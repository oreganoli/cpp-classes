#include <iostream>
#include <cctype>
#include <string>

using namespace std;
const int UPPERCASE_BEGIN = 0x41;
const int UPPERCASE_END = 0x5A;
const int LOWERCASE_BEGIN = 0x61;
const int LOWERCASE_END = 0x7A;
const int ASCII_ALPHABET_LEN = 26;

class Caesar {
private:
    static auto caesar_shift(string *text, int shift) -> string {
        string encrypted = *text;
        int n_shift = shift % ASCII_ALPHABET_LEN;
        for (int i = 0; i < text->size(); i++) {
            int ch = text->at(i);
            if (ch >= LOWERCASE_BEGIN && ch <= LOWERCASE_END) {
                int position = abs((ch - LOWERCASE_BEGIN + n_shift) % ASCII_ALPHABET_LEN);
                encrypted[i] = LOWERCASE_BEGIN + position;
            } else if (ch >= UPPERCASE_BEGIN && ch <= UPPERCASE_END) {
                int position = abs((ch - UPPERCASE_BEGIN + n_shift) % ASCII_ALPHABET_LEN);
                encrypted[i] = UPPERCASE_BEGIN + position;
            }
        }
        return encrypted;
    }

public:
    static auto encrypt(string *text, unsigned int shift) -> string {
        return caesar_shift(text, (int) shift);
    }

    static auto decrypt(string *text, unsigned int shift) -> string {
        auto sh = (signed int) shift % ASCII_ALPHABET_LEN;
        return caesar_shift(text, ASCII_ALPHABET_LEN - sh);
    }
};

int main() {
    string input;
    string shift_input;
    unsigned int shift;
    printf("Enter a sentence to encode:\n>");
    getline(cin, input);
    printf("Enter a positive integer the text will be shifted by:\n>");
    getline(cin, shift_input);
    shift = stoi(shift_input);
    string encrypted = Caesar::encrypt(&input, shift);
    printf("Encrypted with n = %d:\n\"%s\"\n", shift, encrypted.c_str());
    string decrypted = Caesar::decrypt(&encrypted, shift);
    printf("Decrypted back:\n\"%s\"\n", decrypted.c_str());
    return 0;
}
