#ifndef GENERATE_ARRAY_H
#define GENERATE_ARRAY_H

std::vector<int>& generateArray(std::vector<int>& other, int& counter, int size)
{
	if (!other.empty())
		other.clear();
	std::random_device random;
	std::mt19937 generate(random());
	std::uniform_int_distribution<int> width(0, 10000);
	for (int i = 0; i < counter * size; i++)
		other.push_back(width(generate));
	counter++;
	return other;
}


#endif // !GENERATE_ARRAY_H
