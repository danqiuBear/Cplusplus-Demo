#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	/*
	硬币找零问题，我们在贪心算法那一节中讲过一次。我们今天来看一个更新的硬币找零问题。假设我们有几种不同
	币值的硬币v1， v2，...vn,（单位是元）。如果我们要支付w元，求最少需要多少个硬币。比如，我们有三种不同的
	硬币，1元， 3元， 5元，我们要支付9元，最少需要3个硬币（3个3元的硬币）

	可以看做爬阶梯问题，分别可以走1.3.5步，怎么最少走到9步，动态转移方程为f(9)=1+min(f(8),f(6),f(4))
	*/
	//爬阶梯解决法
	//@coins:不同数额的硬币
	//@sum:需要支付的总额
	int minCoinNum1(const vector<int> coins, int sum){
		int n = coins.size();
		return minCoinNum1(coins, sum, n);	
	}
    //动态规划解决法  状态转移表
	// m为最少需要的硬币的个数 = 币值组合的总和/最小硬币的数额
	//states[i][j]代表 i+1个硬币组合的可能的币值为j
	//此题的核心是把状态转移表画出来！！！！
	int minCoinNumDP1(vector<int> coins, int sum){
		sort(coins.begin(), coins.end());
		int n = coins.size();
		int m = sum / coins[0];
		vector<vector<int>> states(m, vector<int>(sum + 1, -1));
		for (int i = 0; i < n; ++i){//初始化states的第一行
			states[0][coins[i]] = coins[i];
		}
		for (int i = 1; i < m; ++i){
			for (int j = 0; j <= sum; ++j){
				if (states[i - 1][j] != -1){
					for (int k : coins){
						//若第i+1枚加上的是第k枚硬币，但是加上后超出总和，则跳出找第i枚硬币的循环，
						//因为后面的硬币数额比前面的大,继续找的话也会超出题目所需的总和
						if (states[i - 1][j] + k > sum) break;
						states[i][j + k] = states[i - 1][j] + k;
						//找到了最小枚数的硬币组合，将其打印出来
						if (states[i][j + k] == sum) {
							int tmp = sum;
							//从后往前找到一组符合组合条件的硬币数额，打印出来
							//p记录现在正在查询的是states的第几行
							for (int p = i; p >= 1; p--){
								for (int v: coins){
									//减去当前行的某枚硬币币值后，币值总和在上一行（p-1)存在。
									if (states[p - 1][tmp - v] != -1){
										tmp = tmp - v;
										cout << v << " ";
										break;//一旦找到上一个硬币，就break，继续找上上个硬币。
									}
								}
							}
							cout << tmp << endl;
							return i + 1;
						}
					}
				}
			}
		}
		return -1;//若找不到这样的组合，则返回-1；
	}
	//状态转移方程
	//min_count[i] = min(min_count[j] + 1) j < i
	int minCoinNumDP2(vector<int> coins, int sum){
		vector<int> min_count(sum + 1, INT_MAX);
		min_count[0] = 0;
		for (int i = 1; i <= sum; ++i){
			for (int j = 0; j <= i - 1; ++j){
				for (int v : coins){
					if ((j + v == i) && (min_count[i] > min_count[j])){//能凑齐且最小
						min_count[i] = min_count[j] + 1;
					}
				}
			}
		}
		return min_count[sum];
	}
private:
	int minCoinNum1(const vector<int> coins, int sum, int n){
		int min_count = sum;//min_count 最大不超过sum.
		if (sum == 0) return 0;
		if (sum < 0) return INT_MAX;//sum<0说明此组合不符合要求，返回一个最大整数
		int i = n-1;
		while ( i>=0 ){
			min_count = min(minCoinNum1(coins, sum - coins[i], n), min_count);
			--i;
		}
		return min_count + 1;//最少需要支付的硬币数目
	}
};

int main06(){
	Solution s;
	vector<int> coins = { 1, 3, 5 };
	int sum = 19;
	int min_coin_num1 = s.minCoinNum1(coins, sum);
	int min_coin_num2 = s.minCoinNumDP1(coins, sum);
	int min_coin_num3 = s.minCoinNumDP2(coins, sum);
	cout << "min_coin_num1: " << min_coin_num1 << endl;
	cout << "min_coin_num2: " << min_coin_num2 << endl;
	cout << "min_coin_num3: " << min_coin_num3 << endl;
	system("pause");
	return 0;
}