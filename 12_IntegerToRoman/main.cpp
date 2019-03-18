#include <iostream>

using namespace std;

string intToRoman(int num);

static auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

string intToRoman(int num) {
    if (num < 1 || num > 3999)
        return "";
    //列出所有的组合
    const int intDict[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string romanDict[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res = "";
    int i = 0;
    //让拥有的组合重复出现
    while (num > 0 && i < 13) {
        if (num >= intDict[i]) {
            res += romanDict[i];
            num -= intDict[i];
        } else
            i++;
    }
    return res;
}

int main() {
    std::cout << intToRoman(1994) << std::endl;
    return 0;
}