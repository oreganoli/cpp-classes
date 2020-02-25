#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

auto digits(int x) -> vector<int>* {
    auto digits = new vector<int>;
    int copy = abs(x);
    while (copy >= 10) {
        digits->push_back(copy % 10);
        copy /= 10;
    }
    digits -> push_back(copy % 10);
    reverse(digits->begin(), digits->end());
    return digits;
}

int main() {
    int x;
    string input;
    cout << "Enter an integer:" << endl << ">";
    getline(cin, input);
    x = stoi(input);
    return 0;
}
