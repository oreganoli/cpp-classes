#include <iostream>
#include <string>
using namespace std;

auto non_palindromic_chars(string s) -> int {
    int unequals = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            unequals++;
        }
    }
    return unequals;
}
int main() {
    string input;
    do {
        input.clear();
        printf("Enter up to 40 characters of text:\n>");
        getline(cin, input);
    } while (input.size() > 40);
    int how_many = non_palindromic_chars(input);
    if (how_many == 0) {
        printf("The string given is a palindrome.\n");
    } else {
        printf("For the string \"%s\" to become a palindrome, %d of its characters would have to be changed.\n", input.c_str(), how_many);
    }
    return 0;
}
