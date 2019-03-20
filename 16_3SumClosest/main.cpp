#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

#include <iostream>
#include <vector>

using namespace std;

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
    IOS;
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