#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n);

void output(const vector<vector<int>> v);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    if (n <= 0)
        return ans;
    int num = 1;
    int lv = 0;
    while (2 * lv < n) {
        for (int i = lv; i < n - lv; ++i) {
            ans[lv][i] = num++;
        }
        for (int i = lv + 1; i < n - lv; ++i) {
            ans[i][n - lv - 1] = num++;
        }
        for (int i = n - lv - 2; i >= lv; --i) {
            ans[n - lv - 1][i] = num++;
        }
        for (int i = n - lv - 2; i >= lv + 1; --i) {
            ans[i][lv] = num++;
        }
        ++lv;
    }
    return ans;
}

void output(const vector<vector<int>> v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << ",";
        }
        cout << endl;
    }
}

int main() {
    const vector<vector<int>> v = generateMatrix(3);
    output(v);
    return 0;
}