#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();

int main() {
    cout << lengthOfLongestSubstring("abcabcbb");
    return 0;
}

int lengthOfLongestSubstring(string s) {
    map<char, int> mhashmap;
    map<char, int>::iterator iter;
    //子串起始位置
    int start = 0;
    //最大子串长
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        //在哈希表中查s[i]
        iter = mhashmap.find(s[i]);
        //若找到重复字母，返回当前位置，在元素重复位置和起始位置中选择最大值作为新的起始位置
        start = max(start, iter != mhashmap.end() ? iter->second + 1 : 0);
        //在最长子串和起始位置中选择最大值作为新的最长子串
        ans = max(ans,i-start+1);
        mhashmap[s[i]]=i;
    }
    return ans;
}
