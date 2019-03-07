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
    if (needle.empty())
        return 0;

    //获取next数组
    vector<int> pi(needle.size(), 0);
    for (int i = 1, k = 0; i < needle.size(); i++) {
        //当k!=0且needle[k] != needle[i]
        while (k && needle[k] != needle[i])
            // k = next[k-1]
            k = pi[k - 1];
        //若最后needle[k] == needle[i],next[i] = ++k 否则 next[i] = 0
        if (needle[k] == needle[i])
            k++;
        pi[i] = k;
    }

    for (int i = 0, k = 0; i < haystack.size(); ++i) {
        //字符不同,i++,k=next[k]
        while (k && needle[k] != haystack[i])
            k = pi[k - 1];
        //字符相同,下一轮k++.i++
        if (needle[k] == haystack[i])
            k++;
        //k走到头,匹配成功
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