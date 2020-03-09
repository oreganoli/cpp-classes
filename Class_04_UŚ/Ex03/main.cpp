#include <iostream>

using namespace std;

auto factorial_iter(unsigned long n) -> unsigned long {
    if (n == 0) {
        return 1;
    }
    unsigned long output = 1;
    for (unsigned long i = 1; i <= n; i++) {
        output *= i;
    }
    return output;
}

auto factorial_recursive(unsigned long n) -> unsigned long {
    if (n == 0) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int main() {
    printf("factorial_iter(5) = %lu\n", factorial_iter(5));
    printf("factorial_recursive(5) = %lu\n", factorial_recursive(5));
    return 0;
}
