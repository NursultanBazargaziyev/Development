#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void mergeSort(std::vector<int>& other);
std::vector<int> merge(std::vector<int> &left, std::vector<int> &right);

long long measuerMerge(std::vector<int> other) {
	auto start = std::chrono::high_resolution_clock::now();
	mergeSort(other);
	auto end = std::chrono::high_resolution_clock::now();
	return (end-start).count();
}


void mergeSort(std::vector<int>& other) {
	if (other.size() <= 1)
		return;
	std::vector<int> left, right;
	int size = other.size() / 2;
	for (int i = 0; i < size; i++)
		left.push_back(other[i]);
	for (int i = size; i < other.size(); i++)
		right.push_back(other[i]);

	mergeSort(left);
	mergeSort(right);
	other = merge(left, right);

}

std::vector<int> merge(std::vector<int> &left, std::vector<int>& right) {
	int x = 0, y = 0;
	std::vector<int> result;
	while (x < left.size() && y < right.size()) {
		if (left[x] < right[y])
		{
			result.push_back(left[x]);
			x++;
		}
		else
		{
			result.push_back(right[y]);
			y++;
		}
	}
	while (x < left.size()) {
		result.push_back(left[x]);
		x++;
	}
	while (y < right.size()) {
		result.push_back(right[y]);
		y++;
	}
	return result;
}



#endif