#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class bag_Problem_upgrade{


public:
	//������Ļ����㷨
	int knapsack1(const vector<int> weight, const vector<int> value, const int w){
		int maxV = INT_MIN; //����ŵ�maxW��
		int n = weight.size();//��Ʒ����
		return f(0, 0,0, maxV, weight,value, w, n);
	}


	//��̬�滮  weight:��Ʒ������ n:��Ʒ������ w:�����ɳ�������
	int knapsack3(const vector<int> weight, const vector<int> value, const int w){
		int n = weight.size();//��Ʒ����
		vector<vector<int>> states(n, vector<int>(w + 1, -1));
		states[0][0] = 0;
		states[0][weight[0]] = value[0];
		for (int i = 1; i < n; ++i){//��̬�滮״̬ת��
			for (int j = 0; j <= w; ++j){//���ѵ�i����Ʒ���뱳��
				if (states[i - 1][j] >= 0) states[i][j] = states[i - 1][j];
			}
			for (int j = 0; j <= w-weight[i]; ++j){//�ѵ�i����Ʒ���뱳��
				if (states[i - 1][j] >= 0 ){
					int v = states[i - 1][j] + value[i];
					if (v > states[i][j + weight[i]]) {
						states[i][j + weight[i]] = v;
					}
				}
			}
		}
		int maxvalue = -1;
		for (int j = 0; j <=w; ++j){//������
			if (states[n - 1][j] > maxvalue) maxvalue  = states[n-1][j];
		}
		return maxvalue;
	}
	//��̬�滮  weight:��Ʒ������ n:��Ʒ������ w:�����ɳ�������
	//��һά��������ʾ״̬���Խ�ʡ�ռ�
	int knapsack4(const vector<int> weight, const vector<int> value, const int w){
		int n = weight.size();//��Ʒ����
		vector<int> states(w + 1, -1);
		states[0] = 0;
		states[weight[0]] = value[0];
		for (int i = 1; i < n; ++i){//��̬�滮״̬ת��
			//����һ�е�jҪ�Ӵ�С����������ǰ���j��С������Ļ��������forѭ���ظ��������⡣
			for (int j = w - weight[i]; j >= 0; --j){//�ѵ�i����Ʒ���뱳��
				if (states[j] >= 0){
					int v = states[j] + value[i];
					if (v > states[j + weight[i]]){
						states[j + weight[i]] = v;
					}
				}
			}
		}
		int maxvalue = -1;
		for (int j = w; j >= 0; --j){//������
			if (states[j] > maxvalue) maxvalue = states[j];
		}
		return maxvalue;
	}
private:
	int f(int i, int cw, int cv, int& maxV, const vector<int> weight, const vector<int> value,const int w, const int n){//����f(0,0,0)
		if (cw == w || i == n){//cw==w��ʾװ���ˣ� i==n��ʾ��Ʒ����������
			if (cv > maxV) maxV = cv;
			return maxV;
		}
		maxV = max(maxV, f(i + 1, cw, cv ,maxV, weight, value, w, n));//ѡ��װ��i����Ʒ
		if (cw + weight[i] <= w){//ѡ��װ��i����Ʒ
			maxV = max(maxV, f(i + 1, cw + weight[i], cv+value[i], maxV, weight, value, w, n));
		}
		return maxV;
	}
};
int main02(){
	bag_Problem_upgrade s;
	int w = 9;//�������ܵ��������
	vector<int> weight = { 2, 2, 4, 6, 4 };//��Ʒ����
	vector<int> value = { 3, 4, 8, 9, 6 };//��Ʒ�ļ�ֵ
	int largest_value_in_bag = s.knapsack4(weight,value,w);
	cout << largest_value_in_bag << endl;
	system("pause");
	return 0;
}
