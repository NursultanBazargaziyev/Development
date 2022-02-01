#ifndef QUICK_H_SORT
#define QUICK_H_SORT
#include<iostream>

void quickSort(int*,int,int);


void quickSort(int* arr, int start, int size){
    
    if (start < size){
        int pivot =  start + (size - start) / 2;
        int pivotV = arr[pivot];
        int l = start;
        int r = size ;    
        while (l <= r)
        {
            while (arr[l] < pivotV)
                l++;
            while (arr[r] > pivotV)
                r--;
            if (l <= r)
            {
                std::swap(arr[l], arr[r]);
                l++;
                r--;
            }
            
        }
        quickSort(arr, start, l - 1);
        quickSort(arr, l, size);
    }
}



#endif