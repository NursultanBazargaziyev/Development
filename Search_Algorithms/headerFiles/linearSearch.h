#ifndef LINEAR_V_SEARCH
#define LINEAR_V_SEARCH
#include<vector>

template<typename T>
int linearSearch(std::vector<T> arr, T element){

    for (size_t i = 0; i < arr.size(); i++)
        if (arr[i] == element) return i;
        
    return -1;
}

#endif
