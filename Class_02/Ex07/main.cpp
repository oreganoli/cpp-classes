#include <iostream>
#include <vector>
#include <string>

using namespace std;

auto digits(int x) -> vector<int> * {
    auto digits = new vector<int>;
    int copy = abs(x);
    while (copy >= 10) {
        digits->push_back(copy % 10);
        copy /= 10;
    }
    digits->push_back(copy % 10);
    reverse(digits->begin(), digits->end());
    return digits;
}

auto is_palindrome(int x) -> bool {
    auto digs = digits(x);
    for (int i = 0; i < digs->size() / 2; i++) {
        if (digs->at(i) != digs->at(digs->size() - i - 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a non-negative integer:" << endl << ">";
    getline(cin, input);
    try {
        auto num = stoi(input);
        if (num < 0) {
            cout << "The integer must be greater than or equal to 0." << endl;
            return EXIT_FAILURE;
        }
        if (is_palindrome(num)) {
            cout << "The given number is a palindrome." << endl;
        } else {
            cout << "The given number is not a palindrome." << endl;
        }
    } catch (exception &ex) {
        cout << "ERROR" << endl;
        cout << ex.what() << endl;
        return EXIT_FAILURE;
    }
    return 0;
}
