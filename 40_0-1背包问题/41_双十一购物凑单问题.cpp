#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	//items ��ʾ��Ʒ�۸� n��ʾ��Ʒ������ w��ʾ���������� ����200
	void double11advance(vector<int> items, int w){
		int n = items.size();
		vector<vector<bool>> states(n, vector<bool>(3 * w + 1, false));//����3����û��޶��ë�ļ�ֵ��
		states[0][0] = true;//��һ��Ҫ���⴦��
		states[0][items[0]] = true;
		for (int i = 1; i < n; ++i){//��̬�滮
			for (int j = 0; j <= 3 * w ; ++j){//�������i����Ʒ
				if (states[i - 1][j] == true) states[i][j] = states[i - 1][j];
			}
			for (int j = 0; j <= 3 * w  - items[i]; ++j){//�����i����Ʒ
				if (states[i - 1][j] == true)  states[i][j + items[i]] = true;
			}
		}
		int j;
		for (j = w; j < 3 * w + 1; ++j){
			if (states[n - 1][j]) break;//���������ڵ���w����Сֵ
		}
		if (j == -1) return;
		for (int i = n - 1; i >= 1; --i){//i ��ʾ��ά�����е��У� j��ʾ��
			if (j - items[i] >= 0 && states[i - 1][j - items[i]]){
				cout << items[i] << " ";
				j = j - items[i];
			}//else û�й��������Ʒ�� j����
		}
		if (j != 0) cout << items[0] << endl;
	}
	/*
	���ں�벿�֣�״̬��i,j)ֻ���ܴ�״̬��i-1,j)���ߣ�i-1, j-value[i])����״̬�Ƶ����������ԣ�
	���Ǿͼ��������״̬�Ƿ�ɴҲ����states[i-1][j]����states[i-1][j-value[i]]�Ƿ�true��
	���states[i-1][j]�ɴ˵������û��ѡ��i����Ʒ�� ���states[i-1][j-valus[i]]�ɴ˵������
	ѡ�����˵�i����Ʒ�����Ǵ���ѡ��һ���ɵ����״̬������������ɴ������ѡ��һ������Ȼ��
	���������ؿ���������Ʒ�Ƿ���ѡ����
	*/
};

int main03(){
	Solution s;
	int w = 9;//�������ܵ��������
	int v = 20;
	vector<int> weight = { 2, 2, 4, 6, 4 };//��Ʒ����
	vector<int> value = { 3, 4, 8, 9, 6 };//��Ʒ�ļ�ֵ
	s.double11advance(value, v);
	system("pause");
	return 0;
}