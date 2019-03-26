
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

vector<vector<int>> fourSum(vector<int> &nums, int target);

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


vector<vector<int>> fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4)
        return {};
    QSort(nums, 0, nums.size() - 1);
    vector<vector<int>> res;
    for (int low = 0; low < nums.size() - 3; low++) {
        //跳过重复位
        if (low == 0 || nums[low] > nums[low - 1]) {
            int target3 = target - nums[low];
            for (int mid1 = low + 1; mid1 < nums.size() - 2; mid1++) {
                if (mid1 == low + 1 || nums[mid1] > nums[mid1 - 1]) {
                    int target2 = target3 - nums[mid1];
                    int mid2 = mid1 + 1;
                    int high = nums.size() - 1;
                    while (mid2 < high) {
                        if (nums[mid2] + nums[high] == target2) {
                            res.push_back({nums[low], nums[mid1], nums[mid2], nums[high]});
                            while (mid2 < high && nums[mid2] == nums[mid2 + 1]) mid2++;
                            while (mid2 < high && nums[high] == nums[high - 1]) high--;
                            mid2++; high--;
                        } else if (nums[mid2] + nums[high] < target2) mid2++;

                        else high--;
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1,0,-5,-2,-2,-4,0,1,-2};
    vector<vector<int>> res = fourSum(nums, -9);
    return 0;
}