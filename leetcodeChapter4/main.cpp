#include<iostream>

#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class CValidParentheses{
public:
	bool IsValid(string const& s){
		string left = "([{";
		string right = ")]}";
		stack<char>stk;

		for (auto c : s){
			if (left.find(c) != string::npos){
				stk.push(c);
			}
			else{
				if (stk.empty() || stk.top() != left[right.find(c)])
					return false;
				else
					stk.pop();
			}
		}
		return stk.empty();
	}
public:
	//用栈 时间复杂度o(n),空间复杂度o（n)

 	int LongestValidParentheses1(const string& s){
		int max_len = 0, last = -1;//the position of the last
		stack<int> lefts;//keep track of the position of non-matching

		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '('){
				lefts.push(i);
			}
			else{
				if (lefts.empty()){
					//no match left
					last = i;
				}
				else{
					//find a matching pair
					lefts.pop();
					if (lefts.empty()){
						max_len = max(max_len, i - last);
					}
					else{
						max_len = max(max_len, i - lefts.top());
					}


				}
			}
		}
		return max_len;
	}
public:
	//动态规划 时间复杂度o(n),空间复杂度o（n)
	int LongestValidParentheses2(const string& s){
		vector<int>f(s.size(), 0);
		int ret = 0;
		for (int i = s.size() - 2; i >= 0; --i){
			int match = i + f[i + 1] + 1;
			//case:"((..))"
			if (s[i] == '(' && match < s.size() && s[match] == ')'){
				f[i] = f[i + 1] + 2;
				//if a valid sequence exist afterwards "((..))()"
				if (match + 1 < s.size()){
					f[i] += f[match + 1];
				}
			}
			ret = max(ret, f[i]);
		}
		return ret;
	}
	//两遍扫描 时间复杂度o(n),空间复杂度o（1)

	int LongestValidParentheses3(const string& s){
		int answer = 0, depth = 0, start = -1;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '('){
				++depth;
			}
			else{
				--depth;
				if (depth < 0){
					start = i;
					depth = 0;
				}
				else if (depth == 0){
					answer = max(answer, i - start);
				}
			}
		}

		depth = 0;
		start = s.size();
		for (int i = s.size() - 1; i >= 0; --i){
			if (s[i] == ')'){
				++depth;
			}
			else{
				--depth;
				if (depth < 0){
					start = i;
					depth = 0;
				}
				else if (depth == 0){
					answer = max(answer, start - i);
				}
			}
		}
		return answer;
	}
public:
	int LongestRectangleArea(vector<int> & height){
		stack<int> s;
		height.push_back(0);
		int result = 0;
		for (int i = 0; i < height.size();){
			if (s.empty() || height[i] > height[s.top()])
				s.push(i++);
			else{
				int tmp = s.top();
				s.pop();
				result = max(result,
					height[tmp] * (s.empty() ? i : i - s.top() - 1));
					
			}
		}
		return result;
	}
public:
	//递归版本
	int EvalRPN1(vector<string> &tokens){
		int x, y;
		auto token = tokens.back();
		tokens.pop_back();
		if (is_operator(token)){
			y = EvalRPN1(tokens);
			x = EvalRPN1(tokens);
			if (token[0] == '+')      x += y;
			else if (token[0] == '-') x -= y;
			else if (token[0] == '*') x *= y;
			else                      x /= y;
		}
		else{
			size_t i;
			x = stoi(token);
		}
		return x;
	}
public:
		//递归版本
	int EvalRPN2(vector<string> &tokens){
		stack<string> s;
		for (auto token : tokens){
			if (!is_operator(token)){
				s.push(token);
			}
			else{
				int y = stoi(s.top());
				s.pop();
				int x = stoi(s.top());
				s.pop();
				if (token == "+")      x += y;
				else if (token[0] == '-') x -= y;
				else if (token[0] == '*') x *= y;
				else                   x /= y;
				s.push(to_string(x));
			}
		}
		return stoi(s.top());
	}
private:
	bool is_operator(const string &op){
		return op.size() == 1 && string("+-*/").find(op) != string::npos;
	}
};

int main(){
	string str = ")()())";
	vector<int> buff = { 2, 1, 5, 6, 5, 2, 3 };
	vector<string>  tokens = { "2", "1", "+", "3", "*" };
	CValidParentheses cv;
	if (cv.IsValid(str)){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
	cout << cv.LongestValidParentheses3(str) << endl;
	cout << cv.LongestRectangleArea(buff) << endl;
	//cout << cv.EvalRPN1(tokens) << endl;
	cout << cv.EvalRPN2(tokens) << endl;
	system("pause");
	return 0;
}