#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

char *next_word(istream &input_stream, int &index, int &word_length) {
    bool found_word = false;
    bool non_word_char;
    char curr_char;
    index = -1;
    word_length = 0;
    while (input_stream.peek() != EOF) {
        input_stream.get(curr_char);
        non_word_char = isspace(curr_char) || ispunct(curr_char);
        if (!found_word && !non_word_char) {
            found_word = true;
            word_length++;
            index = input_stream.tellg();
            index--;
            continue;
        }
        if (!found_word && non_word_char) {
            continue;
        }
        if (found_word && !non_word_char) {
            word_length++;
        }
        if (found_word && non_word_char) {
            break;
        }
    }
    if (word_length > 0 && index != -1) {
        char *word = new char[word_length + 1];
        input_stream.seekg(index);
        for (int i = 0; i < word_length; i++) {
            word[i] = input_stream.get();
        }
        word[word_length] = '\0';
        input_stream.seekg(index + word_length);
        return word;
    } else {
        return nullptr;
    }
}

int fif(char *filename, char *word, char* &ptr) {
    auto input_stream = ifstream(filename);
    int result = -1;
    int word_pos = -1;
    int len;
    int max_len = 0;
    ptr == nullptr;
    char *curr_word = nullptr;
    do {
        curr_word = next_word(input_stream, word_pos, len);
        if (curr_word != nullptr) {
            if (strcmp(curr_word, word) == 0 && result == -1) {
                result = word_pos;
            }
            if (len > max_len) {
                if (ptr != nullptr) {
                    delete[] ptr;
                }
                max_len = len;
                ptr = new char[len + 1];
                strcpy(ptr, curr_word);
            }
            delete[] curr_word;
        }
    } while (curr_word != nullptr);
    return result;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "file_finder usage: file_finder filename.txt" << endl;
        return EXIT_FAILURE;
    }
    char *longest = nullptr;
    string word;
    cout << "Enter a word to look for in the file:" << endl;
    getline(cin, word);
    int where_word = fif(argv[1], (char*)word.data(), longest);
    if (where_word != -1) {
        cout << "The word \"" << word << "\" was found at position " << where_word << "." << endl;
    } else {
        cout << "The word \"" << word << "\" was not found in the file." << endl;
    }
    if (longest != nullptr) {
        cout << "The longest word in the file was \"" << longest << "\"." << endl;
        delete[] longest;
    }
}