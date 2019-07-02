#include<iostream>
#include"string"
using namespace std;

class Solution{
public:
	int GetTranslationCount1(int number)
	{
		if (number < 0){
			return 0;
		}
		string numberInString = to_string(number);
		return GetTranslationCount1(numberInString);
	}
	int GetTranslationCount2(int number)
	{
		if (number < 0){
			return 0;
		}
		string numberInString = to_string(number);
		return GetTranslationCount2(numberInString);
	}
private:
	int GetTranslationCount1(const string& number)
	{
		int length = number.length();
		int *counts = new int[length];
		int count = 0;

		int digit1;
		int digit2;
		int converted;

		int offset;
		if (length == 1)
		{
			count = 1;
			return count;
		}
//========================================================================================================================================================================================
		else if (length == 2)
		{
			digit1 = number[0] - '0';
			digit2 = number[1] - '0';
			converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25){
				count = 2;
			}
			else
				count = 1;
			return count;
		}
//========================================================================================================================================================================================
		else
		{
			counts[length - 1] = 1;

			digit1 = number[0] - '0';
			digit2 = number[1] - '0';
			converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25){
				counts[length - 2] = 2;
			}
			else
				counts[length - 2] = 1;

			for (int i = length - 3; i >= 0; --i){
				digit1 = number[i] - '0';
				digit2 = number[i + 1] - '0';
				converted = digit1 * 10 + digit2;
				if (converted >= 10 && converted <= 25){
					offset = 1;
				}
				else
					offset = 0;
				counts[i] = counts[i + 1] + offset * counts[i + 2];
			}
		}
//========================================================================================================================================================================================
		count = counts[0];
		delete[] counts;

		return count;
	}
private:
	int GetTranslationCount2(const string & s) {
		if (s.empty() || s[0] == '0') 
			return 0; 
		int prev = 0;
		int cur = 1; // n n+1 
		for (size_t i = 1; i <= s.size(); ++i) 
		{ 
			if (s[i-1] == '0') cur = 0; 
			if (i < 2 || !(s[i - 2] == '1' ||(s[i - 2] == '2' && s[i - 1] <= '6')))
				prev = 0; 
			int tmp = cur; 
			cur = prev + cur; 
			prev = tmp; 
		} 
		return cur; 
	}
};

int main()
{
	Solution s;
	int a = 2812358;
	//int count1 = s.GetTranslationCount1(a);
	int count2 = s.GetTranslationCount2(a);
	//cout << count1 << endl;
	cout << count2 << endl;
	system("pause");
	return -1;

}