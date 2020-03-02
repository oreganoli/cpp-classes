#include <cstring>
#include <iostream>

using namespace std;

/// "Cuts" a string down to a substring.
auto cut_string(const char str[], int from, int n) {
    auto len = strlen(str);
    if (from + n > len) {
        throw invalid_argument("Attempted to read past the end of the source string.");
    }
    auto out = new char[n];
    for (int i = 0; i < n; i++) {
        out[i] = str[from + i];
    }
    return out;
}

int main() {
    const auto ALA = "Ala ma kota";
    auto la = cut_string(ALA, 1, 2);
    auto a_ko = cut_string(ALA, 5, 4);
    cout << la << endl;
    cout << a_ko << endl;
    return 0;
}
