#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

char get_num(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else if (c == '\0') {
		return 0;
	} else {
		throw invalid_argument("not a digit");
	}
}

int cstring_to_int(const char *str, int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += (int)get_num(str[n - i - 1]) * pow(10, i);
	}
	return result;
}

class Czas {
		private:
		int godz_;
		int minuty_;
		public:
		Czas(int hours, int minutes) {
			this->godz_ = hours;
			this->godz_ += (minutes - (minutes % 60)) / 60;
			this->minuty_ = minutes % 60;
		}
		Czas(string str) {
			int hours = 0;
			int minutes = 0;
			int hpos = str.find("h");
			int end = str.find("m");
			if (hpos != -1) {
				hours = cstring_to_int(str.data(), hpos);
				if (end != -1) {
					minutes = cstring_to_int(str.data() + hpos + 1, end - hpos - 1);
				} else {
					minutes = cstring_to_int(str.data() + hpos + 1, str.length() - hpos - 1);
				}
			} else {
				throw invalid_argument("invalid hour format");
			}
			*this = Czas(hours, minutes);
		}
		string toString() const {
			return to_string(this->godz_) + "h" + to_string(this->minuty_) + "m";
		}
		Czas dodaj(const Czas &t) const {
			return Czas(this->godz_ + t.godz_, this->minuty_ + t.minuty_);
		}
		Czas odejmij(const Czas &t) const {
			return Czas(this->godz_ - t.godz_, this->minuty_ - t.minuty_);
		}
		Czas pomnoz(int ile) const {
			return Czas(this->godz_ * ile, this->minuty_ * ile);
		}
		static Czas sumuj(Czas *tab[], int n) {
			Czas curr = Czas(0, 0);
			for (int i = 0; i < n; i++) {
				curr = curr.dodaj(*tab[i]);
			}
			return curr;
		}
};

int main() {
	auto t1 = Czas(10, 56);
	auto t2 = Czas(0, 123);
	cout << "t1 = " << t1.toString() << endl;
	cout << "t2 = " << t2.toString() << endl;
	cout << "t1 + t2 = " << t1.dodaj(t2).toString() << endl;
	cout << "t1 - t2 = " << t1.odejmij(t2).toString() << endl;
	Czas *tab[] = {&t1, &t2, &t2};
	cout << "Czas::sumuj(tab, 3) = " << Czas::sumuj(tab, 3).toString() << endl;
	cout << "t1 * 2 = " << t1.pomnoz(2).toString() << endl;
	Czas t3("3h17m");
	cout << "z łańcucha: t3 = " << t3.toString() << endl;
}