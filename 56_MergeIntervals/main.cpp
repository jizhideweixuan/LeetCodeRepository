#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b) {
        return a.front() < b.front();
    });
    vector<vector<int>> ret;
    for (auto &i:intervals) {
        if (ret.empty() || ret.back()[1] < i[0]) {
            ret.emplace_back(i);
        } else {
            ret.back().back() = max(ret.back()[1], i[1]);
        }
    }
    return ret;
}

int main() {
    vector<vector<int>> a = {{1,  3},
                             {2,  6},
                             {8,  10},
                             {15, 18}};
    vector<vector<int>> b = {{1, 4},
                             {4, 5}};
    vector<vector<int>> ret = merge(b);
    for (size_t i = 0; i < ret.size(); ++i) {
        cout << "(" + to_string(ret[i].front()) + "," + to_string(ret[i].back()) + ") ";
    }
    return 0;
}