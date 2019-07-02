#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s) {
		int max_len = 0;
		unordered_map<int, int> m;
		int left = -1;
		for (int i = 0; i < s.size(); ++i){
			if (m.count(s[i])){
				//&& m[s[i]] > left去掉也会报错： && m[s[i]] > left 
				//input:"abba" output:3, expect:2
				left = m[s[i]];
			}
			max_len = max(max_len, i - left);
			m[s[i]] = i;
		}
		return max_len;
	}
};
int main(){
	Solution s;
	string sub = "abba";
	int max_len = s.lengthOfLongestSubstring(sub);
	cout << max_len << endl;
	system("pause");	
}
