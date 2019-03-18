#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

int removeDuplicates(vector<int> &nums) {
    int count = 0;
    vector<int>::iterator it;
    for (it = nums.begin(); it != nums.end(); it++) {
        if (count == 0 || *it != nums[count - 1])
            nums[count++] = *it;
    }
    return count;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << removeDuplicates(nums) << std::endl;
    return 0;
}