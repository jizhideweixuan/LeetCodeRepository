#include <iostream>
#include <vector>
#include <algorithm>

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
    int n = num1.size();
    int m = num2.size();
    string res(n + m, '0');
    for (int i = 0, index1 = n - 1; i < n; i++, index1--) {
        int carry = 0;
        int val1 = num1[index1] - '0';
        for (int j = 0, index2 = m - 1; j < m; j++, index2--) {
            int cur = i + j;
            int tmp = val1 * (num2[index2] - '0') + (res[cur] - '0') + carry;
            res[cur] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        res[i + m] += carry;
    }
    reverse(res.begin(), res.end());
    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;
    return res.substr(i);
}

int main() {
    cout << multiply("123", "456") << endl;
    return 0;
}