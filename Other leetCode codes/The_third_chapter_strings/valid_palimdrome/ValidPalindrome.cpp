#include"iostream"
#include <algorithm>
#include"string.h"
class CPalindrome{
public:
	CPalindrome(std::string s){
		m_s = s;
	}
	CPalindrome(std::string s, int len){
		m_s = s;
		m_len = len;
	}
public:
	bool isPalindrome(){
		transform(m_s.begin(), m_s.end(), m_s.begin(),::tolower);
		auto left = m_s.begin();
		auto right = prev(m_s.end());
		while (left < right){
			if (!::isalnum(*left)){
				left++;
			}
			else if (!::isalnum(*right)){
				right--;
			}
			else if (*left != *right){
				return false;
			}
			else{ left++, right--; }
		}
		return true;
	}
public:
	int LongestPalindrome()
	{
		int i, j, max, c;
		if (m_s == " "  || m_len < 1)
			return 0;
		max = 0;

		for (i = 0; i < m_len; ++i) { // i is the middle point of the palindrome  
			for (j = 0; (i - j >= 0) && (i + j < m_len); ++j){ // if the length of the palindrome is odd  
				if (m_s[i - j] != m_s[i + j])
					break;
				c = j * 2 + 1;
			}
			if (c > max)
				max = c;
			for (j = 0; (i - j >= 0) && (i + j + 1 < m_len); ++j){ // for the even case  
				if (m_s[i - j] != m_s[i + 1+ j ])
					break;
				c = j * 2 + 2;
			}
			if (c > max)
				max = c;
		}
		return max;
	}
private:
	std::string m_s;
	int m_len;
};

int main(){
	CPalindrome *strPalindrome1 = new CPalindrome("A man a plan, a canal: Panama");
	bool isPalindrome1 = strPalindrome1->isPalindrome();
	(isPalindrome1) ? std::cout << "the string is a palindrome" :
	std::cout << "the string is not a palindrome";
	std::cout << std::endl;


	CPalindrome *strPalindrome2 = new CPalindrome("1234326",7);
	int lenPalindrome2 = strPalindrome2->LongestPalindrome();
	std::cout << "lenPalindrome: " << lenPalindrome2 << std::endl;

	std::cout<<"hello world..." << std::endl;
	system("pause");
	return 0;
}