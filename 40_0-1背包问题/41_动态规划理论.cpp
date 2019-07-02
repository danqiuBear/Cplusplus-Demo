#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	//1、基础回溯算法 minDistBacktracing(0,0,0, minDist, w, n)
	//画出递归树图可以发现存在重复计算节点问题
	int minDistBT(const vector<vector<int>> w){
		int minDist = INT_MAX;
		int n = w.size();
		return minDistBT(0, 0, 0, minDist, w, n);
	}
	//2、动态规划, 状态转移表法
	//states[i][j]表示从起点到（i,j)位置的最短路径
	//states[i][j] = min(states[i][j - 1], states[i - 1][j]) + w[i][j];
	int minDistDP1(const vector<vector<int>> w){
		int n = w.size();
		vector<vector<int>> states(n, vector<int>(n, 0));
		states[0][0] = w[0][0];
		for (int j = 1; j < n; ++j){
			states[0][j] = states[0][j - 1] + w[0][j];//初始化第一行的状态值
		}
		for (int i = 1; i < n; ++i){
			states[i][0] = states[i - 1][0] + w[i][0];//初始化第一列的状态值
		}
		for (int i = 1; i < n; ++i){
			for (int j = 1; j < n; ++j){
				states[i][j] = min(states[i][j - 1], states[i - 1][j]) + w[i][j];
			}
		}
		return states[n - 1][n - 1];
	}
	//3、状态转移方程
	//递归+备忘录法
	//min_dist(i,j) = w[i][j] + min(min_dist(i,j-1), min_dist(i-1,j))
	int minDistDP2(const vector<vector<int>> w){
		int n = w.size();
		vector<vector<int>> mem(n, vector<int>(n, 0));
		return minDistDP2(n - 1, n - 1, w, mem);

	}
private:
	int minDistBT(int i, int j, int dist, int& minDist, const vector<vector<int>> w, int n){
		if (i == n - 1){//最后一行的话只能往右走到底
			for (int k = j ; k <= n - 1; ++k){
				dist += w[i][k];
			}
			return dist;
		}
		if (j == n - 1){//最后一列只能往下走到底
			for (int k = i ; k <= n - 1; ++k){
				dist += w[k][j];
			}
			return dist;
		}
		minDist = min(minDistBT(i + 1, j, dist + w[i][j], minDist, w, n), minDistBT(i, j + 1, dist + w[i][j], minDist, w, n));
		return minDist;
	}
	// 3、状态转移方程
	//递归+备忘录法
	//min_dist(i,j) = w[i][j] + min(min_dist(i,j-1), min_dist(i-1,j))
	int minDistDP2(int i, int j, const vector<vector<int>> w, vector<vector<int>>& mem){
		if (i == 0 && j == 0){
			return w[0][0];
		}
		if (mem[i][j] > 0) return mem[i][j];
		int min1 = INT_MAX;
		if (j - 1 >= 0){
			min1 = minDistDP2(i, j - 1, w, mem);
		}
		int min2 = INT_MAX;
		if (i - 1 >= 0){
			min2 = minDistDP2(i - 1, j, w, mem);
		}
		mem[i][j] = w[i][j] + min(min1, min2);
		return mem[i][j];
	}
};

int main05(){
	Solution s;
	vector<vector<int>> square1 = { { 1, 3 }, { 2, 1 } };//4
	vector<vector<int>> square2 = { { 1, 1, 1 }, { 1, 2, 1 }, { 2, 1, 1 } };//5
	vector<vector<int>> square3 = { { 1, 3, 5, 9 }, { 2, 1, 3, 4 }, { 5, 2, 6, 7 }, { 6, 8, 4, 3 } };//19
	int minDist_BT = s.minDistBT(square3);
	int minDist_DP1 = s.minDistDP1(square3);
	int minDist_DP2 = s.minDistDP2(square3);
	cout << "minDist_BT: " << minDist_BT << endl;
	cout << "minDist_DP1: " << minDist_DP1 << endl;
	cout << "minDist_DP2: " << minDist_DP2 << endl;
	system("pause");
	return 0;
}