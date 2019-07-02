#include<iostream>
#include<algorithm>
#include<functional>
#include "vector"
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		do{
			result.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return result;
	}
public:
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last)
	{
		const auto rfirst = reverse_iterator<BidiIt>(last);
		const auto rlast = reverse_iterator<BidiIt>(first);
		auto pivot = next(rfirst);

		while (pivot != rlast && *pivot >= *prev(pivot))
			pivot++;

		if (pivot == rlast){
			reverse(rfirst, rlast);
			return false;
		}

		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
		swap(*pivot, *change);
		reverse(rfirst, pivot);
		return true;

	}
};
int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	vector<vector<int>> result = s.permute(v);
	for (vector<vector<int>>::iterator i = result.begin(); i < result.end(); i++){
		for (vector<int>::iterator j = (*i).begin(); j < (*i).end(); j++){
			cout << *j << " ";
		}
		cout << endl;

	}

	cout << " hello......" << endl;
	system("pause");
	return -1;
}