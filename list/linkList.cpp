#ifndef LINKLIST_CPP_INCLUDED
#define LINKLIST_CPP_INCLUDED
#include <iostream>
#include "linkList.h"
using namespace std;

template <class elemType>
linkList<elemType>::linkList(const linkList<elemType> &l1)
{
	node *p = head, *q = l1.head->next, *tmp;
	while (q)
	{
		tmp = new node();
		p->next = tmp;
		tmp->data = q->data;
		tmp->next = NULL;
		p = tmp;
		q = q->next;
	}
}

template <class elemType>
int linkList<elemType>::length() const
{
	int len = 0;
	node *p = head->next;
	while (p)
	{
		len ++;
		p = p->next;
	}
	return len;
}

template <class elemType>
int linkList<elemType>::search(const elemType &x) const
{
	node *p = head->next;
	int num = 1;
	while (p && p->data != x)
	{
		num ++;
		p = p->next;
	}
	if (p) return num;
	return -1;
}

template <class elemType>
elemType linkList<elemType>::visit(int i) const
{
	if (i < 0) throw OutOfBound();
	int num = 0;
	node *p = head->next;
	while (p)
	{
		num ++;
		if (p && num == i) break;
		p = p->next;
	}
	if (p) return p->data;
	throw OutOfBound();
}

template <class elemType>
void linkList<elemType>::insert(int i, const elemType &x)
{
	if (i < 0) return;
	node *p = head;
	int num = 0;
	while (p && num < i)
	{
		num ++;
		p = p->next;
	}
	if (p) p->next = new node(x, p->next);
}

template <class elemType>
void linkList<elemType>::remove(int i)
{
	if (i <= 0) return;
	node *tmp, *p = head;
	int num = 0;
	while (p && num < i)
	{
		num ++;
		tmp = p;
		p = p->next;
	}
	if (p)
	{
		tmp->next = p->next;
		delete p;
	}
}

template <class elemType>
void linkList<elemType>::clear()
{
	node *tmp, *p = head->next;
	while (p)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
	head->next = NULL;
}

template <class elemType>
void linkList<elemType>::traverse() const
{
	node *p = head->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
#endif
