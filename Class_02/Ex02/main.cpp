#include <iostream>
#include <string>
using namespace std;

auto sum_while(int lower, int upper) -> int {
    int diff = upper - lower;
    int i = 1;
    int result = lower;
    while (i <= diff) {
        result += lower + i;
        i++;
    }
    return result;
}

auto sum_do_while(int lower, int upper) -> int {
    int diff = upper - lower;
    int i = 0;
    int result = 0;
    do {
        result += lower + i;
        i++;
    } while (i <= diff);
    return result;
}

auto sum_for(int lower, int upper) -> int {
    int result = lower;
    for (int i = lower + 1; i <= upper; i++) {
        result += i;
    }
    return result;
}

int main() {
    string input;
    int a;
    int b;
    cout << "Enter the lower bound of the range:" << endl << ">";
    getline(cin, input);
    a = stoi(input);
    input.clear();
    cout << "Enter the upper bound of the range:" << endl << ">";
    getline(cin, input);
    b = stoi(input);
    if (a >= b) {
        cout << "The upper bound must be greater than the lower bound." << endl;
        return EXIT_FAILURE;
    }
    cout << sum_while(a, b) << endl;
    cout << sum_do_while(a, b) << endl;
    cout << sum_for(a, b) << endl;
    return 0;
}
