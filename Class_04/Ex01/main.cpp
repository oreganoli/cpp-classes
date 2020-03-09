#include <iostream>
using namespace std;
auto min(const double tab[], int size) -> double {
    double smallest = tab[0];
    for(int i = 0; i < size; i++) {
        if (tab[i] < smallest) {
            smallest = tab[i];
        }
    }
    return smallest;
}
auto max_by_ref(const double tab[], int size, double & result) {
    double biggest = tab[0];
    for (int i = 0; i < size; i++) {
        if (tab[i] > biggest) {
            biggest = tab[i];
        }
    }
    result = biggest;
}

int main() {
    double array[] = {3.14, 12, 984, 23, -3, -67.8, 746.555};
    double max;
    cout << "The smallest element of the array is " << min(array, 7) << endl;
    max_by_ref(array, 7, max);
    cout << "The biggest element of the array is " << max << endl;
    return 0;
}
