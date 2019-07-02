#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution{
public:
	int getMaxMatch(int N,int M){
		int x = 0;
		if (N > M)//  M个0，N个1=======》假设M>N    M-N 个0     N个01
			getMaxMatch(M, N);
		if (M - N > N)
			return N;//若M-N  >  N，返回N,否则说明有N个01却找不到至少需要的N个0或1来凑成一队三个人的要求。
		else{
			do{
				x++;
			} while (M - N + 2 * x < N - x);//右边减少一个01，左边就会增加一对数字。
			return N - x;
		}
		
	}
};

int main(){
	Solution s;
	int N = 15;
	int M = 16;
	int ret = s.getMaxMatch(N, M);
	cout << ret << endl;
	system("pause");
	return 0;
}