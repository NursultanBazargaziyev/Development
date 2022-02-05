#include<iostream>
#include<vector>
#include<iomanip>
#include"headerFiles/binarySearch.h"
#include"linearSearch.h"
using std::endl;
using std::cout;
using std::vector;

void generateArr(vector<int>&, int);
void printArr(vector<int>&);


int main()
{
    srand(time(NULL));
    vector<int> binary;
    int size = 10;
    generateArr(binary, size);
    printArr(binary);
    cout << binarySearch(binary, 1, 0) <<endl;
    

    return 0;
}

void generateArr(vector<int> &arr, int size){
    for (int i = 0; i < size; i++)
        arr.push_back(rand() % 10);
} 

void printArr(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        cout<< std::left <<std::setw(2) << i + 1 << ": "<< std::left << std::setw(5) << arr[i];
        if ((i + 1) % 4 == 0)
            cout<<"\n";
        
    }
    cout<<"\n\n";
    
}