#include<iostream>
#include<algorithm>
#include<functional>
#include<string>

using namespace std;

class Solution{
public:
	string getPermutation1(int n, int k){
		string s(n, '0');
		for (int i = 0; i < n; i++){
			s[i] += i + 1;
		}
		for (int i = 0; i < k - 1; ++i)
		{
			next_permutation(s.begin(), s.end());
		}
		return s;
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
public:
	string getPermutation2(int n, int k){
		string s(n, '0');
		string result;
		for (int i = 0; i < n; i++){
			s[i] += i + 1;
		}
		return kth_permutation(s, k);
	}
private:
	int factorial(int n){
		int result = 1;
		for (int i = 1; i <= n; i++)
		{
			result *= i;
		}	
		return result;
	}
	template <typename Sequence>
	Sequence kth_permutation(const Sequence &seq, int k){
		const int n = seq.size();
		Sequence S(seq);
		Sequence result;

		int base = factorial(n - 1);
		--k;//康托编码从 0 开始

		for (int i = n - 1; i > 0; k %= base, base /= i, --i){
			cout << endl;
			cout << "======================================for loop===========================================" << endl;
			auto a = next(S.begin(), k / base);
			cout << "i: " << i << "  " << "base: " << base << "  " << "k: " << k << endl;
			cout << "result: " << result << "  " << "*a: " << *a << "  " << "S: " << S << endl;

			result.push_back(*a);
			cout << "after result.push_back(*a)， result:" << result << endl;

			S.erase(a);
			cout << "after S.erase(a)， S:" << S << endl;
		}
		result.push_back(S[0]);//最后一个
		return result;
	}
};

int main()
{
	Solution s;
	string str1 = s.getPermutation1(5, 16);
	cout << str1 << endl;

	string str2 = s.getPermutation2(5, 16);
	cout << str2 << endl;
	system("pause");
	return -1;
}