#include <cmath>
#include <iostream>
#include <tuple>

using namespace std;

auto interleave(const int a[], const int b[], int a_size, int b_size, int out[], int out_size) {
    if (out_size < a_size + b_size) {
        throw invalid_argument("The output array must be at least as large as both the input arrays together.");
    }
    auto arrays = a_size > b_size ? pair(b, a) : pair(a, b);
    int greater = max(a_size, b_size);
    int lesser = min(a_size, b_size);
    int i = 0;
    int x = 0;
    for (; x < lesser; x++) {
        out[i] = a[x];
        i++;
        out[i] = b[x];
        i++;
    }
    for (; x < greater; x++) {
        out[i] = arrays.second[x];
        i++;
    }
}

int main() {
    int tab1[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int tab2[] = {10, 11, 12, 13, 14};
    auto tab3 = new int[13];
    interleave(tab1, tab2, 8, 5, tab3, 13);
    for (int i = 0; i < 13; i++) {
        cout << tab3[i] << ", ";
    }
    cout << endl;
    return 0;
}