#include<iostream>
#include<algorithm>
#include<functional>
#include "vector"
#include"unordered_map"
using namespace std;
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		unordered_map<int, int> count_map;//��¼ÿ��Ԫ�س��ֵĴ���
		for_each(nums.begin(), nums.end(), [&count_map](int e){
			if (count_map.find(e) != count_map.end())
				count_map[e] ++;
			else
				count_map[e] = 1;
		});
		//��map�����pair ������һ��vector��
		vector<pair<int, int>> elems;
		for_each(count_map.begin(), count_map.end(), [&elems](const pair<int, int> &e){
			elems.push_back(e);
		});

		vector<vector<int>> result;//���ս��
		vector<int> p;//�м���

		n = nums.size();
		permute(elems.begin(), elems.end(), p, result);
		return result;
	}
private:
	size_t n;
	typedef vector<pair<int, int>>::const_iterator Iter;
	void permute(Iter first, Iter last, vector<int> &p, vector<vector<int>> &result){
		if (n == p.size()){//��������
			result.push_back(p);
			return;
		}

		//��չ״̬
		for (auto i = first; i != last; i++){
			int count = 0;//ͳ�� *i�� p �г��ֹ����ٴ�
			for (auto j = p.begin(); j != p.end(); j++){
				if (i->first == *j){
					count++;
				}
			}
			if (count < i->second){
				p.push_back(i->first);
				permute(first, last, p, result);
				p.pop_back();
			}
		}
	}
};
int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	vector<vector<int>> result = s.permuteUnique(v);
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