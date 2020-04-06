#include <iostream>
#include <string>
#include <sstream>
#include <optional>

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

int main() {
    std::cout << tag("html",
                     tag(
                             "body",
                             tag("p", "HTML generation")
                     )) << std::endl;
    return 0;
}
