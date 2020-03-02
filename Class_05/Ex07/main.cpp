#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int ASCII_DIGIT_OFFSET = 0x30;
// from c5e2
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
// from c5e6
auto count_occur(char str[], char sub[]) -> int {
    int result = 0;
    int len = strlen(str);
    int sub_len = strlen(sub);
    for (int i = 0; i < len; i++) {
        if (i + sub_len > len) {
            break;
        }
        for (int j = 0; j < sub_len; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
            if (j == sub_len - 1) {
                result += 1;
                i += j;
            }
        }
    }
    return result;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
