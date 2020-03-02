#include <iostream>
#include <string>
using namespace std;

// This exercise is the same thing as class 4, exercise 6, except we're required to return 0 on an empty string.
auto str_find(string & full, string & sub) -> int {
    int result = -1;
    if (sub.size() > full.size()) {
        return result;
    }
    for (int i = 0; i < full.size(); i++) {
        if (sub.size() + i > full.size()) {
            return result;
        }
        if (tolower(full[i]) == tolower(sub[0])) {
            result = i;
            for (int j = 0; j < sub.size(); j++) {
                if (tolower(full[i + j]) != tolower(sub[j])) {
                    result = -1;
                }
            }
            if (result != -1) {
                return result;
            }
        }
    }
    return result;
}
// Wrapper function to make the solution for c4e6 work for this exercise.
auto c4e6_wrapper(string & full, string & sub) -> int {
    if (sub.empty()) {
        return 0;
    } else {
        return str_find(full, sub);
    }
}

int main() {
    string input;
    string sub;
    cout << "Enter some text:" << endl << ">";
    getline(cin, input);
    cout << "Enter a substring to search for:" << endl << ">";
    getline(cin, sub);
    int x = c4e6_wrapper(input, sub);
    if (x != 1) {
        cout << "The substring was found at position " << x << "." << endl;
    } else {
        cout << "The substring could not be found." << endl;
    }
    return 0;
}
