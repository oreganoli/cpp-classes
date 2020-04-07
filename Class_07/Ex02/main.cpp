#include <fstream>
#include <iostream>
using namespace std;

auto search(const char in_filename[], const char out_filename[], const char word[]) {
    auto in = ifstream();
    in.open(in_filename);
    auto out = ofstream();
    out.open(out_filename);
    int line_counter = 1;
    string current_line;
    while (getline(in, current_line)) {
        if (current_line.find(word) != -1) {
            out << line_counter << ": " << current_line << endl;
        }
        line_counter++;
    }
    out << EOF;
}

int main() {
    search("../input.txt", "../output.txt", "egzamin");
    return 0;
}
