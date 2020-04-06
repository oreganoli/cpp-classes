#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

auto count(char filename[], int &whitespace, int &words) -> int {
    whitespace = 0;
    words = 0;
    int result = 0;
    ifstream stream = ifstream();
    stream.open(filename);
    bool expecting_word = true;
    while (true) {
        int current = stream.get();
        if (current == EOF) {
            break;
        }
        if (isspace(current)) {
            whitespace++;
            expecting_word = true;
        } else {
            if (expecting_word) {
                words++;
            }
            expecting_word = false;
        }
        result++;
    }
    return result;
}


int main() {
    int ws;
    int words;
    int result = count("Makefile", ws, words);
    std::cout << "Total characters: " << result << ", whitespace: " << ws << ", words: " << words << std::endl;
    return 0;
}
