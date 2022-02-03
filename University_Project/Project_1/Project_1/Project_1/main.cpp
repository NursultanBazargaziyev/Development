//Bazargaziyev Nursulan
//29-11-2021
#include<iostream>
#include<chrono>
#include<vector>
#include<random>
#include<fstream>
#include<string>
#include<sstream>
#include"generateArr.h"
#include"heapsort.h"
#include"mergesort.h"
#include"quicksort.h"
using namespace std;
int counter;
// chose best case from the array
template<typename T, typename au>
void bestCase(vector<T>& other, int i, au timeM);
// chose worst case from the array
template<typename T, typename au>
void worstCase(vector<T>& other, int i, au timeM);
// counting avg of every size
template<typename T, typename au>
void avgCount(vector<T>& other, int i, au timeM);

int main() {
	
	vector<int> a; // my main vector var
	string filename; 
	string for_console = "Size\tMergesort\tHeapsort\tQuiksort\tMergesort_Sorted\tHeapSort\tQuickSort_Sorted\n";
	stringstream ss;
	ofstream fileout;
	vector<long long> bestH, bestM, bestQ, worstH, worstM, worstQ;
	vector<unsigned long long int> avgM, avgH, avgQ;
	int size = 10, times = 0;


	// The avgM, avgH, avgQ vectors doesn't make sence if there is only 1 iteration, so if you want to see worst case, best case and avg of 
	// time comiling, you should change 1 to 100
	for (int i = 0; i < 100; i++)
	{	
		times++;
		filename = "";
		ss.str("");
		ss << "result" << i + 1 << ".csv";
		//ss << "result" << i + 1 << ".txt";
		filename = ss.str();
		counter = 1;
		fileout.open(filename);
		cout << for_console;
		//for usual result
		//fileout << for_console;
		// 
		//for csv file
		fileout << "Size" << ";" << "MergeSort" << ";" << "HeapSort" << ";" << "QuickSort;" << "MergeSorted" << ";" << "HeapSorted" << ";" << "QuickSorted" << endl;
		for (int i = 0; i < 100; i++)
		{

			generateArray(a, counter,size);
			//copy(a.begin(), a.end(), ostream_iterator<int>(cout," "));
			auto timeM = measuerMerge(a);
			auto timeQ = measureQuickSort(a);
			auto timeH = measureHeapsort(a);
			avgCount(avgM, i, timeM);
			avgCount(avgH, i, timeH);
			avgCount(avgQ, i, timeQ);
			bestCase(bestH, i, timeH);
			bestCase(bestM, i, timeM);
			bestCase(bestQ, i, timeQ);
			worstCase(worstH, i, timeH);
			worstCase(worstM, i, timeM);
			worstCase(worstQ, i, timeQ);
			auto timeMS = measuerMerge(a);
			auto timeQS = measureQuickSort(a);
			auto timeHS = measureHeapsort(a);

			cout << (i + 1) * size << "   \t" << timeM << "    \t" << timeH << "    \t" << timeQ << "      \t" << timeMS << "              \t" << timeHS << "        \t" << timeQS << endl;
			
			// for txt file
			//fileout << (i + 1) * size << "   \t" << timeM << "    \t" << timeH << "    \t" << timeQ << "      \t" << timeMS << "              \t" << timeHS << "        \t" << timeQS << endl;

			// for csv file
			fileout << (i + 1) * size << ";" << timeM << ";" << timeH << ";" << timeQ << ";" << timeMS << ";" << timeHS << ";" << timeQS << endl;
		}
		fileout.close();
	}

	string content = "Size\tBest\t\tWorst\t\tAverage\n";



	fileout.open("QuickSort_Best_Avg_Worst.txt");
	fileout << content;
	for (int i = 0; i < bestQ.size(); i++)
	{
		
		fileout << (i + 1) * size << "\t" << bestQ[i] << "   \t" << worstQ[i]<<"   \t"<< avgQ[i]/ times << endl;
	}
	fileout.close(); 


	fileout.open("MergeSort_Best_Avg_Worst.txt");
	fileout << content;
	for (int i = 0; i < bestM.size(); i++)
	{
		fileout << (i + 1) * size << "\t" << bestM[i] << "   \t"<<worstM[i] << "   \t" << avgM[i]/ times << endl;
	}
	fileout.close();


	fileout.open("HeapSort_Best_Avg_Worst.txt");
	fileout << content;
	for (int i = 0; i < bestH.size(); i++)
	{
		fileout << (i + 1) * size << "\t" << bestH[i] << "   \t" << worstH[i] << "   \t" << avgH[i] / times << endl;
	}
	fileout.close();


	return 0;
}













template<typename T, typename au>
void bestCase(vector<T>& other,int i, au timeM) {
	if (other.size() <= i) 
		other.push_back(timeM);
	else
	{
		if (other[i] > timeM)
			other[i] = timeM;
	}
}

template<typename T, typename au>
void worstCase(vector<T>& other, int i, au timeM) {
	if (other.size() <= i)
		other.push_back(timeM);
	else
	{
		if (other[i] < timeM)
			other[i] = timeM;
	}
}

template<typename T, typename au>
void avgCount(vector<T> &other, int i,au timeM) {

	if (other.size() <= i)
		other.push_back(timeM);
	else {
		other[i] += timeM;
	}
}

