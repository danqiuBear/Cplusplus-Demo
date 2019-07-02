#include<iostream>
#include<algorithm>
#include<functional>
#include "vector"
using namespace std;
class Solution{
public:
	vector<vector<int>> permute(vector<int>& nums){
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;//中间结果

		dfs(nums, path, result);
		
		return result;
	}
public:
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last){
		const auto rfirst = reverse_iterator<BidiIt>(last);
		const auto rlast = reverse_iterator<BidiIt>(first);

		auto pivot = next(rfirst);

		while (pivot != rlast && *pivot >= *prev(pivot))
			++pivot;

		if (pivot == rlast){
			reverse(rfirst, rlast);
			return false;
		}

		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

		swap(*pivot, *change);

		reverse(rfirst, pivot);

		return true;
	}
private:
	void dfs(const vector<int>& nums, vector<int>&path, vector<vector<int>>& result){
		if (path.size() == nums.size()){//收敛条件
			result.push_back(path);

			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++result: +++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			for (vector<vector<int>>::iterator i = result.begin(); i < result.end(); i++){
				for (vector<int>::iterator j = i->begin(); j < i->end(); j++){
					cout  << *j << " ";
				}
				cout << endl;	
			}
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<endl;
			return;
		}
		//扩展状态
		for (auto i : nums){
			//查找 i 是否在 path 中出现过
			auto pos = find(path.begin(), path.end(), i);

			if (pos == path.end()){
				path.push_back(i);
				cout << "====================================after path.push_back(i):====================================" << endl;
				cout << "path: " << endl;
				for (vector<int>::iterator j = path.begin(); j < path.end(); j++){
					cout <<  *j << " ";
				}
				cout << endl;
				dfs(nums, path, result);
				path.pop_back();
				cout << "====================================after path.pop_back():====================================" << endl;
				cout << "path: " << endl;
				for (vector<int>::iterator j = path.begin(); j < path.end(); j++){
					cout << *j << " ";
				}
				cout << endl;
			}
		}
	}
};


int main()
{
	Solution s;
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	vector<vector<int>> result = s.permute(v);
	for (vector<vector<int>>::iterator i = result.begin(); i < result.end(); i++){
		for (vector<int>::iterator j = (*i).begin(); j < (*i).end(); j++){
			cout << *j << " ";
			cout << "hello....." << "  " << endl;
		}
		cout << endl;

	}

	cout << " hello......" << endl;
	system("pause");
	return -1;
}