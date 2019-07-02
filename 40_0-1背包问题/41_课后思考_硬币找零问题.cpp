#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	/*
	Ӳ���������⣬������̰���㷨��һ���н���һ�Ρ����ǽ�������һ�����µ�Ӳ���������⡣���������м��ֲ�ͬ
	��ֵ��Ӳ��v1�� v2��...vn,����λ��Ԫ�����������Ҫ֧��wԪ����������Ҫ���ٸ�Ӳ�ҡ����磬���������ֲ�ͬ��
	Ӳ�ң�1Ԫ�� 3Ԫ�� 5Ԫ������Ҫ֧��9Ԫ��������Ҫ3��Ӳ�ң�3��3Ԫ��Ӳ�ң�

	���Կ������������⣬�ֱ������1.3.5������ô�����ߵ�9������̬ת�Ʒ���Ϊf(9)=1+min(f(8),f(6),f(4))
	*/
	//�����ݽ����
	//@coins:��ͬ�����Ӳ��
	//@sum:��Ҫ֧�����ܶ�
	int minCoinNum1(const vector<int> coins, int sum){
		int n = coins.size();
		return minCoinNum1(coins, sum, n);	
	}
    //��̬�滮�����  ״̬ת�Ʊ�
	// mΪ������Ҫ��Ӳ�ҵĸ��� = ��ֵ��ϵ��ܺ�/��СӲ�ҵ�����
	//states[i][j]���� i+1��Ӳ����ϵĿ��ܵı�ֵΪj
	//����ĺ����ǰ�״̬ת�Ʊ�������������
	int minCoinNumDP1(vector<int> coins, int sum){
		sort(coins.begin(), coins.end());
		int n = coins.size();
		int m = sum / coins[0];
		vector<vector<int>> states(m, vector<int>(sum + 1, -1));
		for (int i = 0; i < n; ++i){//��ʼ��states�ĵ�һ��
			states[0][coins[i]] = coins[i];
		}
		for (int i = 1; i < m; ++i){
			for (int j = 0; j <= sum; ++j){
				if (states[i - 1][j] != -1){
					for (int k : coins){
						//����i+1ö���ϵ��ǵ�köӲ�ң����Ǽ��Ϻ󳬳��ܺͣ��������ҵ�iöӲ�ҵ�ѭ����
						//��Ϊ�����Ӳ�������ǰ��Ĵ�,�����ҵĻ�Ҳ�ᳬ����Ŀ������ܺ�
						if (states[i - 1][j] + k > sum) break;
						states[i][j + k] = states[i - 1][j] + k;
						//�ҵ�����Сö����Ӳ����ϣ������ӡ����
						if (states[i][j + k] == sum) {
							int tmp = sum;
							//�Ӻ���ǰ�ҵ�һ��������������Ӳ�������ӡ����
							//p��¼�������ڲ�ѯ����states�ĵڼ���
							for (int p = i; p >= 1; p--){
								for (int v: coins){
									//��ȥ��ǰ�е�ĳöӲ�ұ�ֵ�󣬱�ֵ�ܺ�����һ�У�p-1)���ڡ�
									if (states[p - 1][tmp - v] != -1){
										tmp = tmp - v;
										cout << v << " ";
										break;//һ���ҵ���һ��Ӳ�ң���break�����������ϸ�Ӳ�ҡ�
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
		return -1;//���Ҳ�����������ϣ��򷵻�-1��
	}
	//״̬ת�Ʒ���
	//min_count[i] = min(min_count[j] + 1) j < i
	int minCoinNumDP2(vector<int> coins, int sum){
		vector<int> min_count(sum + 1, INT_MAX);
		min_count[0] = 0;
		for (int i = 1; i <= sum; ++i){
			for (int j = 0; j <= i - 1; ++j){
				for (int v : coins){
					if ((j + v == i) && (min_count[i] > min_count[j])){//�ܴ�������С
						min_count[i] = min_count[j] + 1;
					}
				}
			}
		}
		return min_count[sum];
	}
private:
	int minCoinNum1(const vector<int> coins, int sum, int n){
		int min_count = sum;//min_count ��󲻳���sum.
		if (sum == 0) return 0;
		if (sum < 0) return INT_MAX;//sum<0˵������ϲ�����Ҫ�󣬷���һ���������
		int i = n-1;
		while ( i>=0 ){
			min_count = min(minCoinNum1(coins, sum - coins[i], n), min_count);
			--i;
		}
		return min_count + 1;//������Ҫ֧����Ӳ����Ŀ
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