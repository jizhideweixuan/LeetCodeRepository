#include <iostream>
#include <vector>
using namespace std;

bool isValid(string s);

static auto io_sync_off = []() {
    //不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
    std::ios::sync_with_stdio(false);
    //解除std::cin和std::cout之间的绑定
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

bool isValid(string s) {
    vector<char> v;
    for (char x : s){
        switch(x){
            case '(':
                v.push_back(x);
                break;
            case '{':
                v.push_back(x);
                break;
            case '[':
                v.push_back(x);
                break;
            case ')':
                if(!v.empty() && *(v.end()-1)=='(') {
                    v.pop_back();
                    break;
                }
                else
                    return false;
            case '}':
                if(!v.empty() && *(v.end()-1)=='{'){
                    v.pop_back();
                    break;
                }
                else
                    return false;
            case ']':
                if(!v.empty() && *(v.end()-1)=='['){
                    v.pop_back();
                    break;
                }
                else
                    return false;
        }
    }
    if(v.empty())
        return true;
    else
        return false;
}

int main() {
    std::cout << isValid("()[]{}")<< std::endl;
    std::cout << isValid("()")<< std::endl;
    std::cout << isValid("}")<< std::endl;
    return 0;
}