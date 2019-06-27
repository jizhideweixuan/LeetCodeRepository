#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    int n = strs.size();
    vector<string> s = strs;
    unordered_map<string, int> order_map;
    for (int i = 0; i < n; ++i) {
        sort(s[i].begin(), s[i].end());
    }
    for (int i = 0; i < n; ++i) {
        if (order_map.find(s[i]) == order_map.end()) {
            res.push_back({strs[i]});
            order_map[s[i]] = res.size() - 1;
        } else {
            res[order_map[s[i]]].push_back(strs[i]);
        }
    }
    return res;
}

int main() {
    vector<string> a = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(a);
    return 0;
}