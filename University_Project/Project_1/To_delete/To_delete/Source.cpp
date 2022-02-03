#include <iostream>
#include<iomanip>

using namespace std;




void insertionSort(int* array, int length) {
    std::cout << "Insertion sort" << std::endl;
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < i; j++)
            if (array[j] > array[i])
                std::swap(array[j], array[i]);
        

    }

}


void bubleSort(int* array, int length) {

    std::cout << "BubleSort" << std::endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
            if (array[j] > array[j + 1]) 
                std::swap(array[j], array[j + 1]); 
    }
}

void printArr(int* a, int length)
{
    for (int i = 0; i < length; i++) {
        cout << std::left << std::setw(2) << i + 1 << ": " << std::left << std::setw(10) << a[i];
        if ((i + 1) % 4 == 0)
            cout << endl;
    }
    cout << "\n\n\n";
}


void generateArr(int* a, int length)
{
    for (int i = 0; i < length; i++)
        a[i] = rand() % 500;
}

void (*measureTIme)(int*, int);


int main()
{
	
    srand(time(NULL));
    int* ptr = new int[50];
    generateArr(ptr, 50);
    printArr(ptr, 50);
    measureTIme = insertionSort;
    measureTIme(ptr, 50);
    printArr(ptr, 50);


    return 0;
}






