#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum2(vector<int> &candidates, int target);

void backTrack(vector<int> &candidates, int target, int ptr, vector<int> &sub, vector<vector<int>> &res);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    if (candidates.size() == 0)
        return res;
    vector<int> sub;
    sort(candidates.begin(), candidates.end());
    backTrack(candidates, target, 0, sub, res);
    return res;
}

void backTrack(vector<int> &candidates, int target, int ptr, vector<int> &sub, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(sub);
        return;
    }
    vector<int> tmpSub = sub;
    for (int i = ptr; i < candidates.size(); i++) {
        if (i > ptr && candidates[i] == candidates[i - 1]) {
            continue;
        }
        int newTarget = target - candidates[i];
        if (newTarget >= 0) {
            sub.push_back(candidates[i]);
            backTrack(candidates, newTarget, i + 1, sub, res);
            sub.pop_back();
        } else
            break;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}