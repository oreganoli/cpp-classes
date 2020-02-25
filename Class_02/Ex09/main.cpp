#include <iostream>

using namespace std;

const char ERROR_MESSAGE[] = "Only numbers 1 through 5 are supported by this program.";

auto draw_cap(int n) {
    if (n < 1 || n > 5) {
        throw invalid_argument(ERROR_MESSAGE);
    }
    cout << "+";
    for (int i = 0; i < n * 8; i++) {
        cout << "-";
    }
    cout << "+";
    cout << endl;
}

auto draw_odd_row(int n) {
    if (n < 1 || n > 5) {
        throw invalid_argument(ERROR_MESSAGE);
    }
    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < n; k++) {
                cout << " ";
            }
            for (int l = 0; l < n; l++) {
                cout << "#";
            }
        }
        cout << "|" << endl;
    }
}

auto draw_even_row(int n) {
    if (n < 1 || n > 5) {
        throw invalid_argument(ERROR_MESSAGE);
    }
    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < n; l++) {
                cout << "#";
            }
            for (int k = 0; k < n; k++) {
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
}

auto draw_board(int n) {
    draw_cap(n);
    for (int i = 0; i < 4; i++) {
        draw_odd_row(n);
        draw_even_row(n);
    }
    draw_cap(n);
}

int main() {
    string input;
    int n;
    cout
            << "What size of square do you want the checkerboard pattern to be drawn with? Acceptable values are 1 through 5."
            << endl;
    getline(cin, input);
    try {
        n = stoi(input);
        draw_board(n);
    } catch (exception &ex) {
        cout << ex.what() << endl;
        return EXIT_FAILURE;
    }
    return 0;
}
