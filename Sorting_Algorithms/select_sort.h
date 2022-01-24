#ifndef SELET_SORT_H
#define SELET_SORT_H
#include<iostream>
void selectSort(int* a, int length) {
	std::cout<<"Select sort\n";
	for (int i = 0; i < length; i++)
	{
		int smallest = i;
		int j;
		for ( j = i; j < length; j++)
			if (a[smallest] > a[j])
				smallest = j;
		
		
		
		std::swap(a[i], a[smallest]);
	}
}
#endif