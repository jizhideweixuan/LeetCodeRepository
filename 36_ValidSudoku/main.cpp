#include <iostream>
#include <vector>
#include <map>

using namespace std;
static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

struct point {
    int x;
    int y;

    point(int X, int Y) : x(X), y(Y) {}
};

int in_same_subbox(point a, point b) {
    if (a.x / 3 == b.x / 3 && a.y / 3 == b.y / 3) return 1;
    else return 0;
}

bool isValidSudoku(vector<vector<char>> &board) {
    map<char, vector<point> > mp;
    char cur;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cur = board[i][j];
            if (cur == '.')
                continue;
            // 记录新数字
            if (!mp.count(cur)) {
                vector<point> pit;
                pit.push_back(point(i, j));
                mp[cur] = pit;
            } else {
                // 已出现的数字则检查合法性
                vector<point>::iterator t;
                for (t = mp[cur].begin(); t != mp[cur].end(); t++)
                    if ((*t).x == i || (*t).y == j || in_same_subbox(*t, point(i, j)))
                        return 0;
                mp[cur].push_back(point(i, j));
            }
        }
    }
    return 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}