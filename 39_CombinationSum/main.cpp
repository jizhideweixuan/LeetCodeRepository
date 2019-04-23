#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum(vector<int> &candidates, int target);

void backTrack(vector<int> &candidates, int target, int ptr, vector<int> &sub, vector<vector<int>> &res);


static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> sub;
    if (candidates.size() == 0)
        return res;
    sort(candidates.begin(), candidates.end());
    backTrack(candidates, target, 0, sub, res);
    return res;
}

void backTrack(vector<int> &candidates, int target, int ptr, vector<int> &sub, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(sub);
        return;
    }
    for (int i = ptr; i < candidates.size(); i++) {
        int newTarget = target - candidates[i];
        if (newTarget >= 0) {
            sub.push_back(candidates[i]);
            backTrack(candidates, newTarget, i, sub, res);
            sub.pop_back();
        } else
            break;
    }
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> res = combinationSum(candidates, 7);
    return 0;
}