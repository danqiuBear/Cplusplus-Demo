#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	//1回溯法
	int lwstBT(const string a, const string b){
		int minDist = INT_MAX;
		return lwstBT(0, 0, 0, minDist,a, b);
	}
	//2动态规划法
	int lwstDP(const string a, const string b){
		int m = a.size();
		int n = b.size();
		vector<vector<int>> minDist(m, vector<int>(n, 0));
		for (int j = 0; j < n; ++j){// 初始化第 0 行:a[0..0] 与 b[0..j]的编辑距离
			if (a[0] == b[j]) minDist[0][j] = j;
			else if (j != 0) minDist[0][j] = minDist[0][j - 1] + 1;
			else minDist[0][j] = 1;
		}
		for (int i = 0; i < m; ++i){// 初始化第 0 列:a[0..i] 与 b[0..0] 的编辑距离
			if (a[i] == b[0]) minDist[i][0] = i;
			else if (i != 0) minDist[i][0] = minDist[i - 1][0] + 1;
			else minDist[i][0] = 1;
		}
		for (int i = 1; i < m; ++i){//按行填表
			for (int j = 1; j < n; ++j){
				if (a[i] == b[j]){
					minDist[i][j] = min(minDist[i - 1][j - 1], 
						                   min(minDist[i-1][j] + 1, minDist[i][j-1] + 1 ));
				}
				else{
					minDist[i][j] = min(minDist[i - 1][j - 1] + 1,
						min(minDist[i - 1][j] + 1, minDist[i][j - 1] + 1));
				}
			}
		}
		return minDist[m - 1][n - 1];
	}
private:
	int lwstBT(int i, int j, int edist, int& minDist,const string a, const string b){
		if (i == a.size() || j == b.size()){
			if (i < a.size()) edist += (a.size() - i);
			if (j < b.size()) edist += (b.size() - j);
			if (edist < minDist) minDist = edist;
			return minDist;
		}
		if (a[i] == b[j]){//两个字符匹配
			return lwstBT(i + 1, j + 1, edist, minDist, a, b);
		}
		else{//两个字符不匹配
			return min(lwstBT(i + 1, j + 1, edist + 1, minDist, a, b),
				min(lwstBT(i + 1, j, edist + 1, minDist, a, b), lwstBT(i, j + 1, edist + 1, minDist, a, b)));
		}
	}
};

int main07(){
	Solution s;
	string a = "mitcmu";
	string b = "mtacnu";
	int minDist1 = s.lwstBT(a, b);
	int minDist2 = s.lwstDP(a, b);
	cout << "minDist1: " << minDist1 << endl;
	cout << "minDist2: " << minDist2 << endl;
	cout << "minDist1: " << minDist1 << endl;
	system("pause");
	return 0;
}