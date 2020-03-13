#include <cmath>
#include <iostream>
#include <vector>
#include <array>

const auto COEFS = 4;

using namespace std;

// Solution lifted from UŚ class 4 exercise 5.
// As there, we use templates over va_* macros for type-safety.
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
    string input;
    auto coefficients = array<double, COEFS>();
    double x;
    cout << "Enter the coefficients of your polynomial in descending order (up to 4)" << endl;
    for (int i = 0; i < coefficients.size(); i++) {
        input.clear();
        cout << ">";
        getline(cin, input);
        try {
            coefficients[i] = stod(input);
        } catch (exception &_) {
            i--;
        }
    }
    cout << "Enter your X:" << endl;
    while (true) {
        input.clear();
        cout << ">";
        getline(cin, input);
        if (input.empty()) {
            continue;
        }
        try {
            x = stod(input);
            break;
        } catch (exception &_) {
            continue;
        }
    }
    cout << "f(" << x << ") = " << polynomial(x, coefficients[0], coefficients[1], coefficients[2], coefficients[3]);
    return 0;
}
