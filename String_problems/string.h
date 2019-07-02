#include<iostream>
#include<assert.h>
using namespace std;
class String{
public:
	char* itoa(int num);//整数转字符串
	int atoi(char* str);//字符串转整数
	char* strcpy(char* strDest, const char* strSrc);//字符串拷贝
	void LoopMove(char* pStr, int steps);//字符串的循环移位
};