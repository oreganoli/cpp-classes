#include <iostream>
#include <string>
#include <cstring>

using namespace std;

auto strpos(const char str[], char z) -> int {
    // this will fail horribly if the string is not null terminated
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '\0') {
            return -1;
        } else if (str[i] == z) {
            return i;
        }
    }
}

int main() {
    string input;
    string search;
    cout << "Enter a string to search:" << endl << ">";
    getline(cin, input);
    cout << "Enter a character to search for (extra characters will be ignored):" << endl << ">";
    getline(cin, search);
    int x = strpos(input.c_str(), search[0]);
    if (x != -1) {
        cout << "The character sought can be found at position " << x << "." << endl;
    } else {
        cout << "The character could not be found." << endl;
    }
    return 0;
}
