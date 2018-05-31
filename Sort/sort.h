#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
template <class T>
void swap(T arr[], int a, int b)
{
    T tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
template <class T>
void quickSort(T arr[], int left, int right)
{
    int tmp = (left + right) / 2;
    if(arr[left] < arr[tmp] && arr[left] < arr[right])
        swap(arr, left, tmp);
    
}


#endif // SORT_H_INCLUDED
