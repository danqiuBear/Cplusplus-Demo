
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class bag_Problem{
public:
	//最基础的回溯算法
	int knapsack1(const vector<int> weight, const int w){
		int maxW = INT_MIN; //结果放到maxW中
		int n = weight.size();//物品个数
		return f(0, 0, maxW, weight, w, n);
	}
	//备忘录+回溯
	int knapsack2(const vector<int> weight, const int w){
		int maxW = INT_MIN; //结果放到maxW中
		int n = weight.size();//物品个数
		vector<vector<bool>> states(n, vector<bool>(w + 1, false));
		return f_mem(0, 0, maxW, weight, w, n, states);
	}

	//动态规划  weight:物品重量， n:物品个数， w:背包可承载重量
	int knapsack3(const vector<int> weight, const int w){
		int maxW = INT_MIN; //结果放到maxW中
		int n = weight.size();//物品个数
		vector<vector<bool>> states(n, vector<bool>(w + 1, false));
		states[0][0] = true;
		states[0][weight[0]] = true;
		for (int i = 1; i < n; ++i){//动态规划状态转移
			for (int j = 0; j <= w; ++j){//不把第i个物品放入背包
				if (states[i - 1][j]) states[i][j] = true;
			}
			for (int j = 0; j <= w; ++j){//把第i个物品放入背包
				if (states[i - 1][j] && (j + weight[i] <= w)){
					states[i][j + weight[i]] = true;
				}
			}
		}
		for (int j = w; j >= 0; --j){//输出结果
			if (states[n - 1][j]) return j;
		}
		return 0;
	}
	//动态规划  weight:物品重量， n:物品个数， w:背包可承载重量
	//用一维数组来表示状态，以节省空间
	int knapsack4(const vector<int> weight, const int w){
		int maxW = INT_MIN; //结果放到maxW中
		int n = weight.size();//物品个数
		vector<bool> states (w + 1, false);
		states[0] = true;
		states[weight[0]] = true;
		for (int i = 1; i < n; ++i){//动态规划状态转移
			//下面一行的j要从大到小处理。如果我们按照j从小到大处理的话，会出现for循环重复计算问题。
			for (int j = w - weight[i]; j >= 0; --j){//把第i个物品放入背包
				if (states[j]) states[j + weight[i]] = true;
			}
		}
		for (int j = w; j >= 0; --j){//输出结果
			if (states[j]) return j;
		}
		return 0;
	}

private:	
	int f(int i, int cw, int& maxW, const vector<int> weight, const int w,  const int n){//条用f(0,0)
		if (cw == w || i == n){//cw==w表示装满了， i==n表示物品都考察完了
			if (cw > maxW) maxW = cw;
			return maxW;
		}
		maxW = max(maxW, f(i + 1, cw, maxW, weight, w, n));//选择不装第i个物品
		if (cw + weight[i] <= w){//选择装第i个物品
			maxW = max(maxW, f(i + 1, cw + weight[i], maxW, weight,w,  n));
		}
		return maxW;
	}
	//备忘录+回溯
	int f_mem(int i, int cw, int& maxW, const vector<int> weight, const int w, const int n, vector<vector<bool>>& states){//条用f(0,0)
		if (cw == w || i == n){//cw==w表示装满了， i==n表示物品都考察完了
			if (cw > maxW) maxW = cw;
			return maxW;
		}
		if (states[i][cw]) return maxW;//重复状态
		states[i][cw] = true;//记录（i,cw)这个状态
		maxW = max(maxW, f_mem(i + 1, cw, maxW, weight, w, n, states));//选择不装第i个物品
		if (cw + weight[i] <= w ){//选择装第i个物品
			maxW = max(maxW, f_mem(i + 1, cw + weight[i], maxW, weight, w, n, states));
		}
		return maxW;
	}
};

int main01(){
	bag_Problem s;
	int w = 9;//背包承受的最大重量
	vector<int> weight = { 2, 2, 4, 6, 4 };//物品重量
	
	int largest_weight_in_bag = s.knapsack4(weight, w);
	cout << largest_weight_in_bag << endl;
	system("pause");
	return 0;
}