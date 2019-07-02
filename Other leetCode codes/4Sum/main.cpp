#include"iostream"
#include"vector"
#include"algorithm"
#include"unordered_map"

using namespace std;

class Solution{
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target){
		vector < vector<int>> result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());
		unordered_map<int, vector<pair<int, int>>> cache;
		for (size_t a = 0; a < nums.size(); ++a){
			for (size_t b = a + 1; b < nums.size(); ++b){
				cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
			}
		}
		for (int c = 0; c < nums.size(); ++c){
			for (size_t d = c + 1; d < nums.size(); ++d){
				const int key = target - nums[c] - nums[d];
				if (cache.find(key) == cache.end()) continue;

				const auto&vec = cache[key];
				for (size_t k = 0; k < vec.size(); ++k){
					if (c <= vec[k].second)
						continue;//гажиЕў
					result.push_back({ nums[vec[k].first], nums[vec[k].second], nums[c], nums[d] });
				}
				
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
public:
	vector<vector<int>> fourSum2(vector<int> &nums, int target){
		vector < vector<int>> result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());

		unordered_multimap<int, pair<int, int>> cache;
		for (size_t i = 0; i < nums.size() - 1; ++i){
			for (size_t j = i + 1; j < nums.size(); ++j){
				cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));

			}
		}
		for (unordered_multimap<int, pair<int, int>>::iterator i = cache.begin(); i != cache.end(); ++i){
			int x = target - i->first;
			/*
			_Pairii equal_range(const key_type& _Keyval)
		{	// find range equivalent to _Keyval in mutable hash table
		size_type _Bucket = _Hashval(_Keyval);
		for (_Unchecked_iterator _Where = _Begin(_Bucket);
			_Where != _End(_Bucket); ++_Where)
			if (!((_Traits&)*this)(this->_Kfn(*_Where), _Keyval))
				{	// found _First, look for end of range
				_Unchecked_iterator _First = _Where;
				for (; _Where != _End(_Bucket); ++_Where)
					if (((_Traits&)*this)(_Keyval, this->_Kfn(*_Where)))
						break;
				if (_First == _Where)
					break;
				return (_Pairii(_Make_iter(_First),
					_Make_iter(_Where)));
				}
		return (_Pairii(end(), end()));
		}
			*/
			//typedef pair<iterator, iterator> _Pairii;
			pair<unordered_multimap<int, pair<int, int>>::iterator, unordered_multimap<int, pair<int, int>>::iterator> range = cache.equal_range(x);


			for (auto j = range.first; j != range.second; ++j){
				auto a = i->second.first;
				auto b = i->second.second;
				auto c = j->second.first;
				auto d = j->second.second;
				if (a != c && a != d && b != c && b != d){
					vector<int> vec = { nums[a], nums[b], nums[c], nums[d] };
					sort(vec.begin(), vec.end());
					result.push_back(vec);
				}

			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};

int main01()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(-2);
	v.push_back(2);
	int target = 0;
	vector<vector<int>> result = s.fourSum2(v, target);

	for (vector<vector<int>>::iterator i = result.begin(); i != result.end(); ++i){
		for (int j = 0; j < (*i).size();++j){
			cout << (*i)[j]  << "  ";
		}
		cout << endl;

	}

	system("pause");
	return 1;
}
int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(9);
	v.push_back(9);
	v.push_back(10);
	vector<int>::iterator i = prev(v.end());
	cout <<"prev(v.end()) equals to :"<<(*i) << "  "<< endl;
	

	vector<int>::iterator j = prev(v.end(),4);
	cout << "prev(v.end(),4) equals to :" << (*j) << "  "<< endl;
	

	vector<int>::iterator k = lower_bound(v.begin(), v.end(), 4);
	cout << "lower_bound(v.begin(), v.end(), 4) equals to :" << (*k) << "  "<< endl;
	

	cout << *(k + 4)<<endl;


	vector<int>::iterator m = upper_bound(v.begin(), v.end(), 4);
	cout << "upper_bound(v.begin(), v.end(), 4) equals to :" << (*m) << "  " << endl;
	system("pause");
	return 1;
}