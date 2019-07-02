#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	//1�������㷨  ʱ�临�Ӷ���O(2^n),�ռ临�Ӷ���O(1)
	int minTriangleSum1(const vector<vector<int>> triangle){
		int minPathSum = triangle[0][0], sum = triangle[0][0];
		return f(0, 0, sum, triangle, minPathSum);
	}
	//2.��̬�滮 ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(n^2)
	int minTriangleSum2(const vector<vector<int>> triangle){
		//states[i][j]����ӣ�i,j)�������һ���������С·����
		int m = triangle.size();
		vector<vector<int>> states(m-1,vector<int>(m, INT_MAX));
		states.push_back(triangle[m - 1]);
		for (int i = m-2; i >= 0; --i){
			for (int j = 0; j <= i; ++j){
				states[i][j] = min(states[i + 1][j], states[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return states[0][0];
	}
	//3.��̬�滮 ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(n)
	int minTriangleSum3(const vector<vector<int>> triangle){
		//states[i][j]����ӣ�i,j)�������һ���������С·����
		int m = triangle.size();
		vector<int> states(triangle.back());
		for (int i = m - 2; i >= 0; --i){
			for (int j = 0; j <= i; ++j){
				states[j] = min(states[j], states[j + 1]) + triangle[i][j];
			}
		}
		return states[0];
	}
	//4.��̬�滮 ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(1)
	//���ַ����ı���triangle���飬���Բ��Ƽ�ʹ��
	int minTriangleSum4( vector<vector<int>> triangle){
		//states[i][j]����ӣ�i,j)�������һ���������С·����
		int m = triangle.size();
		for (int i = m - 2; i >= 0; --i){
			for (int j = 0; j <= i; ++j){
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
private:
	int f(int m, int n, int sum, const vector<vector<int>>& triangle, int& minPathSum){
		if (m == triangle.size()-2){
			minPathSum = min(sum + triangle[m+1][n], sum + triangle[m+1][n + 1]);
			return minPathSum;
		}
		
		minPathSum = min(f(m + 1, n, sum + triangle[m + 1][n], triangle, minPathSum),
			f(m + 1, n + 1, sum + triangle[m + 1][n + 1], triangle, minPathSum));
		return minPathSum;
	}
		
};
int main04(){
	Solution s;
	int w = 9;//�������ܵ��������
	int v = 20;
	vector<vector<int>> triangle1 = { { 5 }, { 7, 8 }, { 2, 3, 4 }, { 4, 9, 6, 1 }, { 2, 7, 9, 4, 5 } };//20
	vector<vector<int>> triangle2 = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };//11
	vector<vector<int>> triangle3 = { { -1 }, { 2, 3 }, { 1, -1, -3 }, { 5, 3, -1, 2 } };//-2

	int minPathSum = s.minTriangleSum4(triangle3);
	cout << "minPathSum: " << minPathSum << endl;
	system("pause");
	return 0;
}