#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> twoSum(vector<int> &nums, int target);

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