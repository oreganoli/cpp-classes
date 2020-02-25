#include <iostream>
#include <string>

using namespace std;

const auto CURRENCY = "PLN";
const long double TAX_FREE = 556.02;
const long double BASE_RATE = 0.18;
const long double UPPER_RATE = 0.32;
const long double TAX_BRACKET = 85528;
const long double UPPER_BASE = 14839.02;

/// Swaps commas for periods for the purpose of numerical input parsing.
/// \param s String containing the numerical input to be Americanized
/// \return void
auto americanize(std::string *s) {
    std::replace(s->begin(), s->end(), ',', '.');
}


auto income_tax(long double income) -> long double {
    if (income <= TAX_FREE) {
        return 0;
    }
    if (income <= TAX_BRACKET) {
        return BASE_RATE * income - TAX_FREE;
    } else {
        return UPPER_BASE + UPPER_RATE * (income - TAX_BRACKET);
    }
}

int main() {
    string input;
    cout << "Enter your income [" << CURRENCY <<"]:" << endl << ">";
    getline(cin, input);
    americanize(&input);
    auto tax = income_tax(stold(input));
    cout << "Your income tax is " << tax << " " << CURRENCY << "." << endl;
    return 0;
}
