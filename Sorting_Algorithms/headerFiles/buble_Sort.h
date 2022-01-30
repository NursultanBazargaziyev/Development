#ifndef BUBLE_SORT_H
#define BUBLE_SORT_H
#include<iostream>

void bubleSort(int* array, int length) {

    std::cout << "BubleSort" << std::endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
            if (array[j] > array[j + 1]) 
                std::swap(array[j], array[j + 1]); 
    }
}


#endif 