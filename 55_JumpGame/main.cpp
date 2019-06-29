#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

bool canJump(vector<int> &nums) {
    int laststep = nums.size() - 1;
    for (int i = laststep; i >= 0; --i) {
        if (i + nums[i] >= laststep) {
            laststep = i;
        }
    }
    return laststep == 0;
}

int main() {
    vector<int> a = {2, 3, 1, 1, 4};
    cout << canJump(a);
    return 0;
}