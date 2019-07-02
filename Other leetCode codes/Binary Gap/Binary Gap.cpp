#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	//���ȣ�������������ʮ���Ƶģ������Ҫһ���ķ�������ת��Ϊ�����Ƶ���ʽ��
	//��������⣬�������ڰ�λת��������ʱ�����ζ�����1֮�������ֵ���м�¼��
	//counter��-32������ΪN���ܻ�ܴ����ȡcounterΪ-32.
	int binaryGap(int N) {
		int res = 0, counter = -32;
		while (N)
		{
			if (N & 1)
			{
				res = max(res, counter);
				counter = 0;
			}
			N = N >> 1;
			counter++;
		}
		return res;
	}
	vector<int> intobinary(int interger, vector<int> &bin_path){
		if (interger == 1){
			bin_path.insert(bin_path.begin(), interger);
			return bin_path;
		}
		bin_path.insert(bin_path.begin(), interger % 2);
		return intobinary(interger / 2, bin_path);
	}
private:

};

int main(){
	Solution s;
	vector<int> bin;
	s.intobinary(9, bin);
	for (int i = 0; i < bin.size(); ++i){
		cout << bin[i] << ' ';
	}
	cout << endl;
	system("pause");
}