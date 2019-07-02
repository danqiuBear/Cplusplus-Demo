#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class sstring{
public:
	pair<int, string> fun(const string& str){//面试题1:求一个字符串中连续出现次数最多的子串
		vector<string>substrs;
		string substr;
		int count = 1;
		int max = 1;
		int len = str.length();

		for (int i = 0; i < len; ++i){
			substrs.push_back(str.substr(i, len - i));
		}
		for (int i = 0; i < len; ++i){
			for (int j = i + 1; j + (j - i) <= len; ++j){//
				count = 1;
				if (substrs[i].substr(0, j - i) == substrs[j].substr(0, j - i)){
					++count;
					for (int k = j + (j - i); k+(j-i) <= len; k = k + (j - i)){
						if (substrs[j].substr(0, j - i) == substrs[k].substr(0, j - i)){
							++count;
						}
						else{
							break;
						}
					}
				}
				if (max < count){
					max = count;
					substr = substrs[i].substr(0, j - i);
				}
			}
		}
		return make_pair(max, substr);
	}
	string longestSubstr(string str){//面试题2:找到最长重复子串
		int len = str.length();
		int max=0;
		string res;
		vector<string> sstr;
		for (int i = 0; i < len; ++i){
			sstr.push_back(str.substr(i, len - i));//分解字符串，存入到vector中
		}
		sort(sstr.begin(), sstr.end());//vector中的字符串排序
		for (int i = 1; i < len; ++i){//从相邻字符串中找到最长公共前缀
			int count = 0;
			int m = sstr[i - 1].length();
			int n = sstr[i].length();
			int k = m < n ? m : n;
			for (int j = 0; i < k; ++j){
				if (sstr[i - 1][j] != sstr[i][j]) break;
				++count;
			}
			if (max < count){
				max = count;
				res = sstr[i].substr(0, max);
			}
		}
		return res;
	}
	const char* strstr(const char* string, const char* strCharSet){//面试题3：找到最长子串，调用了函数的
		int len1 = strlen(string);
		int len2 = strlen(strCharSet);
		int count = 0;
		for (int i = 0; i < len1 - len2 + 1; ++i){
			if (string[i] == strCharSet[0]){
				int tmp = i;
				for (int j = 0; j < len2;){
					if (string[i++] != strCharSet[j++]) {
						break;
					}
					++count;
					if (count == len2){
						return &string[tmp];
					}
				}
			}
		}
		return nullptr;
	}
	const char* strstr2(const char* string, const char* strCharSet){////面试题3：找到最长子串，不调用任何函数
		for (int i = 0; string[i] != '\0'; ++i){
			if (string[i] == strCharSet[0]){
				int tmp = i;
				int j = 0;
				while (string[i++] == strCharSet[j++]){
					if (strCharSet[j] == '\0'){
						return &string[tmp];
					}
				}
				
			}
		}
		return nullptr;
	}
	int numOfOne(long long num){
		
		long long front=num;
		int pos;
		long long back;
		long long time10 = 1;
		long long sum = 0;
		while (front){
			pos = front % 10;
			front = front / 10;
			back = num%time10;
			if (pos == 0){
				sum += front*(time10);
			}
			else if(pos == 1){
				sum += front*(time10)+(back+1);
			}
			else{
				sum += (front + 1)*time10;
			}
			time10 *= 10;
		}
		return sum;
	}
};
int main02(){
	sstring ss;
	/*string str = "yyabcdabjcabceg";
	string rep = ss.longestSubstr(str);
	cout << rep << " " << rep.length() << endl;
	cout << ss.strstr("12345678", "8") << endl;
	cout << ss.strstr2("12345678", "8") << endl;
	string str;
	pair<int, string> rs;
	while (cin >> str){
		rs = ss.fun(str);
		cout << rs.second << ":" << rs.first << endl;
	}
	string s = "i come from ezhou.";
	cout << "s: " << s << endl;
	reverse(s.begin(), s.end());
	cout << "after reversed: " << s << endl;
	string::iterator left = s.begin();
	for (string::iterator i = s.begin(); i != s.end(); ++i){
		if (*i == ' '){
			reverse(left, i);
			left = i + 1;
		}
	}
	cout << "after reversed: " << s << endl;*/
	cout << ss.numOfOne(13) << endl;
	system("pause");
	return 0;
}