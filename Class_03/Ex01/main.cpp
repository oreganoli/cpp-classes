#include <array>
#include <iostream>
#include <random>
using namespace std;

const int SIZE = 10;
const double MIN = 3.0;
const double MAX_EXCLUSIVE = 9.0;

auto ten_nums(mt19937 rng, uniform_real_distribution<double> dist) {
    auto arr = *new array<double, SIZE>;
    double sum = 0;
    double avg;
    for (double & i : arr) {
        do {
            i = dist(rng);
        } while (i == MAX_EXCLUSIVE); // in the astronomically rare case we actually hit the upper bound, we re-roll
        sum += i;
    }
    avg = sum / arr.size();
    int lt = 0;
    int gt = 0;
    for (auto i : arr) {
        if (i < avg) {
            lt++;
        } else if (i > avg) {
            gt++;
        }
        printf("%.1f ", arr[i]);
    }
    printf("\n");
    for (int i = arr.size() - 1; i >= 0; i--) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
    printf("Average: %.1f\n", avg);
    printf("Greater than average: %d\n", gt);
    printf("Lesser than average: %d\n", lt);
}

int main() {
    random_device rd;
    mt19937 twister(rd());
    uniform_real_distribution dist(MIN, MAX_EXCLUSIVE);
    ten_nums(twister, dist);
    return 0;
}
