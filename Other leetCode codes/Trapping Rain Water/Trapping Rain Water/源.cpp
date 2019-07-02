#include<iostream>
#include<vector>
using namespace std;
#include<functional>
#include<stack>
#include<algorithm>
class Solution {
public: int trap(const vector<int>& A) {
	const int n = A.size();
	stack<pair<int, int>> s;
	int water = 0;
	for (int i = 0; i < n; ++i) {
		int height = 0; 
		while (!s.empty()) { //²»Îª¿Õ
			int bar = s.top().first;
			int pos = s.top().second; // bar, height, A[i]
			water += (min(bar, A[i]) - height) * (i - pos - 1); 
			cout << "i: " << i << " " << "A[i]: " << A[i] << " " << "water: " << water << endl;
			height = bar; 
			if (A[i] < bar) // 
				break; 
			else s.pop(); // 
		} 
		s.push(make_pair(A[i], i));
		} return water;
	}
};
int main(){
	Solution s;
	vector<int> v = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int water = s.trap(v);
	cout << "water:" << water << endl;
	system("pause");
	return 0;
}