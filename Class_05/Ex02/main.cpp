#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>

const int ASCII_DIGIT_OFFSET = 0x30;
using namespace std;

auto strint(const char str[]) -> int {
    bool negative = false;
    int sum = 0;
    int e = 0;
    auto digits = *new vector<int>;
    for (int i = 0; i < strlen(str); i++) {
        if (i == 0 && str[i] == '-') {
            negative = !negative;
        } else if (i == 0 && str[i] == '+') {
            continue;
        } else if (isdigit(str[i])) {
            digits.push_back(str[i] - ASCII_DIGIT_OFFSET);
        } else if (str[i] == 'e' && strlen(str) - i > 0) {
            e = strint(&str[i + 1]);
            if (e < 0) {
                e = 0; // we don't handle fractions
            }
            //cout << "e is " << e << endl;
            break;
        } else {
            break;
        }
    }
    for (int i = 0; i < digits.size(); i++) {
        sum += digits[i] * pow(10, digits.size() - i - 1);
    }
    sum *= pow(10, e);
    if (!negative) {
        return sum;
    } else {
        return -sum;
    }
}

int main() {
    string input;
    cout << "Enter an integer:" << endl << ">";
    getline(cin, input);
    cout << "Your number was parsed as " << strint(input.c_str()) << "." << endl;
    return 0;
}
