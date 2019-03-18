/*
 * a,b分别为公鸡母鸡数量，c为小鸡数量除以3
 * a+b+3c=100
 * 5a+2b+c=100
 * num=100-c*3
 * mon=100-c
 * 消去b得出 a=(mon-2*num)/3
 * b=num-a;
 * 限制AB的范围，避免出现负数
 */
#include <iostream>

using namespace std;

void fun1();
void fun2();

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();


void fun1() {
    int a, b, c, num, mon;
    for (c = 0; c <= 33; c++) {
        num = 100 - 3 * c;
        mon = 100 - c;
        if ((mon - 2 * num) % 3 == 0)                        //AB满足方程组时，输出正确答案
        {
            a = (mon - 2 * num) / 3;
            if (a < 0 || a > 16) continue;
            b = num - a;
            if (b < 0 || b > 40) continue;
            cout << "分配:公鸡" << a << "只,母鸡" << b << "只,小鸡" << 3 * c << "只" << endl;
        }
    }
}

//公鸡a 母鸡b 小鸡c
void fun2() {
    int a, b, c;
    for (a = 0; a <= 16; a++) {
        for (b = 0; b <= 40; b++) {
            c = 100 - a - b;
            if (!(c % 3) && c / 3 + b * 2 + a * 5 == 100) {
                cout << "分配:公鸡" << a << "只,母鸡" << b << "只,小鸡" << c << "只" << endl;
            }
        }
    }
}

int main() {
    cout << "公鸡5元1只，母鸡2元1只，小鸡1元3只，要求计算100元买100只鸡的所有可能组合" << endl;
    cout << "单循环" << endl;
    fun1();
    cout << "双循环" << endl;
    fun2();
    return 0;
}