#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

int removeElement(vector<int> &nums, int val) {
    int high = nums.size();
    int low = 0;
    while (low < high) {
        if (nums[low] == val) {
            nums[low] = nums[high-1];
            high--;
        } else {
            low++;
        }
    }
    return high;
}

int main() {
    vector<int> nums1 = {3, 2, 2, 3};
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    std::cout << removeElement(nums1, 3) << std::endl;
    std::cout << removeElement(nums2, 2) << std::endl;
    return 0;
}