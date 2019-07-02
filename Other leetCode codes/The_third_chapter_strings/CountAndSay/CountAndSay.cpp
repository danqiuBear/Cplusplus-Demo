#include<iostream>
#include"string"
#include <sstream>
#include "algorithm"
#include "functional"
#include <vector>

using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		string s("1");
		while (--n)
			s = getNext(s);
		return s;
	}
	string getNext(const string &s) {
		stringstream ss;
		for (auto  i = s.begin(); i != s.end();) {
			auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
			ss << distance(i, j) << *i;
			i = j;
		}
		return ss.str();
	}
	int lengthOfLastWord(const string& s){
		auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
		auto last = find_if_not(first, s.rend(), ::isalpha);
		cout << *first << endl;
		cout << *last << endl;

		return distance(first, last);
	}
	string simplifyPath(const string& path){
		vector<string> dirs;//当做栈

		for (auto i = path.begin(); i != path.end();){
			++i;
			auto j = find(i, path.end(), '/');
			auto dir = string(i, j);

			if (!dir.empty() && dir != "."){// 当有连续 '///'时，dir为空
				if (dir == ".."){
					if (!dirs.empty())
						dirs.pop_back();
				}
				else
					dirs.push_back(dir);
			}
			i = j;
		}
		stringstream out;
		if (dirs.empty()){
			out << "/";
		}
		else{
			for (auto dir : dirs)
				out << '/' << dir;
		}
		return out.str();
	}
};

int main(){
	Solution s;
	//string say = s.countAndSay(4);
	//int lastLength = s.lengthOfLastWord("hello world");
	//cout << say << endl;
	//cout << lastLength << endl;
	string path = "/a/.////b/../../c/";
	string dir = s.simplifyPath(path);
	cout << dir << endl;
	string b = "aaaabbb";
	auto first = find(b.begin(), b.end(), 'a');
	auto last  = find(b.begin(), b.end(), 'b');
	auto str = string(first, last);
	cout << str << endl;
	system("pause");
	return 0;
}