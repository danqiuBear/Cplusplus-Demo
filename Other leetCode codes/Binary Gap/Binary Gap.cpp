#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	//首先，给定的数字是十进制的，因此需要一定的方法将其转化为二进制的形式。
	//对于这道题，当我们在按位转换二进制时，依次对两个1之间的最大的值进行记录。
	//counter是-32，是因为N可能会很大，因此取counter为-32.
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