#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

string multiply(string num1, string num2) {
    if (num1 == "" || num2 == "") return "";
    if (num1 == "0" || num2 == "0") return "0";
    vector<int> res(num1.size() + num2.size());
    int n = num1.size();
    int m = num2.size();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            res[n + m - i - j - 2] += (num1[i] - '0') * (num2[j] - '0');
            res[n + m - i - j - 1] += res[n + m - i - j - 2] / 10;
            res[n + m - i - j - 2] %= 10;
        }
    }
    string str = "";
    for (int i = n + m - 1; i >= 0; i--) {
        if (res[i] != 0) {
            for (int j = i; j >= 0; j--) {
                str += to_string(res[j]);
            }
            return str;
        }
    }
    return "0";
}

int main() {
    cout << multiply("123", "456") << endl;
    return 0;
}