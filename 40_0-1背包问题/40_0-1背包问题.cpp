
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class bag_Problem{
public:
	//������Ļ����㷨
	int knapsack1(const vector<int> weight, const int w){
		int maxW = INT_MIN; //����ŵ�maxW��
		int n = weight.size();//��Ʒ����
		return f(0, 0, maxW, weight, w, n);
	}
	//����¼+����
	int knapsack2(const vector<int> weight, const int w){
		int maxW = INT_MIN; //����ŵ�maxW��
		int n = weight.size();//��Ʒ����
		vector<vector<bool>> states(n, vector<bool>(w + 1, false));
		return f_mem(0, 0, maxW, weight, w, n, states);
	}

	//��̬�滮  weight:��Ʒ������ n:��Ʒ������ w:�����ɳ�������
	int knapsack3(const vector<int> weight, const int w){
		int maxW = INT_MIN; //����ŵ�maxW��
		int n = weight.size();//��Ʒ����
		vector<vector<bool>> states(n, vector<bool>(w + 1, false));
		states[0][0] = true;
		states[0][weight[0]] = true;
		for (int i = 1; i < n; ++i){//��̬�滮״̬ת��
			for (int j = 0; j <= w; ++j){//���ѵ�i����Ʒ���뱳��
				if (states[i - 1][j]) states[i][j] = true;
			}
			for (int j = 0; j <= w; ++j){//�ѵ�i����Ʒ���뱳��
				if (states[i - 1][j] && (j + weight[i] <= w)){
					states[i][j + weight[i]] = true;
				}
			}
		}
		for (int j = w; j >= 0; --j){//������
			if (states[n - 1][j]) return j;
		}
		return 0;
	}
	//��̬�滮  weight:��Ʒ������ n:��Ʒ������ w:�����ɳ�������
	//��һά��������ʾ״̬���Խ�ʡ�ռ�
	int knapsack4(const vector<int> weight, const int w){
		int maxW = INT_MIN; //����ŵ�maxW��
		int n = weight.size();//��Ʒ����
		vector<bool> states (w + 1, false);
		states[0] = true;
		states[weight[0]] = true;
		for (int i = 1; i < n; ++i){//��̬�滮״̬ת��
			//����һ�е�jҪ�Ӵ�С����������ǰ���j��С������Ļ��������forѭ���ظ��������⡣
			for (int j = w - weight[i]; j >= 0; --j){//�ѵ�i����Ʒ���뱳��
				if (states[j]) states[j + weight[i]] = true;
			}
		}
		for (int j = w; j >= 0; --j){//������
			if (states[j]) return j;
		}
		return 0;
	}

private:	
	int f(int i, int cw, int& maxW, const vector<int> weight, const int w,  const int n){//����f(0,0)
		if (cw == w || i == n){//cw==w��ʾװ���ˣ� i==n��ʾ��Ʒ����������
			if (cw > maxW) maxW = cw;
			return maxW;
		}
		maxW = max(maxW, f(i + 1, cw, maxW, weight, w, n));//ѡ��װ��i����Ʒ
		if (cw + weight[i] <= w){//ѡ��װ��i����Ʒ
			maxW = max(maxW, f(i + 1, cw + weight[i], maxW, weight,w,  n));
		}
		return maxW;
	}
	//����¼+����
	int f_mem(int i, int cw, int& maxW, const vector<int> weight, const int w, const int n, vector<vector<bool>>& states){//����f(0,0)
		if (cw == w || i == n){//cw==w��ʾװ���ˣ� i==n��ʾ��Ʒ����������
			if (cw > maxW) maxW = cw;
			return maxW;
		}
		if (states[i][cw]) return maxW;//�ظ�״̬
		states[i][cw] = true;//��¼��i,cw)���״̬
		maxW = max(maxW, f_mem(i + 1, cw, maxW, weight, w, n, states));//ѡ��װ��i����Ʒ
		if (cw + weight[i] <= w ){//ѡ��װ��i����Ʒ
			maxW = max(maxW, f_mem(i + 1, cw + weight[i], maxW, weight, w, n, states));
		}
		return maxW;
	}
};

int main01(){
	bag_Problem s;
	int w = 9;//�������ܵ��������
	vector<int> weight = { 2, 2, 4, 6, 4 };//��Ʒ����
	
	int largest_weight_in_bag = s.knapsack4(weight, w);
	cout << largest_weight_in_bag << endl;
	system("pause");
	return 0;
}