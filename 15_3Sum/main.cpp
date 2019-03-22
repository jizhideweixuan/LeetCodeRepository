#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums);

void QSort(vector<int> &nums, int low, int high);

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

vector<vector<int>> threeSum(vector<int> &nums) {
    IOS;
    if (nums.size() < 3)
        return {};
    int low = 0;
    int high = 0;
    int mid = 0;
    int sum = 0;
    vector<vector<int>> res;
    vector<int> tmp(3);
    //快排
    QSort(nums, 0, nums.size() - 1);
    //遍历low
    for (low; low < nums.size() - 2; low++) {
        //跳过重复的低位
        if (low == 0 || nums[low] > nums[low - 1]) {
            mid = low + 1;
            high = nums.size() - 1;
            while (mid < high) {
                sum = nums[low] + nums[mid] + nums[high];
                if (sum == 0) {
                    tmp = {nums[low], nums[mid], nums[high]};
                    res.push_back(tmp);
                    //跳过重复值
                    while (mid < high && nums[mid] == nums[mid + 1]) mid++;
                    while (mid < high && nums[high] == nums[high - 1]) high--;
                    mid++; high--;
                } else if (sum > 0)
                    //高位过大
                    high--;
                else
                    //低位过小
                    mid++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    return 0;
}