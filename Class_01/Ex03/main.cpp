#include <iostream>
#include <cmath>
#include <string>
using namespace std;
const double BMI_LOWER_BOUND = 18.5;
const double BMI_UPPER_BOUND = 24.9;
auto bmi(double weight, double height) -> double {
    if (weight <= 0 || height <= 0) {
        throw invalid_argument("The height and weight must both be positive.");
    }
    return weight / pow(height, 2);
}
/// Swaps commas for periods for the purpose of numerical input parsing.
/// \param s String containing the numerical input to be Americanized
/// \return void
auto americanize(std::string *s) {
    std::replace(s->begin(), s->end(), ',', '.');
}

int main() {
    string input;
    double height;
    double weight;
    cout << "Enter your height [m]:" << endl << ">";
    getline(cin, input);
    americanize(&input);
    height = stod(input);
    input.clear();
    cout << "Enter your weight [kg]" << endl << ">";
    getline(cin, input);
    americanize(&input);
    weight = stod(input);

    try {
        auto your_bmi = bmi(weight, height);
        cout << "Your BMI is " << your_bmi << "." << endl;
        if (your_bmi < BMI_LOWER_BOUND) {
            cout << "You are underweight." << endl;
        } else if (your_bmi >= BMI_LOWER_BOUND && your_bmi <= BMI_UPPER_BOUND) {
            cout << "Your weight is normal." << endl;
        } else {
            cout << "You are overweight." << endl;
        }

    } catch (exception &ex) {
        cout << ex.what() << endl;
        return -1;
    }
    return 0;
}
