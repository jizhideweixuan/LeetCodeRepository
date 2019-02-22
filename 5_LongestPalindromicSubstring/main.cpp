#include<iostream>
#include<string>
using namespace std;

string longestPalindrome(string s) {
	string result;
	//窗口实际长度
	unsigned int winSize = s.length();
	//窗口两端游标
	unsigned int low = 0;
	unsigned int high = winSize-1;
    unsigned int r_low = low;
    unsigned int r_high = high;
	while (winSize>1)
	{
		//窗口从最左端开始滑动
		for(unsigned int flag=0;flag<s.length()-winSize+1;flag++)
		{
            r_low = low = flag;
            r_high = high = winSize-1;
			while(low<high)
			{
				if(s[low]!=s[high])
					break;
				else
				{
					low++;
					high--;
				}
			}
			if(low>=high)
			{
				result = s.substr(r_low,r_high+1);
				cout<<result;
				return result;
			}
		}
		//缩小窗口
		winSize --;
	}
	return "";
}

int main(){
	longestPalindrome("abaaaa");
	return 0;
}