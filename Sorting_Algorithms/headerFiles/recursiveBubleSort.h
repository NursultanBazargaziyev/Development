#ifndef RECURSIVE_BUBLE_H
#define RECURSIVE_BUBLE_H
#include<iostream>



void recursiveBubleSort(int* array, int length){
    if(length == 1)
        std::cout<<"Recursive Buble sort"<<std::endl;
    if(length == 1){
        return;
    }

    for (int j = 0; j < length - 1; j++)
            if (array[j] > array[j + 1]) 
                std::swap(array[j], array[j + 1]); 
    
    recursiveBubleSort(array, length-1);

}


#endif