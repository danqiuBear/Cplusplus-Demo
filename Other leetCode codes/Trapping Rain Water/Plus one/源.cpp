#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits)
	{ add(digits, 1);
	return digits;
	} 
private: 
	// 0 <= digit <= 9 
	void add(vector<int> &digits, int digit) 
	{ 
		int c = digit; // carry, 
		for (auto it = digits.rbegin(); it != digits.rend(); ++it) 
		{
			*it += c; c = *it / 10; *it %= 10; 
		} 
	//if (c > 0) digits.insert(digits.begin(), 1);
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(3);
	v.push_back(9);
	vector<int> v1 = s.plusOne(v);
	for (auto it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
