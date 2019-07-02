#include<iostream>
#include "vector"
#include "algorithm"
#include <functional>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int index = nums.size() - 1;
		while (nums[index] <=nums[index - 1]) {
			--index;
		}
		if (index == 0) {
			sort(nums.begin(), nums.end());
			return;
		}

		int second = INT_MAX, secondIndex = INT_MAX;
		for (int i = nums.size() - 1; i >= index - 1; --i) {
			if (nums[i] > nums[index - 1]) {
				if (nums[i] < second) {
					second = nums[i];
					secondIndex = i;
				}
			}
		}
		int temp = nums[index - 1];
		nums[index - 1] = nums[secondIndex];
		nums[secondIndex] = temp;

		sort(nums.begin() + index, nums.end());
	}

public:
	void nextPermutation2(vector<int>& nums){
		cout << "nums.begin():  " << *nums.begin() << endl;//
		//cout  << "nums.end():  " << *nums.end() << endl; //此行报错
		cout  << "nums.end()-1:  " << *(nums.end()-1) << endl; 
		next_permutation(nums.begin(), nums.end());
	}
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last){
		//Get a reversed range to simplify reversed traversal.
		const auto rfirst = reverse_iterator<BidiIt>(last);
		const auto rlast = reverse_iterator<BidiIt>(first);
		cout << "*rfirst: " << *rfirst << endl;
		cout << "*(rlast-1): " << *(rlast-1) << endl;
		//cout << "*rlast: " << *rlast << endl;//此行报错
		//begin from the  second last element to the first element.
		auto pivot = next(rfirst);

		//Find 'pivot',which is the first element that is no less than is successor.
		//'prev' is used since 'pivot' is a 'reversed_iterator'
		
		cout << "*pivot: " << *pivot << "  " << "*prev(pivot): " << *prev(pivot) << endl;

		cout << "================================while loop=================================" << endl;
		while (pivot != rlast && *pivot >= *prev(pivot))
		{
			
			++pivot;
			cout << "*pivot: " << *pivot << "  " << "*prev(pivot): " << *prev(pivot) << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;

		//No such element found, current sequence ia already the largest  permutation,
		//then rearrange to the first permutation and return false
		if (pivot == rlast){
			reverse(rfirst, rlast);
			return false;
		}

		//Scan from right to left, find the first element that is greater than 'pivot'
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
		cout << "*change:  " << *change<< endl;
		swap(*change, *pivot);
		cout << "after swap: " << endl;
		for (vector<int>::iterator i = first; i != last; i++)
		{
			cout << *i << "  ";
		}
		cout << endl;
		cout << endl;

		reverse(rfirst, pivot);
		cout << "after reverse: " << endl;
		for (vector<int>::iterator i = first; i != last; i++)
		{
			cout << *i << "  ";
		}
		cout << endl;

		
		return true;

	}

};
int main()
{
	Solution s;
	vector<int> v;
	v.push_back(6);
	v.push_back(8);
	v.push_back(7);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	s.nextPermutation2(v);
	cout << "the next permutation is:  ";
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << "  ";
	}
	cout << endl;

	s.nextPermutation2(v);
	cout << "the next permutation is:  ";
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << "  ";
	}
	cout << endl;

	reverse(v.begin()+1, v.end() - 1);
	cout << "the next permutation to be partly reversed:  ";
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}