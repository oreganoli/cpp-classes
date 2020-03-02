#include <iostream>
#include <string>
using namespace std;

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

int main() {
    string full;
    string substring;
    cout << "Enter a string to search:" << endl << ">";
    getline(cin, full);
    cout << "Enter a substring to search for:" << endl << ">";
    getline(cin, substring);
    auto x = str_find(full, substring);
    if (x != -1) {
        cout << "The substring was found at index " << x << " in the original string." << endl;
    } else {
        cout << "The substring \"" << substring << "\" could not be found." << endl;
    }
    return 0;
}
