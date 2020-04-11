#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

auto frequencies(string &str) -> int* {
    auto s = str.c_str();
    auto freq = new int[26] {0};
    for (int i = 0; i < str.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            freq[s[i] - 'a']++;
        }
    }
    return freq;
}

auto show_histogram(int frequencies[]) {
    int maximum = 0;
    for (int i = 0; i < 26; i++) {
        if (frequencies[i] > maximum) {
            maximum = frequencies[i];
        }
    }
    if (maximum == 0) {
        cout << "The frequency table provided is invalid - it has no non-zero entries." << endl;
        return;
    }
    for (int i = 0; i < 26; i++) {
        int stars = (50 * frequencies[i]) / maximum;
        cout << (char)('a' + i) << ' ';
        for (int j = 0; j < stars; j++) {
            cout << '*';
        }
        for (int j = 0; j < 50 - stars; j++) {
            cout << ' ';
        }
        cout << ' ' << frequencies[i] << endl;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    stringstream s;
    auto in = ifstream(argv[1]);
    s << in.rdbuf();
    string str = s.str();
    auto freqs = frequencies(str);
    show_histogram(freqs);
    return EXIT_SUCCESS;
}
