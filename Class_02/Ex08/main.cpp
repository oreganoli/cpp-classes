#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto is_prime(int n) -> bool {
    if (n < 1) {
        throw invalid_argument("Checking the primeness of numbers smaller than 1 makes no sense");
    }
    if (n == 1 || n == 2 || n == 3) {
        return true;
    }
    for (int i = n - 1; i >= 2; i--) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    int n;
    cout << "Enter an integer greater than7 or equal to 1:" << endl << ">";
    getline(cin, input);
    try {
        n = stoi(input);
        if (is_prime(n)) {
            cout << "The number given is prime." << endl;
        } else {
            cout << "The number given is not prime." << endl;
        }
    } catch (exception &ex) {
        cout << ex.what() << endl;
        return EXIT_FAILURE;
    }
    return 0;
}
