#include<iostream>
#include<iomanip>
#include<chrono>
#include<string>
#include"headerFiles/selectSort.h"
#include"headerFiles/bubleSort.h"
#include"headerFiles/recursiveBubleSort.h"
#include"headerFiles/insertionSort.h"
#include"headerFiles/recursiveInsertionSort.h"
#include"headerFiles/mergeSort.h"
#include"headerFiles/quickSort.h"
#include"headerFiles/heapSort.h"
#include"headerFiles/countingSort.h"
using namespace std::chrono;
using std::cout;
using std::endl;

//Selection sort Algorithm
//22-01-22

//Buble sort Algorithm 
//24-01-22 

// Insertion sort Algorithm
//25-01-22

// Recursive Insertion sort Algorithm
//25-01-22

// Merge sort Algorithm
// 25-01-22

// Quick sort Algorith
// 30-01-22

// Heap sort Algorithm 
// 01-02-2022


void generateArr(int* a, int length, int range);
void printArr(int* a, int length);
void (*measureTIme)(int*, int);







int main() {
	srand(time(NULL));
	int size = 7;
	int * ptr = new int[size];	
	generateArr(ptr, size, 9);
	printArr(ptr, size);
	// measureTIme = heapSort;
	// measureTIme(ptr, size);
	countingSort(ptr, size, 0, 9);
	printArr(ptr, size);

	
	system("pause");
	return 0;
}


// quickSort(ptr, 0, size - 1);
// mergeSort(ptr, 0, size);
// RecursiveInsertionSort(ptr, size);







void generateArr(int* a, int length, int range)
{
	for (int i = 0; i < length; i++)
		a[i] = rand() % range;
}



void printArr(int* arr, int length)
{
	for (int i = 0; i < length; i++) {
		cout << std::left << std::setw(2) << i + 1  << ": "  << std::left << std::setw(10) << arr[i];
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
	cout << "\n\n\n";
}

