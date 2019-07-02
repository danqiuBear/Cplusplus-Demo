#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	//items 表示商品价格， n表示商品个数， w表示满减条件， 比如200
	void double11advance(vector<int> items, int w){
		int n = items.size();
		vector<vector<bool>> states(n, vector<bool>(3 * w + 1, false));//超过3倍就没有薅羊毛的价值了
		states[0][0] = true;//第一行要特殊处理
		states[0][items[0]] = true;
		for (int i = 1; i < n; ++i){//动态规划
			for (int j = 0; j <= 3 * w ; ++j){//不购买第i个商品
				if (states[i - 1][j] == true) states[i][j] = states[i - 1][j];
			}
			for (int j = 0; j <= 3 * w  - items[i]; ++j){//购买第i个商品
				if (states[i - 1][j] == true)  states[i][j + items[i]] = true;
			}
		}
		int j;
		for (j = w; j < 3 * w + 1; ++j){
			if (states[n - 1][j]) break;//输出结果大于等于w的最小值
		}
		if (j == -1) return;
		for (int i = n - 1; i >= 1; --i){//i 表示二维数组中的行， j表示列
			if (j - items[i] >= 0 && states[i - 1][j - items[i]]){
				cout << items[i] << " ";
				j = j - items[i];
			}//else 没有购买这个商品， j不变
		}
		if (j != 0) cout << items[0] << endl;
	}
	/*
	对于后半部分，状态（i,j)只可能从状态（i-1,j)或者（i-1, j-value[i])两个状态推导过来，所以，
	我们就检查者两个状态是否可达，也就是states[i-1][j]或者states[i-1][j-value[i]]是否true。
	如果states[i-1][j]可达，说明我们没有选第i个商品， 如果states[i-1][j-valus[i]]可达，说明我们
	选择购买了第i个商品。我们从中选择一个可到达的状态（如果两个都可达，就随意选择一个），然后，
	继续迭代地考察其他商品是否有选择购买。
	*/
};

int main03(){
	Solution s;
	int w = 9;//背包承受的最大重量
	int v = 20;
	vector<int> weight = { 2, 2, 4, 6, 4 };//物品重量
	vector<int> value = { 3, 4, 8, 9, 6 };//物品的价值
	s.double11advance(value, v);
	system("pause");
	return 0;
}