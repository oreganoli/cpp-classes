#include <iostream>
#include <string>
#include <fstream>
using namespace std;

auto sum_and_save(const char* filename) {
    int sum = 0;
    auto in = ifstream();
    in.open(filename);
    auto out = ofstream();
    string current;
    bool numbers_present = false;
    while (getline(in, current)) {
        numbers_present = true;
        try {
            sum += stoi(current);
        } catch (exception &_ex) {
            numbers_present = false;
            continue;
        }
    }
    if (!numbers_present) {
        sum = 1; // pre-populate a new file with a 1
    }
    in.close();
    out.open(filename, fstream::app);
    out << to_string(sum) << endl;
    out.close();
}

int main() {
    sum_and_save("../output.txt");
    return 0;
}
