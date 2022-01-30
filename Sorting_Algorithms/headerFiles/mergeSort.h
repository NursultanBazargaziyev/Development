#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include<iostream>
void merge(int*,int*,int*,int,int);

void mergeSort(int* array, int start, int length){
    int lIdnex, rIndex;
    if (length <= 1) return;
        
    lIdnex = length % 2 == 1? length / 2 + 1: length / 2;
    rIndex = length / 2;
    int *l = new int[lIdnex];
    int *r = new int[rIndex];
    int i = 0;
    for (i; i < lIdnex; i++)
        l[i] = array[i];
    for (int j = 0; j < rIndex; j++){
        r[j] = array[i];
        i++;
    }

    mergeSort(l, start, lIdnex);
    mergeSort(r, length - lIdnex, rIndex );

    merge(array,l, r, lIdnex, rIndex);

}

void merge(int* array,int* l,int* r, int lIndex, int rIndex){
    int x = 0, y = 0;
    int index = 0;
    while (x < lIndex && y < rIndex)
    {
        if(l[x] < r[y])
        { 
            array[index] = l[x];
            x++;
            index++;
        }
        else{
            array[index] = r[y];
            y++;
            index++;
        }
    }
    while (x != lIndex)
    {
        array[index] = l[x];
        x++;
        index++;
    }
    
    while (y != rIndex)
    {
        array[index] = r[y];
        y++;
        index++;
    }


}


#endif
