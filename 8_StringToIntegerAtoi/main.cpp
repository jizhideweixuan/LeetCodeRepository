#include <iostream>

using namespace std;

int myAtoi(string str);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

int myAtoi(string str) {
    const int maxDiv = INT_MAX / 10;
    //串长
    int n = str.length();
    //返回值
    int res = 0;
    //当前读取数字
    int num = 0;
    //当前位
    int i = 0;
    //符号位
    int sign = 1;
    while (i < n && i < isspace(str[i]))
        i++;
    if (i < n && str[i] == '+')
        i++;
    else if (i < n && str[i] == '-') {
        sign = -1;
        i++;
    }
    while (i < n && isdigit(str[i])) {
        //str[i]与'0'的ASCII码差值
        num = str[i] - '0';
        if (res > maxDiv || res == maxDiv && num >= 8)
            return sign == 1 ? INT_MAX : INT_MIN;
        res = res * 10 + num;
        i++;
    }
    return sign * res;
}

int main() {
    std::cout << myAtoi("-2147483647") << std::endl;
    return 0;
}