#include<iostream>
#include<assert.h>
using namespace std;
class String{
public:
	char* itoa(int num);//����ת�ַ���
	int atoi(char* str);//�ַ���ת����
	char* strcpy(char* strDest, const char* strSrc);//�ַ�������
	void LoopMove(char* pStr, int steps);//�ַ�����ѭ����λ
};