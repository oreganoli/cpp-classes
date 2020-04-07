#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// lifted from UŚ class 4, exercise 4
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

auto encrypt(string in_filename, int shift) {
    auto in = ifstream();
    in.open(in_filename);
    string buffer;
    in >> buffer;
    in.close();
    buffer = Caesar::encrypt(&buffer, shift);
    auto out = ofstream();
    out.open("_"+in_filename);
    out << buffer;
    out.close();
}
auto decrypt(string in_filename, int shift) {
    auto in = ifstream();
    in.open(in_filename);
    string buffer;
    in >> buffer;
    in.close();
    buffer = Caesar::decrypt(&buffer, shift);
    auto out = ofstream();
    out.open(in_filename);
    out << buffer;
    out.close();
}
int main() {
    string file = "input.txt";
    int shift = 2;
    auto reader = ifstream();
    string buffer;
    reader.open(file);
    reader >> buffer;
    reader.close();
    cout << "Contents of input file:" << endl;
    cout << buffer << endl;
    buffer.clear();
    encrypt(file, shift);
    reader.open("_"+file);
    reader >> buffer;
    reader.close();
    cout << "Contents after encryption:" << endl;
    cout << buffer << endl;
    buffer.clear();
    decrypt("_"+file, 2);
    reader.open("_"+file);
    reader >> buffer;
    reader.close();
    cout << "Decrypted:" << endl;
    cout << buffer << endl;

    return 0;
}
