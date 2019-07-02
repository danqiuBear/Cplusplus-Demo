#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class bag_Problem_upgrade{


public:
	//最基础的回溯算法
	int knapsack1(const vector<int> weight, const vector<int> value, const int w){
		int maxV = INT_MIN; //结果放到maxW中
		int n = weight.size();//物品个数
		return f(0, 0,0, maxV, weight,value, w, n);
	}


	//动态规划  weight:物品重量， n:物品个数， w:背包可承载重量
	int knapsack3(const vector<int> weight, const vector<int> value, const int w){
		int n = weight.size();//物品个数
		vector<vector<int>> states(n, vector<int>(w + 1, -1));
		states[0][0] = 0;
		states[0][weight[0]] = value[0];
		for (int i = 1; i < n; ++i){//动态规划状态转移
			for (int j = 0; j <= w; ++j){//不把第i个物品放入背包
				if (states[i - 1][j] >= 0) states[i][j] = states[i - 1][j];
			}
			for (int j = 0; j <= w-weight[i]; ++j){//把第i个物品放入背包
				if (states[i - 1][j] >= 0 ){
					int v = states[i - 1][j] + value[i];
					if (v > states[i][j + weight[i]]) {
						states[i][j + weight[i]] = v;
					}
				}
			}
		}
		int maxvalue = -1;
		for (int j = 0; j <=w; ++j){//输出结果
			if (states[n - 1][j] > maxvalue) maxvalue  = states[n-1][j];
		}
		return maxvalue;
	}
	//动态规划  weight:物品重量， n:物品个数， w:背包可承载重量
	//用一维数组来表示状态，以节省空间
	int knapsack4(const vector<int> weight, const vector<int> value, const int w){
		int n = weight.size();//物品个数
		vector<int> states(w + 1, -1);
		states[0] = 0;
		states[weight[0]] = value[0];
		for (int i = 1; i < n; ++i){//动态规划状态转移
			//下面一行的j要从大到小处理。如果我们按照j从小到大处理的话，会出现for循环重复计算问题。
			for (int j = w - weight[i]; j >= 0; --j){//把第i个物品放入背包
				if (states[j] >= 0){
					int v = states[j] + value[i];
					if (v > states[j + weight[i]]){
						states[j + weight[i]] = v;
					}
				}
			}
		}
		int maxvalue = -1;
		for (int j = w; j >= 0; --j){//输出结果
			if (states[j] > maxvalue) maxvalue = states[j];
		}
		return maxvalue;
	}
private:
	int f(int i, int cw, int cv, int& maxV, const vector<int> weight, const vector<int> value,const int w, const int n){//条用f(0,0,0)
		if (cw == w || i == n){//cw==w表示装满了， i==n表示物品都考察完了
			if (cv > maxV) maxV = cv;
			return maxV;
		}
		maxV = max(maxV, f(i + 1, cw, cv ,maxV, weight, value, w, n));//选择不装第i个物品
		if (cw + weight[i] <= w){//选择装第i个物品
			maxV = max(maxV, f(i + 1, cw + weight[i], cv+value[i], maxV, weight, value, w, n));
		}
		return maxV;
	}
};
int main02(){
	bag_Problem_upgrade s;
	int w = 9;//背包承受的最大重量
	vector<int> weight = { 2, 2, 4, 6, 4 };//物品重量
	vector<int> value = { 3, 4, 8, 9, 6 };//物品的价值
	int largest_value_in_bag = s.knapsack4(weight,value,w);
	cout << largest_value_in_bag << endl;
	system("pause");
	return 0;
}
