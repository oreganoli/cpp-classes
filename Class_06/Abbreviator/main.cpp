#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const auto ASCII_FIRST_LOWERCASE = 'a';
const auto ASCII_LAST_LOWERCASE = 'z';
const auto ASCII_FIRST_UPPERCASE = 'A';
const auto ASCII_LAST_UPPERCASE = 'Z';
const auto ASCII_LETTER_DIFF = 'a' - 'A';

auto is_letter(char c) -> bool {
    return (c >= ASCII_FIRST_UPPERCASE && c <= ASCII_LAST_UPPERCASE) ||
           (c >= ASCII_FIRST_LOWERCASE && c <= ASCII_LAST_LOWERCASE);
}

auto to_upper(char c) -> char {
    if (is_letter(c)) {
        if (c >= ASCII_FIRST_LOWERCASE && c <= ASCII_LAST_LOWERCASE) {
            return c - ASCII_LETTER_DIFF;
        } else {
            return c;
        }
    } else {
        return c;
    }
}

auto abbreviate(const char s[]) {
    int src_len = strlen(s);
    /* We assign a minimum value of 2 here because
     * one space will be needed for the first character of the expression
     * and another for the NUL byte C strings end with. */
    int out_len = 2;
    for (int i = 0; i < src_len; i++) {
        if (s[i] == ' ') {
            out_len++;
        }
    }
    auto out = new char[out_len];
    int out_counter = 0;
    for (int i = 0; i < src_len; i++) {
        if (i == 0 || s[i - 1] == ' ') {
            if (is_letter(s[i])) {
                out[out_counter] = to_upper(s[i]);
                out_counter++;
            }
        }
    }
    out[out_counter] = '\0';
    cout << "The expression \"" << s << "\" can be abbreviated as \"" << out << "\".";
    delete[] out;
}

int main() {
    string input;
    cout << "Enter a string to abbreviate:" << endl << ">";
    getline(cin, input);
    abbreviate(input.c_str());
    return 0;
}
