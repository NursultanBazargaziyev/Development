#ifndef HEAPSORT_H
#define HEAPSORT_H
void heapSort(std::vector<int>& a, int n, int j);


long long measureHeapsort(std::vector<int> &other) {
	auto start = std::chrono::high_resolution_clock::now();
	for ( int i = other.size() / 2 - 1; i >=0 ; i--)
	{
		heapSort(other, other.size(), i);
		
	}
	for (int i = other.size() - 1; i > 0; i--)
	{
		std::swap(other[0], other[i]);
		heapSort(other, i , 0);
	}
	auto end = std::chrono::high_resolution_clock::now();
	return (end-start).count();
}




void heapSort(std::vector<int>& a,int n,int j) {
	int root = j;
	int l = j * 2 + 1;
	int r = j * 2 + 2;
	if (l< n && a[l] > a[root])
		root = l;
	if (r < n && a[r] > a[root])
		root = r;
	if (root != j)
	{
		std::swap(a[j], a[root]);
		heapSort(a, n, root);
	}
}


#endif // !HEAPSORT_H









/*std::cout << "\nSorted arr\n" << std::endl;
for (int i = 0; i < temp.size(); i++)
{
	std::cout << temp[i] << " ";
}
std::cout << std::endl;*/
