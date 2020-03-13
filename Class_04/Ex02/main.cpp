#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

auto analysis(const int tab[], int size, float & median, float & mean) -> int {
    if (size < 1) {
        throw invalid_argument("Can't analyze an empty or negative-sized array");
    }
    if (size == 1) {
        median = mean = tab[0];
        return tab[0];
    }
    // Here we create a vector to hold the sorted numbers to keep our function as pure as possible.
    // We do not know the size at compile time, so we can't use an std::array.
    // Dumb C arrays and sorting algorithm wheel-reinvention are right out.
    vector<int> vec = vector<int>(size);
    for (int i = 0; i < size; i++) {
        vec[i] = tab[i];
    }
    sort(vec.begin(), vec.end());
    int middle = size / 2;
    if (size % 2 == 0) {
        median = (float)(vec[middle - 1] + vec[middle]) / 2.0f;
    } else {
        median = (vec[middle]);
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }
    mean = (float)sum / (float)size;
    return sum;
}

int main() {
    string input;
    float med;
    float avg;
    int sum;
    int arrSize;
    do {
        cout << "Enter the size of the array you want to analyze (must be a positive integer):" << endl << ">";
        getline(cin, input);
        arrSize = stoi(input);
        input.clear();
    } while (arrSize <= 0);
    vector<int> array = vector<int>();
    array.reserve(arrSize);
    for (int i = 0; i < arrSize; i++) {
        cout << "Enter an integer to insert into the array:" << endl << ">";
        getline(cin, input);
        int num = stoi(input);
        array.push_back(num);
        cout << "Set array[" << i << "] to " << array[i] << endl;
        input.clear();
    }
    sum = analysis(array.data(), arrSize, med, avg);
    cout << "The sum of all elements is " << sum << ", the mean is " << avg << " and the median is " << med << "." << endl;
    return 0;
}
