#include<iomanip> // potrzebne do estetycznego wyświetlania tabliczki
#include<exception>
#include<iostream>
#include<string>
using namespace std;

int get_factor(string &input_buffer, int upper_limit) {
    int x = 0;
    do {
        getline(cin, input_buffer);
        try {
            x = stoi(input_buffer);
        } catch (invalid_argument) {
            cout << "Nieprawidłowy format liczby. Spróbuj ponownie." << endl;
            input_buffer.clear();
            continue;
        }
        if (x < 1) {
            cout << "Mnożna i mnożnik muszą być większe od 0. Spróbuj ponownie." << endl;
            input_buffer.clear();
        } else if (x > upper_limit) {
            cout << "Mnożna i mnożnik nie mogą być większe od " << upper_limit << ". Spróbuj ponownie." << endl;
        }
    } while (x < 1 || x > upper_limit);
    return x;
}

void tabliczka(int r) {
    if (r < 0) {
        throw invalid_argument("tabliczka mnożenia nie ma sensu dla niedodatnich rozmiarów\n");
    }
    /// wewnętrznie tabliczka jest alokowana jako jednowymiarowa, by ograniczyć ilość alokacji i nieciągłość w pamięci
    int *dane = new int[r * r];
    /// osobno alokujemy wskaźniki do poszczególnych wierszy tabliczki; tę tablicę możemy traktować jako dwuwymiarową
    int **tabliczka = new int*[r];

    for (int y = 0; y < r; y++) {
        tabliczka[y] = &dane[y * r];
        for (int x = 0; x < r; x++) {
            tabliczka[y][x] = (y + 1) * (x + 1);
        }
    }

    string input;
    while (true) {
        cout << "Podaj mnożną: ";
        int x = get_factor(input, r);
        cout << "Podaj mnożnik: ";
        int y = get_factor(input, r);
        cout << x << " * " << y << " = " << tabliczka[y - 1][x - 1] << endl;
        cout << "Aby zakończyć pracę programu, wpisz \"quit\". Aby kontynuować, wciśnij Enter. ";
        getline(cin, input);
        if (input == "quit") {
            break;
        } else {
            input.clear();
        }
    }
    int top = r * r;
    int digits = 0;
    while (top != 0) { top /= 10; digits++; }
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < r; x++) {
            cout << setfill(' ') << setw(digits) << tabliczka[y][x] << " ";
        }
        cout << endl;
    }
    delete[] tabliczka;
    delete[] dane;
}

int main()
{
    int i = 0;
    string input;
    do {
        cout << "Podaj wielkość tabliczki mnożenia: ";
        getline(cin, input);
        try {
            i = stoi(input);
        } catch (invalid_argument) {
            cout << "Nieprawidłowy format liczby. Spróbuj ponownie." << endl;
            input.clear();
            continue;
        }
        if (i < 1) {
            cout << "Tabliczka mnożenia musi mieć wielkość przynajmniej 1x1. Spróbuj ponownie." << endl;
            input.clear();
        }
    } while (i < 1);
    tabliczka(i);
    return 0;
}