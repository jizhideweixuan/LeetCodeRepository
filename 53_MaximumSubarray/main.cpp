#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int res = INT_MIN;
    int win_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (win_sum < 0) {
            win_sum = nums[i];
        } else {
            win_sum += nums[i];
        }
        res = max(res, win_sum);
    }
    return res;
}

int main() {
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(a);
    return 0;
}