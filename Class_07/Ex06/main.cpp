#include <iostream>
#include <string>
#include <sstream>
#include <optional>
#include <fstream>
#include <vector>

using namespace std;

auto tag(string tag_name, string content, optional<string> properties = nullopt) -> string {
    stringstream output;
    output << "<" << tag_name;
    if (properties) {
        output << " " << properties.value();
    }
    output << ">" << content << "</" << tag_name << ">";
    return output.str();
}

auto split(string input, char delim) -> vector<string> {
    auto output = vector<string>();
    int index = 0;
    int next;
    do {
        next = input.find(delim, index);
        output.push_back(input.substr(index, next - index));
        index = next + 1;
    } while (next != -1);
    return output;
}

auto htmlize(ifstream &file) -> string {
    stringstream table_contents;
    stringstream current_row;
    bool headers = true;
    string line;
    vector<string> elements;
    while (getline(file, line)) {
        elements = split(line, ' ');
        if (headers) {
            for (int i = 0; i < elements.size(); i++) {
                current_row << tag("th", elements[i]);
            }
        } else {
            for (int i = 0; i < elements.size(); i++) {
                current_row << tag("td", elements[i]);
            }
        }
        headers = false;
        table_contents << tag("tr", current_row.str());
        current_row.str("");
    }
    return tag("table", tag("tbody", table_contents.str()));
}

int main() {
    auto in = ifstream();
    in.open("../input.txt");
    string result = htmlize(in);
    in.close();
    auto out = ofstream("../output.html");
    out << result;
    out.close();
    return 0;
}
