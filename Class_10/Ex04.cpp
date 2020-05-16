#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class ElementZamowienia {
    private:
    string nazwa_;
    double cena_;
    int liczbaSztuk_;
    public:
    ElementZamowienia() {
        nazwa_ = "Pusty przedmiot";
        cena_ = 0.0;
        liczbaSztuk_ = 0;
    }
    ElementZamowienia(string name, double price, int pcs) {
        nazwa_ = name;
        cena_ = price;
        liczbaSztuk_ = pcs;
    }
    string toString() {
        return nazwa_ + " " + to_string(cena_) + "zł, " + to_string(liczbaSztuk_) + "szt., łącznie " + to_string(obliczKoszt()) + "zł";
    }
    double obliczRabat() {
        if (liczbaSztuk_ >= 5) {
            return 0.9;
        } else {
            return 1;
        }
    }
    double obliczKoszt() {
        return cena_ * (double)liczbaSztuk_ * obliczRabat();
    }
    double obliczKosztBez() {
        return cena_ * (double)liczbaSztuk_;
    }
};
class Zamowienie {
    private:
    ElementZamowienia *elementy_;
    int rozmiar_;
    int maksRozmiar_;
    public:
    Zamowienie(int capacity) {
        elementy_ = new ElementZamowienia[capacity];
        rozmiar_ = 0;
        maksRozmiar_ = capacity;
    }
    ~Zamowienie() {
        delete[] elementy_;
    }
    bool dodaj(const ElementZamowienia &p) {
        if (rozmiar_ + 1 > maksRozmiar_) {
            return false;
        }
        elementy_[rozmiar_] = p;
        rozmiar_++;
        return true;
    }
    double obliczKoszt() {
        double sum = 0;
        for (int i = 0; i < rozmiar_; i++) {
            sum += elementy_[i].obliczKoszt();
        }
        return sum;
    }
    double obliczKosztBez() {
        double sum = 0;
        for (int i = 0; i < rozmiar_; i++) {
            sum += elementy_[i].obliczKosztBez();
        }
        return sum;
    }
    void pisz() {
        for (int i = 0; i < rozmiar_; i++) {
            cout << i + 1 << ". " << elementy_[i].toString() << endl;
        }
        cout << "Całkowity koszt: " << obliczKoszt() << "zł" << endl;
        cout << "Rabat: " << obliczKosztBez() - obliczKoszt() << "zł" << endl;
    }
};
int main() {
    cout << setprecision(4);
    auto z = Zamowienie(10);
    z.dodaj(ElementZamowienia("Chleb", 4.0, 2));
    z.dodaj(ElementZamowienia("Mleko", 2.5, 1));
    z.dodaj(ElementZamowienia("Cukier", 4.0, 5));
    z.dodaj(ElementZamowienia("Papierosy", 9.0, 1));
    z.pisz();
}