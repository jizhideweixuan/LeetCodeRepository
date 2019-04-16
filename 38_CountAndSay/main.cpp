#include <iostream>
#include <vector>

using namespace std;

string count(string last_str);

string countAndSay(int n);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

string count(string last_str) {
    int p = 0, count = 0;
    string ans = "";
    while (p < last_str.size()) {
        char temp = last_str[p];
        count = 1;
        while (p + 1 < last_str.size() && last_str[p] == last_str[p + 1]) {
            count++;
            p++;
        }
        p++;
        ans += '0' + count;
        ans += temp;
    }
    return ans;
}

string countAndSay(int n) {
    vector<string> strs(n + 1);
    strs[1] = "1";
    for (int i = 2; i <= n; ++i) {
        strs[i] = count(strs[i - 1]);
    }
    return strs[n];
}

int main() {
    std::cout << countAndSay(4) << std::endl;
    return 0;
}