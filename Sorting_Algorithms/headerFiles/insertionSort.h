#ifndef INSERTION_H_SORT
#define INSERTION_H_SORT
#include<iostream>


void insertionSort(int* array, int length) {
    std::cout << "Insertion sort" << std::endl;
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < i; j++)
            if (array[j] > array[i])
                std::swap(array[j], array[i]);
        

    }

}



#endif