#ifndef RECURSIVE_INSERTION_H_KNOWN
#define RECURSIVE_INSERTION_H_KNOWN


void RecursiveInsertionSort(int* array, int length, int current = 1){

    if (length == current) 
    {   
        std::cout << "Recursive insertion sort" << std::endl;
        return;
    }


    for (int i = 0; i < current; i++)
        if (array[i] > array[current])
                std::swap(array[current], array[i]);
    

    RecursiveInsertionSort(array, length, current + 1);
}


#endif