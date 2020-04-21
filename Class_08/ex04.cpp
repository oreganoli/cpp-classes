#include <iostream>
using namespace std;

int *odwroc(int *tab, int rozmiar) {
    int *nowa = new int[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        nowa[i] = tab[rozmiar - i - 1];
    }
    return nowa;
}

int main() {
    int liczby[] = {1, 2, 3, 4};
    int *odwrotnie = odwroc(liczby, 4);
    for (int i = 0; i < 4; ++i)
    {
        cout << odwrotnie[i] << " ";
    } // powinno wyświetlić: 4 3 2 1
    cout << endl;
    delete[] odwrotnie; // zwolnienie przydzielonej pamięci
    return 0;
}