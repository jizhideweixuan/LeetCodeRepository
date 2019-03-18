#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

int searchInsert(vector<int> &nums, int target) {
    if (nums.empty())
        return 0;
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    std::cout << searchInsert(nums, 7) << std::endl;
    return 0;
}