#include <iostream>
#include <vector>

using namespace std;

int getStr(string haystack, string needle);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int getStr(string haystack, string needle) {
    if (needle.empty()) return 0;

    //获取next数组
    vector<int> pi(needle.size(), 0);
    for (int i = 1, k = 0; i < needle.size(); i++) {
        while (k && needle[k] != needle[i])
            k = pi[k - 1];
        if (needle[k] == needle[i])
            k++;
        pi[i] = k;
    }

    for (int i = 0, k = 0; i < haystack.size(); ++i) {
        while (k && needle[k] != haystack[i])
            k = pi[k - 1];
        if (needle[k] == haystack[i])
            k++;
        if (k == needle.size())
            return i - k + 1;
    }

    return -1;
}

// Driver program to test above function
int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    cout << getStr(txt, pat);
    return 0;
}