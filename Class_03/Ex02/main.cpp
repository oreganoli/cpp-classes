#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto digits(unsigned int n, vector<char> &buffer) -> void {
    if (n > 1) {
        digits(n / 2, buffer);
    }
    if (n % 2 == 0) {
        buffer.push_back('0');
    } else {
        buffer.push_back('1');
    }
}

auto smr(int n) -> string {
    string output;
    output.reserve(sizeof(int) * 4 + 2);
    if (n >= 0) {
        output += "0.";
    } else {
        output += "1.";
    }
    int m = abs(n);
    vector<char> buf = *new vector<char>(sizeof(int) * 4);
    digits(m, buf);
    for (char a : buf) {
        if (a == '1' || a == '0') {
            output += a;
        }
    }
    return output;
}

int main() {
    string input;
    int n;
    printf("Enter an integer: \n>");
    getline(cin, input);
    n = stoi(input);
    printf("In the sign-and-magnitude binary notation, the number %d is written: %s\n", n, smr(n).c_str());
    return 0;
}
