#include<iostream>
#include<iomanip>
#include<chrono>
#include"select_sort.h"
#include"buble_Sort.h"
#include"recursive_Buble_Sort.h"
#include"insertionSort.h"
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

void generateArr(int* a, int length);
void printArr(int* a, int length);
void (*measureTIme)(int*, int);




int main() {
	srand(time(NULL));
	int* ptr = new int[50];
	generateArr(ptr, 50);
	printArr(ptr, 50);
	measureTIme = insertionSort;
    measureTIme(ptr, 50);
	printArr(ptr, 50);

	
	return 0;
}











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

