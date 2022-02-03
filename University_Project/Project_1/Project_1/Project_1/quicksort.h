#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void quickSort(std::vector<int>& other, int l, int r);
int partition(std::vector<int>& other, int l, int r);

long long measureQuickSort(std::vector<int> other) {

	auto start = std::chrono::high_resolution_clock::now();
	quickSort(other, 0, other.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	return (end-start).count();


}
void quickSort(std::vector<int>& other, int l, int r)
{
	if (l<r)
	{
		int p = partition(other, l, r);
		quickSort(other, l, p - 1);
		quickSort(other, p, r);
	}
}

int partition(std::vector<int>& other, int l, int r) {
	int pivotI = l + (r - l) / 2;
	int pivotV = other[pivotI];
	int x = l, y = r;
	while (x <= y) {
		while (other[x] < pivotV) {
			x++;
		}
		while (other[y] > pivotV) {
			y--;
		}
		if (x <= y) {
			std::swap(other[x], other[y]);
			x++;
			y--;
		}
	}
	// {9,4654,12,984,12,9 8,444,61,81,659,51}
	return x;
}
#endif // !quickSort




/*std::cout << "<==========>\nQuick sort before: ";
	for (int i = 0; i < other.size(); i++)
	{
		std::cout << " " << other[i];
	}
	std::cout << "\n";*/
/*std::cout << "<==========>\nQuick sort After: ";
	for (int i = 0; i < other.size(); i++)
	{
		std::cout << " " << other[i];
	}
	std::cout << "\n";*/