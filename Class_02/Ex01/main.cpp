#include <iostream>
#include <string>
using namespace std;
const char ADD = '+';
const char SUB = '-';
const char MUL = '*';
const char DIV = '/';

int main() {
    string input;
    double a;
    double b;
    double c;
    char op;
    cout << "CALCULATOR" << endl;
    cout << "a = ";
    getline(cin, input);
    a = stod(input);
    input.clear();
    cout << "Choose from one of the following operations: +, -, *, /" << endl << ">";
    getline(cin, input);
    op = input.front();
    input.clear();
    cout << "b = ";
    getline(cin, input);
    b = stod(input);
    switch(op) {
        case ADD:
            c = a + b;
            break;
        case SUB:
            c = a - b;
            break;
        case MUL:
            c = a * b;
            break;
        case DIV:
            if (b == 0) {
                cout << "Attempted division by 0, exiting." << endl;
                return EXIT_FAILURE;
            }
            c = a / b;
            break;
        default:
            cout << "Unrecognized operation, exiting." << endl;
            return EXIT_FAILURE;
    }
    cout << "a " << op << " b = " << c << endl;
    // we assume below that Linux users can use a terminal
#ifndef __linux__
    cout << "Press any key to exit." << endl;
    cin.get();
    cin.ignore();
#endif
    return 0;
}
