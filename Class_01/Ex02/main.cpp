#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    auto nums = new vector<int>();
    string input;
    for (int i = 0; i < 3; i++) {
        cout << "Enter an integer:" << endl << ">";
        getline(cin, input);
        nums->push_back(stoi(input));
        input.clear();
    }
    sort(nums->begin(), nums->end());
    cout << "Smallest number: " << nums->front() << endl;
    cout << "Greatest number: " << nums->back() << endl;
    return 0;
}
