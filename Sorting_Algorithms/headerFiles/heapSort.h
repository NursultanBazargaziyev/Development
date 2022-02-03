#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <iostream>
#include<iomanip>
void heap(int *, int, int);

void heapSort(int *arr, int length)
{
    int lastParent = length / 2 - 1;
    for (int i = lastParent; i >= 0; i--)
        heap(arr, i, length); 
    for (int i = length - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heap(arr, 0,i);
    }
}

void heap(int *arr, int parent, int length)
{
    int lChild = parent * 2 + 1;
    int rChild = parent * 2 + 2;
    int temp = parent;
    if (arr[temp] < arr[lChild] && lChild < length)
        temp = lChild;
    if (arr[temp] < arr[rChild] && rChild < length)
        temp = rChild;
    if (temp != parent)
    {
        std::swap(arr[parent], arr[temp]);
        heap(arr, lChild, length);
        heap(arr, rChild, length);
    }
    
}

// {6,46,7,84,4,8,48, 56, 36}
// l = 2* i + 1
// r = 2 * i + 2;
// last parent = length / 2 - 1;

#endif