#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template <typename ... Args>
auto polynomial(double x, Args... coefficients) -> double {
    vector<double> vec = {static_cast<double>(coefficients)...};
    double sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i] * pow(x, vec.size() - i - 1);
    }
    return sum;
}

int main() {
    cout << polynomial(3, -1, 2, 5) << endl;
    cout << polynomial(12, 1, 0, 0) << endl;
    return 0;
}
