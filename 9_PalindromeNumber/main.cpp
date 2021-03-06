﻿#include<iostream>
using namespace std;

bool isPalindrome(int x);

static auto io_sync_off = []() {
	//不再兼容scanf和printf,让std::cin和std::cout不再经过缓冲区
	std::ios::sync_with_stdio(false);
	//解除std::cin和std::cout之间的绑定
	std::cin.tie(nullptr);
	return 0;
}();

bool isPalindrome(int x) {
	int div = 1;//与位数对应的10的倍数
	int low = 0;//最高位
	int high = 0;//最低位
	if (x<0)
		return false;
	while(x/div >= 10)
		div *= 10;
	while(x!=0)
	{
		//取低位
		low = x%10;
		//取高位
		high = x/div;
		if(high!=low)
			return false;
		//去掉最高位和最低位
		x=(x%div)/10;
		//缩小两位
		div /= 100;
	}
	return true;
}

int main(){
	cout<<"input:121 "<<isPalindrome(121)<<endl;
	cout<<"input:-121 "<<isPalindrome(-121)<<endl;
	cout<<"input:1001 "<<isPalindrome(1001)<<endl;
	return 0;
}