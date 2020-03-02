#include <cstring>
#include <iostream>

auto count_occur(char str[], char sub[]) -> int {
    int result = 0;
    int len = strlen(str);
    int sub_len = strlen(sub);
    for (int i = 0; i < len; i++) {
        if (i + sub_len > len) {
            break;
        }
        for (int j = 0; j < sub_len; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
            if (j == sub_len - 1) {
                result += 1;
                i += j;
            }
        }
    }
    return result;
}

int main() {
    std::cout << count_occur("AlibabAlia", "Ali") << std::endl; // 2
    std::cout << count_occur("mama ma kotama", "ma") << std::endl; // 4
    std::cout << count_occur("Mārcus Iūliam pulsat" , "x") << std::endl; // 0
    return 0;
}
