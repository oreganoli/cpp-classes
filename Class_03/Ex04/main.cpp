#include <iostream>
#include <cstring>

using namespace std;
#ifndef __linux__
const auto EOF_KEYS = "CTRL+Z";
#else
const auto EOF_KEYS = "CTRL+D";
#endif // who uses Macs anyway?
const auto ASCII_VOWELS = "AEIOUYaeiouy";

int main() {
    string input;
    string digit;
    int current;
    int whitespace = 0;
    int letters = 0;
    int vowels = 0;
    bool digits_found = false;
    int digit_sum = 0;
    input.reserve(1024);
    printf("Enter some text. To finish, press %s.\n", EOF_KEYS);
    while (true) {
        current = getchar();
        if (current == EOF) {
            break;
        }
        input += (char)current;
        if (isspace(current)) {
            whitespace++;
        }
        if (isalpha(current)) {
            letters++;
            for (int i = 0; i < strlen(ASCII_VOWELS); i++) {
                if (ASCII_VOWELS[i] == current) {
                    vowels++;
                }
            }
        }
        if (isdigit(current)) {
            digits_found = true;
            digit = (char)current;
            digit_sum += stoi(digit);
        }
    }
    printf("\n");
    if (input.empty()) {
        printf("No input given.\n");
    }
    if (whitespace > 0) {
        printf("Whitespace characters: %d\n", whitespace);
    }
    if (letters > 0) {
        printf("Letters: %d\n", letters);
        if (vowels > 0) {
            printf("- of which English vowels: %d\n", vowels);
        }
    }
    if (digits_found) {
        printf("Sum of all digits in the text: %d\n", digit_sum);
    }
    return 0;
}
