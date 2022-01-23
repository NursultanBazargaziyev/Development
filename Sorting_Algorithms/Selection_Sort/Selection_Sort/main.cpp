#include<iostream>
#include<chrono>
#include<iomanip>
using namespace std::chrono;
using std::cout;
using std::endl;

//Selection sort Algorithm
//22-01-22

void selectSort(int* a, int length);
void generateArr(int* a, int length);
void printArr(int* a, int length);


int main() {
	
	srand(time(NULL));
	int* ptr = new int[50];
	generateArr(ptr, 50);
	printArr(ptr, 50);
	selectSort(ptr, 50);
	printArr(ptr, 50);
	
	return 0;
}



void selectSort(int* a, int length) {
	for (int i = 0; i < length; i++)
	{
		int smallest = i;
		int j;
		for ( j = i; j < length; j++)
		{
			if (a[smallest] > a[j])
				smallest = j;
		}
		
		std::swap(a[i], a[smallest]);
	}
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

