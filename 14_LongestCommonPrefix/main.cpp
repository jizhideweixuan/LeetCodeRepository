#include <iostream>
#include <vector>
using namespace std;

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

string longestCommonPrefix(vector<string> &strs) {
    string res = "";
    string world;
    string nextWorld;
    //两个字符串相同开头的长度
    unsigned int preLength;
    if (strs.empty())
        return "";
    else if (strs[0] == "")
        return "";
    else if (strs.size() == 1)
        return strs[0];
    world = strs[0];
    preLength = strs[0].size();
    for (vector<string>::iterator itr = strs.begin() + 1; itr != strs.end(); itr++) {
        nextWorld = *itr;
        //相同长度和下一个字符串长度,取较小值
        preLength = min(preLength, (unsigned int) nextWorld.size());
        //找出两个字符串相同开头的长度
        for (int j = 0; j < preLength; ++j) {
            if (world[j] != nextWorld[j]) {
                preLength = j;
                break;
            }
        }
    }
    return world.substr(0, preLength);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}