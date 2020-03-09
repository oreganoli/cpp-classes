#include <iostream>

using namespace std;

auto add_and_mutate(int a, int & b) -> int {
    b += a; // mutates b, as b is passed by reference
    a = 0; // our local a, however, is a copy of the original parameter
    printf("a was copied into the function and mutated to %d\n", a);
    return b;
}

int main() {
    int a = 4;
    int b = -6;
    printf("a = %d, b = %d\n", a, b);
    printf("add_and_mutate(a, b) = %d\n", add_and_mutate(a, b));
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
