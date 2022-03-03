#ifndef GENERATE_ARRAY_H
#define GENERATE_ARRAY_H

int randomNumber();



void generateArray(std::vector<int>& arr)
{
    std::generate(arr.begin(), arr.end(), randomNumber);

}


int randomNumber() {
    std::random_device random;
    std::mt19937 generate(random());
    std::uniform_int_distribution<int> width(0, 100);
    return width(generate);
}



#endif
