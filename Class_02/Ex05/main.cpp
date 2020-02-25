#include <iostream>
#include <string>
using namespace std;

auto draw_tree(unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < 1 + 2 * i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    string input;
    cout << "How tall a tree do you want?" << endl;
    getline(cin, input);
    int n = stoi(input);
    if (n < 0) {
        cout << "Negative values are not supported.";
        return EXIT_FAILURE;
    }
    draw_tree(n);
    return 0;
}
