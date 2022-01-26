#ifndef MERGE_H_KNOWN
#define MERGE_H_KNOWN
#include<iostream>

void merge(int *arr,int* l, int *r, int size, int lindex,int rindex);


void mergeSort(int* arr, int length){
    std::cout << "Merge sort" << std::endl;
    if(length <= 1){
        return;
    }
    int lIndex, rIndex;
    if(length % 2 == 1){
        lIndex = length / 2;
        rIndex = (length / 2) - 1;
    }
    else{
        lIndex = length / 2;
        rIndex = length / 2;
    }
    int *l, *r;
    l = new int[lIndex];
    r = new int[rIndex];

    int i = 0;
    for (i; i < lIndex; i++)
        l[i] = arr[i];

    for (int j = 0; j < rIndex; j++){
        r[j] = arr[i];
        i++;
    }
    mergeSort(l, lIndex);
    mergeSort(r, rIndex);

    merge(arr,l, r, length, lIndex, rIndex);
}

void merge(int *arr,int* l, int *r, int size, int lindex,int rindex){
    int *temp = new int[size];
    
    for (int i = 0; i < lindex; i++)
        temp[i] = l[i];
    for (int i = rindex; i < size; i++)
        temp[i] = r[i];

    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

#endif