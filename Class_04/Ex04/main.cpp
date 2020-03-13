#include <cmath>
#include <iostream>
#include <string>
using namespace std;
const auto BLANK_CHAR = ' ';
const auto PAINT_CHAR = '#';

auto side_length(int n) -> int {
    return pow(3, n - 1);
}

auto sierp_carpet(int n) -> char** {
    if (n < 1) {
        throw invalid_argument("Sierpiński carpets can only be constructed for n >= 1.");
    }
    auto len = side_length(n);
    auto **array = new char * [len];
    for (int i = 0; i < len; i++) {
        array[i] = new char [len];
    }
    if (n == 1) {
        array[0][0] = PAINT_CHAR;
        return array;
    }
    auto smaller_len = side_length(n - 1);
    auto smaller = sierp_carpet(n - 1);
    for (int y = 0; y < smaller_len * 3; y+= smaller_len) {
        for (int x = 0; x < smaller_len * 3; x += smaller_len) {
            for (int j = 0; j < smaller_len; j++) {
                for (int i = 0; i < smaller_len; i++) {
                    if (x == y && x == smaller_len) {
                        array[y+j][x+i] = BLANK_CHAR;
                    } else {
                        array[y+j][x+i] = smaller[j][i];
                    }
                }
            }
        }
    }
    return array;
}
auto print_square(char** picture, int n) {
    int size = side_length(n);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << picture[i][j];
        }
        cout << endl;
    }
}

int main() {
    string input;
    int n = 0;
    do {
        input.clear();
        cout << "Enter a positive integer:" << endl << ">";
        getline(cin, input);
        try {
            n = stoi(input);
        } catch (exception &_) {
            continue;
        }
    } while (n <= 0);
    auto pic = sierp_carpet(n);
    print_square(pic, n);
    return 0;
}
