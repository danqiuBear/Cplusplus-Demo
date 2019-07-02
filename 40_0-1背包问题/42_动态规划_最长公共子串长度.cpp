#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:

	//longest common substring��̬�滮
	int lcs(const string a, const string b){
		int m = a.size();
		int n = b.size();
		vector<vector<int>> maxlcs(m, vector<int>(n, 0));
		for (int j = 0; j < n; ++j){// ��ʼ���� 0 �У�a[0..0] �� b[0..j]��maxlcs
			if (a[0] == b[j]) maxlcs[0][j] = 1;
			else if (j != 0) maxlcs[0][j] = maxlcs[0][j - 1];
			else maxlcs[0][j] = 0;
		}
		for (int i = 0; i < m; ++i){// ��ʼ���� 0 �У�a[0..i] �� b[0..0]��maxlcs
			if (a[i] == b[0]) maxlcs[i][0] = 1;
			else if (i != 0) maxlcs[i][0] = maxlcs[i - 1][0];
			else maxlcs[i][0] = 0;
		}
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (a[i] == b[j]){
					maxlcs[i][j] = max(maxlcs[i - 1][j - 1]+1,
						max(maxlcs[i - 1][j] , maxlcs[i][j - 1] ));
				}
				else{
					maxlcs[i][j] = max(maxlcs[i - 1][j - 1],
						max(maxlcs[i - 1][j], maxlcs[i][j - 1]));
				}
			}
		}
		return maxlcs[m - 1][n - 1];
	}
	//����  ʱ�临�Ӷ������ַ�������ָ������
	int lcsBT(const string a, const string b){
		int maxlcs = INT_MIN;
		return lcsBT(0, 0, 0, maxlcs, a, b);
	}
private:
	int lcsBT(int i, int j, int edist, int& maxlcs, const string a, const string b){
		/*
		if (i == a.size()-1 || j == b.size()-1){//�����Ƕ��ַ��������һ���ַ������ж�
			if (a[i] == b[j]){
				edist = edist + 1;
				maxlcs = maxlcs > edist ? maxlcs : edist;
			}
			else{
				if (i < a.size() - 1){//�ַ���a���滹���ַ�
					maxlcs = maxlcs > edist ? maxlcs : edist;
					return max(maxlcs, lcsBT(i + 1, j, edist, maxlcs, a, b));
				}
				else if (j < b.size() - 1){//�ַ���b���滹���ַ�
					maxlcs = maxlcs > edist ? maxlcs : edist;
					return max(maxlcs, lcsBT(i , j + 1, edist, maxlcs, a, b));
				}
				else{//ͬʱ�������ַ���a��b�����һλ
					maxlcs = maxlcs > edist ? maxlcs : edist;
					return maxlcs;
				}
			}
			if (maxlcs < edist) maxlcs = edist;
			return maxlcs;
		}*/
		//������ֹ����д���뿴�������Щ�����Ǻ�ʱ������ע�͵��ĸ���
		if (i == a.size() || j == b.size()){
			maxlcs = maxlcs > edist ? maxlcs : edist;
			return maxlcs;
		}
		if (a[i] == b[j]) return max( lcsBT(i + 1, j + 1, edist+1, maxlcs, a, b),
			max(lcsBT(i + 1, j, edist, maxlcs, a, b), lcsBT(i, j + 1, edist, maxlcs, a, b)) );
		else return max( lcsBT(i + 1, j + 1, edist, maxlcs, a, b),
			max(lcsBT(i + 1, j, edist, maxlcs, a, b), lcsBT(i, j + 1, edist, maxlcs, a, b)) );
	}
};
int main08(){
	Solution s;
	string a = "mitcmuab";
	string b = "mtacnubaaaaa";
	int minDist1 = s.lcs(a, b);
	int minDist2 = s.lcsBT(a, b);//���ݷ���ʱ�临�ӶȺܸ�
	cout << "minDist1: " << minDist1 << endl;
	cout << "minDist2: " << minDist2 << endl;
	cout << "minDist1: " << minDist1 << endl;
	system("pause");
	return 0;
}