#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const auto ASCII_DIGIT_BEGIN = '0';
const auto ASCII_DIGIT_END = '9';

auto sum(char s[]) -> int {
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= ASCII_DIGIT_BEGIN && s[i] <= ASCII_DIGIT_END) {
            sum += s[i] - ASCII_DIGIT_BEGIN;
        }
    }
    return sum;
}

int main() {
    string input;
    cout << "Enter a string to sum the digits in:" << endl << ">";
    getline(cin, input);
    auto string = (char*)input.c_str();
    cout << "The sum of all digits in your string is " << sum(string) << endl;
    return 0;
}
