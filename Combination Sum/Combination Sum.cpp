#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSumI(vector<int> & nums, int target){
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		dfsI(nums, path, result, target, 0);
		return result;
	}

	vector<vector<int>> combinationSumII(vector<int> & nums, int target){
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		dfsII(nums, path, result, target, 0);
		return result;
	}

private:
	void dfsI(vector<int>& nums, vector<int>& path, vector<vector<int>>& result,
		int gap, int start){
		if (gap == 0){
			result.push_back(path);
			return;
		}
		for (int i = start; i < nums.size(); ++i){//扩展状态
			if (gap < nums[i])
			{
				return;//剪枝
			}
			path.push_back(nums[i]);
			dfsI(nums, path, result, gap - nums[i], i);
			path.pop_back();
		}
	}

	void dfsII(vector<int>& nums, vector<int>& path, vector<vector<int>>& result,
		int gap, int start){
		if (gap == 0){
			result.push_back(path);
			return;
		}
		int prev = -1;
		for (int i = start; i < nums.size(); ++i){//扩展状态
			//如果上一轮循环已经使用了nums[i],则本次循环就不能再选nums[i],
			//确保nums[i]最多用一次
			if (prev == nums[i]) continue;
			if (gap < nums[i])	return;//剪枝
			
			prev = nums[i];
			path.push_back(nums[i]);
			dfsII(nums, path, result, gap - nums[i], i+1);
			path.pop_back();//恢复环境
		}
	}
};

int main(){
	Solution s;
	vector<int> nums = { 2, 2, 2, 3, 6, 7 };
	int target = 7;
	vector<vector<int>> resultII = s.combinationSumII(nums, target);
	for (int i = 0; i < resultII.size(); ++i){
		for (int j = 0; j < resultII[i].size(); ++j)
		{
			cout << resultII[i][j]<<' ';
		}
		cout << endl;
		
	}
	system("pause");
}