#include <iostream>
#include <random>
#include <string>

using namespace std;
typedef mt19937 generator;
const auto MIN_NUM = 1;
const auto MAX_NUM = 100;


int main() {
    random_device rd;
    uniform_int_distribution<random_device::result_type> rd_dist(0, UINT32_MAX);
    uniform_int_distribution<generator::result_type> dist(MIN_NUM, MAX_NUM);
    generator rng(rd_dist(rd));
    int number = dist(rng);
    int guess = -1;
    string input;
    while (guess != number) {
        cout << "Guess the number:" << endl << ">";
        getline(cin, input);
        guess = stoi(input);
        input.clear();
        if (guess < MIN_NUM || guess > MAX_NUM) {
            cout << "Hint: the number is between " << MIN_NUM << " and " << MAX_NUM << "." << endl;
            continue;
        }
        if (guess < number) {
            cout << "Too low!" << endl;
        } else if (guess > number) {
            cout << "Too high!" << endl;
        }
    }
    cout << "You guessed correctly!" << endl;
    return 0;
}
