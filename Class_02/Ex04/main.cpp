#include <iostream>
#include <string>
using namespace std;

auto display_rect(char fill, unsigned int x, unsigned int y, unsigned int a, unsigned int b) {
    if (x == 0 || y == 0 || a == 0 || b == 0) {
        throw invalid_argument("The coordinates and dimensions of the rectangle to be drawn must be positive.");
    }
    for (int i = 1; i < y; i++) {
        cout << endl;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 1; j < x; j++) {
            cout << " ";
        }
        for (int j = 0; j < b; j++) {
            cout << fill;
        }
        cout << endl;
    }
}
auto get_int(const string& question) -> int {
    string input;
    cout << question << endl << ">";
    getline(cin, input);
    return stoi(input);
}

int main() {
    string input;
    char fill;
    cout << "What character do you want the rectangle to be drawn with?";
    getline(cin, input);
    if (input.empty()) {
        cout << "Character not given, exiting." << endl;
        return EXIT_FAILURE;
    }
    fill = input[0];
    int a = get_int("How wide?");
    int b = get_int("How tall?");
    int x = get_int("X offset?");
    int y = get_int("Y offset?");
    display_rect(fill, x, y, a, b);
    return 0;
}
