#include <iostream>
#include <string>
using namespace std;
auto celsius_to_fahrenheit(double celsius) -> double {
    return 1.8 * celsius + 32;
}

int main() {
    cout << "Temperature [°C] = ?" << endl << ">";
    string input;
    getline(cin, input);
    cout << "Temperature [°F] = " << celsius_to_fahrenheit(stod(input)) << endl;
    return 0;
}
