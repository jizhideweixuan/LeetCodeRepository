#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
	//输出
	long result = 0;
	//余数
	int num = 0;
	while (x!=0)
	{
		num = x%10;
		x = x/10;
		result = result * 10 + num;
	}
	if(result>INT_MAX ||result<INT_MIN)
	{
		result = 0;
	}
	return result;
}

int main(){
	cout<<"input123: "<<reverse(123)<<endl;
	cout<<"output-321: "<<reverse(-321)<<endl;
	return 0;
}