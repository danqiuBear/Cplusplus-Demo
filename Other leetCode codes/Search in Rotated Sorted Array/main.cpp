#include<iostream>
#include "vector"
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int first = 0, last = nums.size();
		while (first != last)
		{
			const int mid = (first + last) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			if (nums[first] <= nums[mid])//left part sorted
			{
				if (nums[first] <= target && target < nums[mid])
				{
					last = mid;
				}
				else
				{
					first = mid + 1;
				}

			}
			else//right part sorted
			{
				if (nums[mid] < target && target <= nums[last - 1])
				{
					first = mid + 1;
				}
				else
				{
					last = mid;
				}
			}
		}
		return -1;
	}
};
void main()
{
	vector<int> nums  ;
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(3);
	//nums.push_back(7);
	//nums.push_back(0);
	//nums.push_back(1);
	//nums.push_back(2);
	
	Solution s;
	int ret = 0;
	ret = s.search(nums, 3);
	cout << ret << endl;
	system("pause");
	return;
}