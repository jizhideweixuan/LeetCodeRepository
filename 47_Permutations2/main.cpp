#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> permuteUnique(vector<int> &nums);

void perm(vector<int> num, int level, vector<vector<int>> &res);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.size() == 0) {
        return res;
    }
    sort(nums.begin(), nums.end());
    perm(nums, 0, res);
    return res;
}

void perm(vector<int> num, int level, vector<vector<int>> &res) {
    if (level == num.size()) {
        res.push_back(num);
        return;
    }
    for (int i = level; i < num.size(); i++) {
        bool skip = false;
        for (int j = level; j < i; j++) {
            if (num[j] == num[i]) {
                skip = true;
                break;
            }
        }
        if (skip) {
            continue;
        }
        swap(num[i], num[level]);
        perm(num, level + 1, res);
        swap(num[i], num[level]);
    }
}

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = permuteUnique(nums);
    return 0;
}