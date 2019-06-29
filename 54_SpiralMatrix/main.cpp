#include <iostream>
#include <vector>

using namespace std;

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    if (matrix.size()==0){
        return res;
    }
    int c1 = 0;
    int c2 = matrix[0].size() - 1;
    int r1 = 0;
    int r2 = matrix.size() - 1;
    while (r1 <= r2 && c1 <= c2) {
        for (int i = c1; i <= c2; ++i) {
            res.push_back(matrix[r1][i]);
        }
        for (int i = r1 + 1; i <= r2; ++i) {
            res.push_back(matrix[i][c2]);
        }
        if (r1 < r2 && c1 < c2) {
            for (int i = c2 - 1; i > c1; --i) {
                res.push_back(matrix[r2][i]);
            }
            for (int i = r2; i > r1; --i) {
                res.push_back(matrix[i][c1]);
            }
        }
        r1++;
        r2--;
        c1++;
        c2--;
    }
    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}