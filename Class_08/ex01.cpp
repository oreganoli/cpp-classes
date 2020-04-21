#include <iostream>
using namespace std;

void minMax(int tab[], int w, int* wmin, int* wmax) {
    int min = INT32_MAX;
    int max = INT32_MIN;
    for (int i = 0; i < w; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    *wmin = min;
    *wmax = max;
}

int main()
{
    int t[] = {3, -4, 1, 0, 10, 5};
    int min, max;
    minMax(t, sizeof(t) / sizeof(t[0]), &min, &max);
    cout << "Najmniejszy i największy element ciągu to " << min << " i " << max << endl;
    return 0;
}