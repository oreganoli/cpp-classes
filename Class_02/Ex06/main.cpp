#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

auto digits(int x) -> vector<int>* {
    auto digits = new vector<int>;
    int copy = abs(x);
    while (copy >= 10) {
        digits->push_back(copy % 10);
        copy /= 10;
    }
    digits -> push_back(copy % 10);
    reverse(digits->begin(), digits->end());
    return digits;
}

int main() {
    int x;
    string input;
    cout << "Enter an integer:" << endl << ">";
    getline(cin, input);
    try {
        x = stoi(input);
    } catch (exception &ex) {
        cout << ex.what() << endl;
        cout << "Terminating." << endl;
        return EXIT_FAILURE;
    }
    auto digs = digits(x);
    int sum = 0;
    double avg_odd = 0;
    double counter_odd = 0;
    double avg_even = 0;
    double counter_even = 0;
    for (int dig : *digs) {
        sum += dig;
        if (dig % 2 != 0) {
            avg_odd += dig;
            counter_odd++;
        } else {
            avg_even += dig;
            counter_even++;
        }
    }
    if (counter_odd != 0) {
        avg_odd /= counter_odd;
    }
    if (counter_even != 0) {
        avg_even /= counter_even;
    }
    cout << "Sum of digits: " << sum << endl;
    if (counter_odd != 0) {
        cout << "Ratio of the average of even digits to the average of the odd digits: " << avg_even / avg_odd << endl;
    } else {
        cout << "The ratio of the averages of even and odd digits could not be calculated, as there are no odd digits."
             << endl;
    }
    return 0;
}
