#include<iostream>
#include<iomanip>
#include<chrono>
#include<string>
#include"headerFiles/select_sort.h"
#include"headerFiles/buble_Sort.h"
#include"headerFiles/recursive_Buble_Sort.h"
#include"headerFiles/insertionSort.h"
#include"headerFiles/recursiveInsertionSort.h"
#include"headerFiles/mergeSort.h"
#include"headerFiles/quickSort.h"
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

void generateArr(int* a, int length);
void printArr(int* a, int length);
void (*measureTIme)(int*, int);







int main() {
	srand(time(NULL));
	int size = 7;
	int * ptr = new int[size];	
	generateArr(ptr, size);
	printArr(ptr, size);
	// measureTIme = bubleSort;
 	quickSort(ptr, 0, size - 1);
	// measureTIme(ptr, size);
	printArr(ptr, size);

	
	return 0;
}


// mergeSort(ptr, 0, size);
// RecursiveInsertionSort(ptr, size);







void generateArr(int* a, int length)
{
	for (int i = 0; i < length; i++)
		a[i] = rand() % 500;
}



void printArr(int* a, int length)
{
	for (int i = 0; i < length; i++) {
		cout << std::left << std::setw(2) << i + 1  << ": "  << std::left << std::setw(10) << a[i];
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
	cout << "\n\n\n";
}

