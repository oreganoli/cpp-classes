#include<cctype>
#include<iostream>
#include<string>
using namespace std;

string *podziel_na_slowa(char tekst[], int &ile_slow) {
    int word_count = 0;
    bool found_word = false;
    int i = 0;
    while (tekst[i] != '\0') {
        if (found_word && isspace(tekst[i])) {
            found_word = false;
        }
        if (!found_word && !isspace(tekst[i])) {
            word_count++;
            found_word = true;
        }
        i++;
    }
    i = 0;
    found_word = false;

    string *slowa = new string[word_count];
    ile_slow = word_count;
    int j = 0;
    int start = 0;
    int end = 0;
    
    while (tekst[i] != '\0') {
        if (isspace(tekst[i])) {
            found_word = false;
        }
        if (!found_word && !isspace(tekst[i])) {
            start = i;
            end = i;
            found_word = true;
        }
        if (found_word && !isspace(tekst[i])) {
            end = i;
            if (isspace(tekst[i + 1])) {
                slowa[j] = string(&tekst[start], &tekst[end + 1]);
                j++;
            }
            if (tekst[i + 1] == '\0') {
                slowa[j] = string(&tekst[start], &tekst[end + 1]);
                break;
            }
        }
        i++;
    }
    return slowa;
}

int main() {
    string input;
    int ile;
    cout << "Podaj zdanie do podzielenia na słowa:" << endl;
    getline(cin, input);
    string *slowa = podziel_na_slowa(input.data(), ile);
    cout << "Poszczególne słowa:" << endl;
    for (int i = 0; i < ile; i++) {
        cout << slowa[i] << endl;
    }
    delete[] slowa;
    cout << "Wszystkich słów: " << ile << endl;
    return 0;
}