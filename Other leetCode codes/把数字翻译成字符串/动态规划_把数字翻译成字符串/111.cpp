#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution{
public:
	int getMaxMatch(int N,int M){
		int x = 0;
		if (N > M)//  M��0��N��1=======������M>N    M-N ��0     N��01
			getMaxMatch(M, N);
		if (M - N > N)
			return N;//��M-N  >  N������N,����˵����N��01ȴ�Ҳ���������Ҫ��N��0��1���ճ�һ�������˵�Ҫ��
		else{
			do{
				x++;
			} while (M - N + 2 * x < N - x);//�ұ߼���һ��01����߾ͻ�����һ�����֡�
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