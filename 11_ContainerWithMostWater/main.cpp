#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height);

static auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

int maxArea(vector<int> &height) {
    if (height.size() < 2)
        return 0;
    //指向头
    int low = 0;
    //指向尾
    int high = height.size() - 1;
    //面积
    int area = 0;
    //由于面积受到短的制约，由短的一边向长的一边靠拢
    while (low < high) {
        if ((high - low) * min(height[low], height[high]) > area)
            area =(high - low) * min(height[low], height[high]);
        if(height[low]<height[high])
            low++;
        else
            high--;
    }
    return area;
}

int main() {
    vector<int> nums= {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(nums) << std::endl;
    return 0;
}