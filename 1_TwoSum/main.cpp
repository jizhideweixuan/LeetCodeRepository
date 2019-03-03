#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int main() {
    vector<int> nums={2, 7, 11, 15};
    twoSum(nums,9);
    return 0;
}

vector<int> twoSum(vector<int> &nums, int target) {
    map<int,int> mhashmap;
    for(int i=0;i<nums.size();i++){
        if(mhashmap.find(nums[i])!=mhashmap.end()){
            cout<<mhashmap[nums[i]]<<endl;
            cout<<i;
            return vector<int>{mhashmap[nums[i]],i};
        }
        mhashmap[target-nums[i]]=i;
    }
}