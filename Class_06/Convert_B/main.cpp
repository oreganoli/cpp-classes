#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const auto ASCII_DIGIT_OFFSET = '0';
const auto AUTHOR_INITIALS = "JPL";

auto convert(char a[]) {
    int str_len = strlen(a);
    char first = a[0];
    char last = a[str_len - 1];
    bool put_first = true;
    int in_len = strlen(AUTHOR_INITIALS);
    int conversions = 0;
    for (int i = 0; i < str_len; i++) {
        if (isdigit(a[i])) {
            if ((a[i] - ASCII_DIGIT_OFFSET) % 2 == 0) {
                if (put_first) {
                    a[i] = first;
                } else {
                    a[i] = last;
                }
                put_first = !put_first;
                conversions++;
            } else {
                a[i] = '*';
                conversions++;
            }
        }
        for (int j = 0; j < in_len; j++) {
            if (a[i] == AUTHOR_INITIALS[j] || a[i] == tolower(AUTHOR_INITIALS[j])) {
                a[i] = '.';
                conversions++;
            }
        }
    }
    cout << a << endl;
    cout << "Converted characters: " << conversions << endl;
}

int main() {
    char string[] = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
    convert(string);
    return 0;
}
