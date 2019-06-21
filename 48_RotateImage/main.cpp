#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

void rotate(vector<vector<int>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return;
    }
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = tmp;
        }
    }
}

int main() {
    vector<vector<int>> a = {
            {5,  1,  9,  11},
            {2,  4,  8,  10},
            {13, 3,  6,  7},
            {15, 14, 12, 16}
    };
    rotate(a);
    return 0;
}