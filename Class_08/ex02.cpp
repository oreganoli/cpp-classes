#include <iostream>
#include <cstring>
using namespace std;

void strsl(char s1[], char s2[], char *&dluzszy, char *&krotszy) {
    dluzszy = s1;
    krotszy = s2;
    auto l1 = strlen(s1);
    auto l2 = strlen(s2);
    if (l2 > l1) {
        krotszy = s1;
        dluzszy = s2;
    }
}

int main()
{
    char s1[100];
    char s2[100];
    cout << "Podaj pierwszy ciag: ";
    cin >> s1;
    cout << "Podaj drugi ciag: ";
    cin >> s2;
    char *krotszy;
    char *dluzszy;
    strsl(s1, s2, dluzszy, krotszy);
    cout << "Dluzszy z podanych lancuchow to: " << dluzszy << endl
         << "Krotszy z podanych lancuchow to: " << krotszy << endl;
    return 0;
}