#include <iostream>
#include <string>
using namespace std;

const int PRĘDKOŚĆ_OS = 90;
const int PRĘDKOŚĆ_CI = 50;
const int PRĘDKOŚĆ_TR = 70;
const int SPALANIE_OS = 7;
const int SPALANIE_CI = 25;
const int SPALANIE_TR = 12;

enum class TypAuta {
    Osobowy,
    Ciężarowy,
    Terenowy
};

class Samochód {
    protected:
    /// x - kilometry
    virtual double spalanie(int x) = 0;
    /// x - kilometry
    virtual double czasPrzejazdu(int x) = 0;
    virtual string dajNazwę() = 0;
    
    public:
    void dane() {
        cout << dajNazwę() << endl;
        cout << "Spalanie na 100 km: " << spalanie(100) << "l" << endl;
        cout << "Czas przejazdu 100 km: " << czasPrzejazdu(100) << "h" << endl;
    }
    static Samochód *z_konsoli();
};

class Osobowy : public Samochód {
    private:
    TypAuta typ;
    string nazwa;
    double oszczędność;
    virtual double spalanie(int x) {
        return oszczędność * SPALANIE_OS * x;
    }
    virtual double czasPrzejazdu(int x) {
        return x / (oszczędność * PRĘDKOŚĆ_OS);
    }
    virtual string dajNazwę() {
        return nazwa + ", samochód osobowy";
    }
    public:
    Osobowy(string nazwa, double oszczędność, TypAuta typ = TypAuta::Osobowy) {
        this->nazwa = nazwa;
        this->oszczędność = oszczędność;
        this->typ = typ;
    }
};

class Ciężarowy : public Samochód {
    private:
    TypAuta typ;
    string nazwa;
    double oszczędność;
    virtual double spalanie(int x) {
        return oszczędność * SPALANIE_CI * x;
    }
    virtual double czasPrzejazdu(int x) {
        return x / (oszczędność * PRĘDKOŚĆ_CI);
    }
    virtual string dajNazwę() {
        return nazwa + ", samochód ciężarowy";
    }
    public:
    Ciężarowy(string nazwa, double oszczędność, TypAuta typ = TypAuta::Ciężarowy) {
        this->nazwa = nazwa;
        this->oszczędność = oszczędność;
    }
};

class Terenowy : public Samochód {
    private:
    TypAuta typ;
    string nazwa;
    double oszczędność;
    virtual double spalanie(int x) {
        return oszczędność * SPALANIE_TR * x;
    }
    virtual double czasPrzejazdu(int x) {
        return x / (oszczędność * PRĘDKOŚĆ_TR);
    }
    virtual string dajNazwę() {
        return nazwa + ", samochód terenowy";
    }
    public:
    Terenowy(string nazwa, double oszczędność, TypAuta typ = TypAuta::Terenowy) {
        this->nazwa = nazwa;
        this->oszczędność = oszczędność;
        this->typ = typ;
    }
};

Samochód *Samochód::z_konsoli() {
    string input;
    TypAuta typ;
    string nazwa;
    double oszczędność = -1;
    do {
        cout << "Jaki typ samochodu stworzyć? C - ciężarowy, O - osobowy T - terenowy" << endl;
        getline(cin, input);
        if (input.find_first_of("Cc") != -1) {
            typ = TypAuta::Ciężarowy;
            break;
        }
        if (input.find_first_of("Oo") != -1) {
            typ = TypAuta::Osobowy;
            break;
        }
        if (input.find_first_of("Tt") != -1) {
            typ = TypAuta::Terenowy;
            break;
        }
        input.clear();
        cout << "Nie rozpoznano typu. Spróbuj ponownie." << endl;
    } while (true);
    cout << "Wpisz nazwę samochodu:" << endl;
    getline(cin, nazwa);
    input.clear();
    do {
        cout << "Wpisz oszczędność samochodu (musi być dodatnia):" << endl;
        getline(cin, input);
        try {
            oszczędność = stod(input);
        } catch (exception) {
            cerr << "Nieprawidłowy format liczby. Spróbuj ponownie." << endl;
        }
    } while (oszczędność <= 0);
    if (typ == TypAuta::Ciężarowy) {
        return new Ciężarowy(nazwa, oszczędność);
    } else if (typ == TypAuta::Osobowy) {
        return new Osobowy(nazwa, oszczędność);
    } else if (typ == TypAuta::Terenowy) {
        return new Terenowy(nazwa, oszczędność);
    } else {
        throw exception(); // ten kod powinien być nieosiągalny
    }
}

int main() {
    string input;
    int n = 0;
    cout << "Ile samochodów wpisać? Wpisz n >= 1:" << endl;
    do {
        getline(cin, input);
        try {
            n = stoi(input);
            if (n <= 0) {
                cout << "Spróbuj ponownie." << endl;
            }
        } catch (exception) {
            cerr << "Nieprawidłowy format liczby." << endl;
            continue;
        }
    } while (n <= 0);
    Samochód **tablica = new Samochód*[n];
    for (int i = 0; i < n; i++) {
        tablica[i] = Samochód::z_konsoli();
    }
    for (int i = 0; i < n; i++) {
        tablica[i]->dane();
        delete tablica[i];
    }
    delete[] tablica;
}