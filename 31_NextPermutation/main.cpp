#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &nums);

void reverse(vector<int> &nums, int left);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

void nextPermutation(vector<int> &nums) {
    if (nums.size() < 2)
        return;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            reverse(nums, i + 1);
            return;
        }
    }
    reverse(nums, 0);
}

void reverse(vector<int> &nums, int left) {
    int right = nums.size() - 1;
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

int main() {
    vector<int> a = {1, 3, 2};
    nextPermutation(a);
    return 0;
}