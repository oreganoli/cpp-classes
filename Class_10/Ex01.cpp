#include <cmath>
#include <iostream>
#include <string>
using namespace std;
class Wektor {
    private:
    double x;
    double y;

    public:
    Wektor();
    Wektor(double x, double y);
    double dlugosc();
    Wektor pomnoz(double a);
    Wektor dodaj(const Wektor &w);
    Wektor odejmij(const Wektor &w);
    Wektor normalizuj();
    string toString();
};

Wektor::Wektor() {
    this->x = 0;
    this->y = 0;
}
Wektor::Wektor(double x, double y) {
    this->x = x;
    this->y = y;
}
double Wektor::dlugosc() {
    return sqrt(this->x * this->x + this->y * this->y);
}
Wektor Wektor::pomnoz(double a) {
    return Wektor(this->x * a, this->y * a);
}
Wektor Wektor::dodaj(const Wektor &w) {
    return Wektor(this->x + w.x, this->y + w.y);
}
Wektor Wektor::odejmij(const Wektor &w) {
    return Wektor(this->x - w.x, this->y - w.y);
}
Wektor Wektor::normalizuj() {
    return Wektor(this->x / this->dlugosc(), this->y / this->dlugosc());
}
string Wektor::toString() {
    string result;
    result.append("[");
    result.append(to_string(this->x));
    result.append(", ");
    result.append(to_string(this->y));
    result.append("]");
    return result;
}

int main() {
    Wektor w1(2, 4), w2(1, 0);
    cout << "w1 = " << w1.toString() << endl;
    cout << "w2 = " << w2.toString() << endl;
    cout << "|w1| = " << w1.dlugosc() << endl;
    cout << "|w2| = " << w2.dlugosc() << endl;
    cout << "w1 + w2 = " << w1.dodaj(w2).toString() << endl;
    cout << "w1 - w2 = " << w1.odejmij(w2).toString() << endl;
    cout << "-2w1 = " << w1.pomnoz(-2).toString() << endl;
    cout << "w1 po normalizacji = " << w1.normalizuj().toString() << endl;
    cout << "w2 po normalizacji = " << w2.normalizuj().toString() << endl;
    cout << "w1 * 2 - w2 = " << w1.pomnoz(2).odejmij(w2).toString() << endl;
}