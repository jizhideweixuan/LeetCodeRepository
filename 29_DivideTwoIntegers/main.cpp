#include <iostream>

using namespace std;

int divide(int dividend, int divisor);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

int divide(int dividend, int divisor) {
    if (dividend == 0)
        return 0;
    if (dividend == 0)
        return INT_MAX;
    else if (divisor == 1)
        return dividend;
    else if (divisor == -1)
        return dividend == INT_MIN?INT_MAX:-dividend;
    const bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
    long left_num = abs((long)dividend);
    long right_num = abs((long)divisor);
    int result = 0;
    while (left_num >= right_num) {
        int multi = 1;
        while (right_num * multi <= (left_num >> 1)) {
            multi = multi << 1;
        }
        result += multi;
        left_num -= right_num * multi;
    }
    return neg ? -result : result;
}

int main() {
    std::cout << divide(7, -3) << std::endl;
    return 0;
}