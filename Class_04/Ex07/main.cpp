#include <iostream>

// This is the same as UŚ class 4 exercise 2.
auto fib_iter(unsigned int n) -> unsigned int {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int sum = 0;
    int penult = 0;
    int last = 1;
    for (int i = 1; i < n; i++) {
        sum = penult + last;
        penult = last;
        last = sum;
    }
    return sum;
}

auto fib_recursive(unsigned int n) -> unsigned int {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib_recursive(n - 2) + fib_recursive(n - 1);
    }
}

int main() {
    printf("fib_iter(2) = %d\n", fib_iter(2));
    printf("fib_iter(6) = %d\n", fib_iter(6));
    printf("fib_recursive(2) = %d\n", fib_recursive(2));
    printf("fib_recursive(6) = %d\n", fib_recursive(6));
    return 0;
}