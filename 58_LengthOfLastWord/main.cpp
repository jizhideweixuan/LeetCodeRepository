#include <iostream>

using namespace std;

int lengthOfLastWord(string s);

static auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int lengthOfLastWord(string s) {
    int len = 0;
    int end = s.size() - 1;
    for (int i = end; i > -1; --i) {
        const char ch = s[i];
        if (ch != 32) {
            end = i;
            break;
        }
    }
    for (int i = end; i > -1; --i) {
        const char ch = s[i];
        if (ch != 32) {
            ++len;
        } else {
            break;
        }
    }
    return len;
}

int main() {
    string s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}