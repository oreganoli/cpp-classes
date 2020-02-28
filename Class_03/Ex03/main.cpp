#include <array>
#include <iostream>
#include <random>
#include <tuple>

using namespace std;

class Matrix {
    static const auto MATRIX_SIZE = 5;
    static const auto MIN = -5;
    static const auto MAX = 5;
    array<array<int, MATRIX_SIZE>, MATRIX_SIZE> data {};
public:
    explicit Matrix(mt19937 & twister) {
        auto dist = uniform_int_distribution(MIN, MAX);
        for (auto & y : data) {
            for (int & x : y) {
                x = dist(twister);
            }
        }
    }
    auto column_minimums() -> array<int, MATRIX_SIZE> {
        auto minimums = *new array<int, MATRIX_SIZE>;
        for (auto & i : minimums) {
            i = INT32_MAX; // we ensure here that the comparisons below will make sense
        }
        for (int y = 0; y < MATRIX_SIZE; y++) {
            for (int x = 0; x < MATRIX_SIZE; x++) {
                if (data[x][y] < minimums[y]) {
                    minimums[y] = data[x][y];
                }
            }
        }
        return minimums;
    }
    auto diagonal_maximums() -> tuple<int, int> {
        auto maximums = make_tuple<int,int>(INT32_MIN, INT32_MIN);
        for (int i = 0; i < MATRIX_SIZE; i++) {
            int diag = data[i][i];
            int anti = data[i][MATRIX_SIZE - i - 1];
            if (diag > get<0>(maximums)) {
                get<0>(maximums) = diag;
            }
            if (anti > get<1>(maximums)) {
                get<1>(maximums) = anti;
            }
        }
        return maximums;
    }
    auto display() {
        printf("[");
        bool pad = false;
        for (auto y : data) {
            if (pad) {
                printf(" ");
            }
            for (int x = 0; x < MATRIX_SIZE; x++) {
                printf("%2d", y[x]);
                if (x < MATRIX_SIZE - 1) {
                    printf(", ");
                }
            }
            printf("\n");
            pad = true;
        }
        printf("]\n");
    }
};

int main() {
    random_device rd;
    mt19937 twister(rd());
    auto matrix = Matrix(twister);
    auto mins = matrix.column_minimums();
    auto maxes = matrix.diagonal_maximums();
    printf("Random matrix:\n");
    matrix.display();
    printf("Minimums for each column: ");
    printf("[");
    for (int i = 0; i < mins.size(); i++) {
        printf("%d", mins[i]);
        if (i < mins.size() - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("Diagonal maximum: %d\n", get<0>(maxes));
    printf("Anti-diagonal maximum: %d\n", get<1>(maxes));
    return 0;
}
