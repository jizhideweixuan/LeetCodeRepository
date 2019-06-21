#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    if (strs.size() == 0) {
        return res;
    }
    map<string, vector<string>> order_map;
    for (int i = 0; i < strs.size(); ++i) {
        int count[26] = {};
        for (int j = 0; j < strs[i].size(); ++j) {
            count[strs[i][j] - 'a']++;
        }
        string row_sum = "";
        for (int k = 0; k < 26; ++k) {
            row_sum += "#"+to_string(count[k]);
        }
        vector<string> &v = order_map[row_sum];
        if (v.size()==0){
            order_map[row_sum] = vector<string>{strs[i]};
        } else{
            v.push_back(strs[i]);
        }
    }
    for (map<string, vector<string>> ::iterator it = order_map.begin(); it != order_map.end(); it++)
    {
        res.push_back(order_map[it->first]);
    }
    return res;
}

int main() {
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(a);
    return 0;
}