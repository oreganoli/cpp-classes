#include <cstring>
#include <iostream>
using namespace std;

auto is_prefix(char str[], char sub[]) -> bool {
    auto len = strlen(str);
    auto sub_len = strlen(sub);
    if (sub_len > len) {
        return false;
    }
    for (int i = 0; i < sub_len; i++) {
        if (str[i] != sub[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << (is_prefix("Hello, World!", "Hello, ") ? "true" : "false") << endl; // true
    cout << (is_prefix("Hello, World!", "ell") ? "true" : "false") << endl; // false
    return 0;
}
