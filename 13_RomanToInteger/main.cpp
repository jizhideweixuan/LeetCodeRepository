#include <iostream>
using namespace std;

int romanToInt(string s);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

int romanToInt(string s) {
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        switch (s[i]) {
            case 'M':
                res += 1000;
                break;
            case 'D':
                res += 500;
                break;
            case 'C':
                res += 100 * (res >= 500 ? -1 : 1);
                break;
            case 'L':
                res += 50;
                break;
            case 'X':
                res += 10 * (res >= 50 ? -1 : 1);
                break;
            case 'V':
                res += 5;
                break;
            case 'I':
                res += 1 * (res >= 5 ? -1 : 1);
                break;
        }
    }
    return res;
}

int main() {
    cout<<"input: XII output: "<<romanToInt("XII");
    return 0;
}