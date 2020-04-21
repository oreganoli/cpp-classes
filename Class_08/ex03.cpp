#include <iostream>
using namespace std;

void ptradv(int *wsk, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Adres: " << wsk << ", wartość: " << *wsk << endl;
        wsk += 1;
    }
}

int main()
{
    int t[] = {1, 3, -6, 4};
    int *z;
    ptradv(t, 4);
    z = t;
    ptradv(z, 4);
    return 0;
}