#include <iostream>
using namespace std;

void move_memory(int *to, int *from, int size) {
    int *temp = new int[size];
    for (int i = 0; i < size; i++) {
        temp[i] = from[i];
    }
    for (int i = 0; i < size; i++) {
        to[i] = temp[i];
    }
    delete[] temp;
}
void reverse_memory(int *slice, int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(slice[i], slice[size - i - 1]);
    }
}

class Lista
{
private:
    int *liczby;
    int pojemnosc;
    int rozmiar;
    void delete_at(int index) {
        if (index < rozmiar - 1) {
            move_memory(liczby + index, liczby + index + 1, rozmiar - index - 1);
        }
        rozmiar--;
    }
    void delete_reps_of(int x) {
        int first_index = znajdz(x);
        for (int i = first_index + 1; i < rozmiar; i++) {
            if (liczby[i] == x) {
                delete_at(i);
            }
        }
    }
public:
    Lista(int capacity)
    {
        this->liczby = new int[capacity];
        this->pojemnosc = capacity;
        this->rozmiar = 0;
    }
    ~Lista()
    {
        delete[] this->liczby;
    }
    void dodajElement(int x)
    {
        if (rozmiar + 1 > pojemnosc) {
            cerr << "lista pełna!" << endl;
            return;
        }
        liczby[rozmiar] = x;
        rozmiar++;
    }
    int znajdz(int x)
    {
        for (int i = 0; i < rozmiar; i++)
        {
            if (liczby[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
    void pisz()
    {
        cout << "Rozmiar/pojemność: " << rozmiar << '/' << pojemnosc << endl;
        cout << "Zawartość: [";
        for (int i = 0; i < rozmiar; i++)
        {
            cout << liczby[i];
            if (i < rozmiar - 1)
            {
                cout << ", ";
            }
        }
        cout << ']' << endl;
    }
    void usunPierwszy(int x) {
        int index = znajdz(x);
        if (index == -1) {
            return;
        }
        delete_at(index);
    }
    void odwroc() {
        reverse_memory(liczby, rozmiar);
    }
    void usunPowtorzenia() {
        for (int i = 0; i < rozmiar; i++) {
            delete_reps_of(liczby[i]);
        }
    };
};

int main()
{
    const int N = 10;
    Lista *l = new Lista(N);
    for (int i = 0; i < N / 2; ++i)
    {
        l->dodajElement((1 << i));
    }
    l->dodajElement(2);
    l->dodajElement(8);
    l->pisz();
    l->usunPierwszy(2);
    l->pisz();
    for (int i = 0; i < N/2; ++i) {
        l->dodajElement( (1 << i) );
    }
    l->pisz();
    cout << "Po usunięciu powtórzeń:" << endl;
    l->usunPowtorzenia();
    l->pisz();
    cout << "Po odwróceniu:" << endl;
    l->odwroc();
    l->pisz();
    delete l;
    return 0;
}