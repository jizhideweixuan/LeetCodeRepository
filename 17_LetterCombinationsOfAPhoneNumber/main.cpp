#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

vector<string> letterCombinations(string digits);

vector<string> mapCombinations(string digits);

//使用unordered_map
vector<string> mapCombinations(string digits) {
    IOS;
    unordered_map<char, vector<string>> table = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}};
    if (digits.size() == 1) return table[digits[0]];
    vector<string> subCombinations = letterCombinations(digits.substr(1));
    vector<string> result;
    for (string item : table[digits.at(0)]) {
        for (string sub : subCombinations) {
            result.push_back(item + sub);
        }
    }
    return result;
}

vector<string> letterCombinations(string digits) {
    IOS;
    if (digits.empty())
        return {};
    vector<vector<string>> table = {
                    {"a", "b", "c"},
                    {"d", "e", "f"},
                    {"g", "h", "i"},
                    {"j", "k", "l"},
                    {"m", "n", "o"},
                    {"p", "q", "r", "s"},
                    {"t", "u", "v"},
                    {"w", "x", "y", "z"}
            };
    if (digits.size() == 1) return table[digits[0] - '0' - 2];
    vector<string> subCombinations = letterCombinations(digits.substr(1));
    vector<string> result;
    for (string item : table[digits[0] - '0' - 2]) {
        for (string sub : subCombinations) {
            result.push_back(item + sub);
        }
    }
    return result;
}

int main() {
    string digits = "234";
    vector<string> res = letterCombinations(digits);
    return 0;
}