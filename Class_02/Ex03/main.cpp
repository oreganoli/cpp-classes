#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string input;
    auto nums = new vector<int>;
    int curr;
    cout << "Enter some integers. 0 will end the sequence and not be counted." << endl;
    while (true) {
        getline(cin, input);
        curr = stoi(input);
        input.clear();
        if (curr == 0) {
            break;
        }
        nums->push_back(curr);
    }
    if (nums->empty()) {
        cout << "Can't do anything without any numbers, exiting." << endl;
        return EXIT_FAILURE;
    }
    sort(nums->begin(), nums->end());
    auto extremes = nums->front() + nums->back();
    double avg = 0;
    double counter = 0;
    for (auto x: *nums) {
        avg += (double)x;
        counter++;
    }
    avg /= counter;
    int gt_avg = 0;
    for (auto x: *nums) {
        if (x > avg) {
            gt_avg++;
        }
    }
    cout << "The sum of the smallest and greatest numbers is " << extremes << "." << endl;
    cout << "The average is " << avg << "." << endl;
    cout << gt_avg << " numbers are greater than the average." << endl;
    return 0;
}
