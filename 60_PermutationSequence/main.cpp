#include <iostream>
#include <vector>

using namespace std;

string getPermutation(int n, int k);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

string getPermutation(int n, int k) {
    string res = "";
    k = k - 1;
    int factor = 1;
    for (int i = 1; i < n; ++i) {
        factor *= i;
    }
    //vector<int> digits(n, 0);
    vector<int> digits;
    for (int i = 0; i < n; ++i) {
        //digits[i] = i + 1;
        digits.emplace_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        const int index = k / factor;
        vector<int>::iterator it = digits.begin() + index;
        res += digits[index] + 48;
        digits.erase(it);
        k %= factor;
        if (i < n - 1) {
            factor = factor / (n - 1 - i);
        }
    }
    return res;
}

int main() {
    std::cout << getPermutation(3, 3) << std::endl;
    return 0;
}