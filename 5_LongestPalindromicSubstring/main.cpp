#include<iostream>
using namespace std;

string longestPalindrome(string s);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    return 0;
}();


//从某个字符为中心，左右验证。用这个方法遍历所有的字符
string longestPalindrome(string s) {
    string result="";
    if(s.size() == 0)
        return result;
    //寻找奇数长的回文
    for(int i=0; i<=s.length()-1; i++){
        int j=i, k=i;
        string tmp = "";
        while( j>=0 && k<= s.length()-1 && s[j] == s[k] ){
            j--;
            k++;
        }
        if(j!=k)
            tmp = s.substr(j+1, k-j-1);
        else
            tmp+=s[i];
        if(tmp.size() >= result.length())
            result = tmp;
    }
    //寻找偶数长的回文
    for(int i=0, j=1; j<=s.length()-1; i++, j++){
        int m=i, n=j;
        string tmp = "";
        while( m>=0 && n<= s.length()-1 && s[m] == s[n] ){
            m--;
            n++;
        }
        if(n-m !=1)
            tmp = s.substr(m+1, n-m-1);

        if(tmp.size() >= result.length())
            result = tmp;
    }

    return result;
}

int main() {
    cout << longestPalindrome("babad");
    return 0;
}