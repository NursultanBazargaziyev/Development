#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

void countingSort(int *arr, int size, int begin, int last)
{
    int indexSize = last - begin + 1;
    int* copy = new int[size];
    int* range = new int[indexSize];
    for (int i = 0; i < size; i++)
        copy[i] = arr[i];

    for (int i = 0; i < indexSize; i++)
    {
        range[i] = 0;
        for (int j = 0; j < size; j++) 
            if (begin == arr[j]) 
                range[i]++;
        begin++;
    }
    for (int i = 0; i < indexSize - 1; i++)
        range[i+1] = range[i] + range[i + 1];
    
    for (int i = 0; i < size; i++)
    {
        int current = range[arr[i]] - 1; 
        arr[i] = copy[current];
        range[current]--;
    }
    
}

#endif
