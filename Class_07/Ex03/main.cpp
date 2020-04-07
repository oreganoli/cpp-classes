#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int AGE_F = 60;
const int AGE_M = 65;

auto retirement(char filename[]) {
    auto in = ifstream();
    in.open(filename);
    auto out_f = ofstream();
    auto out_m = ofstream();
    ofstream* output;
    out_f.open("../women.txt");
    out_m.open("../men.txt");
    string name;
    string surname;
    char sex;
    int age;
    int retirement;
    string current_line;
    while (getline(in, current_line)) {
        auto first_space = current_line.find(" ");
        auto second_space = current_line.find(" ", first_space + 1);
        auto third_space = current_line.find(" ", second_space + 1);
        name = current_line.substr(0, first_space);
        surname = current_line.substr(first_space, second_space - first_space);
        sex = current_line[second_space + 1];
        age = stoi(current_line.substr(third_space));
        if (sex == 'M') {
            output = &out_m;
            retirement = AGE_M;
        } else {
            output = &out_f;
            retirement = AGE_F;
        }
        *output << surname << " " << name << " " << retirement - age << endl;
    }
}

int main() {
    retirement("../input.txt");
    return 0;
}
