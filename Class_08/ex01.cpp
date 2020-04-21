#include <iostream>
using namespace std;

void minMax(int tab[], int w, int* wmin, int* wmax) {}

int main()
{
    int t[] = {3, -4, 1, 0, 10, 5};
    int min, max;
    minMax(t, sizeof(t) / sizeof(t[0]), &min, &max);
    cout << "Najmniejszy i najwieksy element ciągu, to " << min << ", " << max << endl;
    return 0;
}