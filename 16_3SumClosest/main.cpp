#include <iostream>
#include <vector>

using namespace std;

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

void QSort(vector<int> &nums, int low, int high);

int threeSumClosest(vector<int> &nums, int target);

void QSort(vector<int> &nums, int low, int high) {
    if (low > high)
        return;
    int begin = low;
    int end = high;
    int key = nums[begin];
    while (begin < end) {
        while (begin < end && nums[end] >= key)
            end--;
        nums[begin] = nums[end];
        while (begin < end && nums[begin] <= key)
            begin++;
        nums[end] = nums[begin];
    }
    nums[begin] = key;
    QSort(nums, low, begin - 1);
    QSort(nums, begin + 1, high);
}

int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3)
        return 0;
    QSort(nums, 0, nums.size() - 1);
    int low = 0;
    int mid = 0;
    int high = 0;
    int sum = 0;
    int closeSum = nums[0] + nums[1] + nums[2];
    for (low; low < nums.size() - 2; low++) {
        //跳过重复的低位
        mid = low + 1;
        high = nums.size() - 1;
        while (mid < high) {
            sum = nums[low] + nums[mid] + nums[high];
            if (abs(target - sum) < abs(target - closeSum)) {
                closeSum = sum;
                if (closeSum == target)
                    return closeSum;
            }
            if (sum - target > 0)
                high--;
            else
                mid++;
        }
    }
    return closeSum;
}

int main() {
    vector<int> nums = {1, 1, 0, -100};
    std::cout << threeSumClosest(nums, 1) << std::endl;
    return 0;
}