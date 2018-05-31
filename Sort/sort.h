#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
void swap(T arr[], int a, int b)
{
    T tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
template <class T>
int divide(T arr[], int low, int high)
{
    if (low >= high)
        return low;
    T key = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= key)
            high--;
        if (low < high)
            arr[low] = arr[high];
        while (low < high && arr[low] <= key)
            low++;
        if (low < high)
            arr[high] = arr[low];
    }
    arr[low] = key;
    return low;
}
template <class T>
void quickSort(T arr[], int low, int high)
{
    int mid;
    if (low >= high)
        return;
    mid = divide(arr, low, high);
    quickSort(arr, low, mid - 1);
    quickSort(arr, mid + 1, high);
}

template <class T>
void insertSort(T arr[], int size)
{
    int i, j;
    int key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

template <class T>
void shellSort(T arr[], int size)
{
    int key, i, j;
    for (int step = size / 2; step > 0; step /= 2)
    {
        for (i = step; i < size; i++)
        {
            key = arr[i];
            for (j = i - step; j >= 0 && arr[j] > key; j -= step)
            {
                arr[j + step] = arr[j];
            }
            arr[j + step] = key;
        }
    }
}

template <class T>
void searchSort(T arr[], int size)
{
    int min;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[i])
                min = j;
        }
        swap(arr, i, min);
    }
}
template <class T>
void percolateDown(T arr[], int hole, int size)
{
    if (hole < 0 || hole >= size)
        return;
    T tmp = arr[hole];
    int child;
    while (hole * 2 + 2 < size)
    {
        child = hole * 2 + 1;
        if (child != size && arr[child + 1] > arr[child])
            child++;

        if (arr[child] > tmp)
        {
            arr[hole] = arr[child];
            hole = child;
        }
        else
            break;
    }
    arr[hole] = tmp;
}

template <class T>
void heapSort(T arr[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        percolateDown(arr, i, size);
    for (i = size - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        percolateDown(arr, 0, i);
    }
}

template<class T>
void bubbleSort(T arr[], int size)
{
    bool flag = true;
    for(int i = size; flag && i > 1; i--) //size of each sort
    {
        flag = false;
        for(int j = 1; j < i; j++) // j = [1, i - 1]
        {
            if(arr[j] < arr[j - 1])
            {
                //cout << "swap(" << j << ", " << j - 1 <<")" << endl;
                swap(arr, j, j - 1);
                flag = true;
            }
        }
    }
}


#endif // SORT_H_INCLUDED
