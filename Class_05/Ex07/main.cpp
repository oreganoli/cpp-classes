#include <cmath>
#include <cstring>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;

const int ASCII_DIGIT_OFFSET = 0x30;

// from c5e2
auto strint(const char str[]) -> optional<int> {
    bool negative = false;
    bool isNumber = false;
    int sum = 0;
    optional<int> e = {};
    auto digits = *new vector<int>;
    for (int i = 0; i < strlen(str); i++) {
        if (i == 0 && str[i] == '-') {
            negative = !negative;
        } else if (i == 0 && str[i] == '+') {
            continue;
        } else if (isdigit(str[i])) {
            isNumber = true;
            digits.push_back(str[i] - ASCII_DIGIT_OFFSET);
        } else if (str[i] == 'e' && strlen(str) - i > 0) {
            e = strint(&str[i + 1]);
            if (!e) {
                break;
            }
            if (e.value() < 0) {
                e = 0; // we don't handle fractions
            }
            break;
        } else {
            break;
        }
    }
    for (int i = 0; i < digits.size(); i++) {
        sum += digits[i] * pow(10, digits.size() - i - 1);
    }
    sum *= pow(10, e.value_or(0));
    if (negative) {
        sum *= -1;
    }
    if (isNumber) {
        return sum;
    } else {
        return {};
    }
}

// from c5e6
auto count_occur(const char *str, const char *sub) -> int {
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
    vector<string> inputs;
    optional<int> sum = {};
    string concat;
    string phrase;
    int phrase_in_all = 0;
    int phrase_in_concat = 0;
    optional<double> ratio = {};

    cout << "Enter a sequence of strings. To finish, enter an empty string:" << endl;
    string input;
    input.reserve(1024); // so as not to reallocate on every new line
    while (true) {
        cout << ">";
        getline(cin, input);
        if (input.empty()) {
            break;
        } else {
            inputs.push_back(input);
            input.clear();
        }
    }
    cout << "Enter a phrase to look for in your strings:" << endl << ">";
    getline(cin, phrase);

    for (string &s : inputs) {
        auto number = strint(s.c_str());
        if (number) {
            sum = sum.value_or(0) + number.value();
        } else {
            concat += s;
            phrase_in_all += count_occur(s.c_str(), phrase.c_str());
        }
    }
    phrase_in_concat += count_occur(concat.c_str(), phrase.c_str());
    if (phrase_in_concat > 0) {
        ratio = (double) phrase_in_all / (double) phrase_in_concat;
    }
    if (sum) {
        cout << "ad 1: The sum of all numbers in your strings is " << sum.value() << "." << endl;
    } else {
        cout << "ad 1: No numbers were found in your strings." << endl;
    }
    cout << "ad 2: \"" << concat << "\"" << endl;
    if (phrase_in_all > 0) {
        cout << "ad 3: The phrase \"" << phrase << "\" " << "appears in all your strings " << phrase_in_all << " times."
             << endl;
    } else {
        cout << "ad 3: The phrase \"" << phrase << "\" " << "does not appear in any of your individual strings."
             << endl;
    }
    if (phrase_in_concat > 0) {
        cout << "ad 4: The phrase \"" << phrase << "\" " << "appears in the concatenated string " << phrase_in_concat
             << " times."
             << endl;
    } else {
        cout << "ad 4: The phrase \"" << phrase << "\" " << "does not appear in the concatenated string." << endl;
    }
    if (ratio) {
        printf("ad 5: The ratio of phrase occurrences in individual strings to occurrences in the concatenated string is %.2f%%.",
               ratio.value() * 100);
        cout << endl;
    } else {
        cout
                << "ad 5: Could not calculate the ratio of phrase occurrences in individual strings to the same in the concatenated string."
                << endl;
    }
    return 0;
}