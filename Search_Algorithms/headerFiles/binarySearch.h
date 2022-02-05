#ifndef BINARY_H_SEARCH
#define BINARY_H_SEARCH

template<typename T>
int binarySearch(const std::vector<T> &arr, T element, int start) {
    int middle = start + arr.size() / 2;
    if (start > arr.size())
        return -1;
    
    for (int i = middle; i > 0 ; i--)
    {
        if (element == arr[i])
            return i;        
    }
    binarySearch(arr, element, middle + 1);

}

#endif

