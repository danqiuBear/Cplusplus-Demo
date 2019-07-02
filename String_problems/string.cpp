#include"string.h"
char* String::itoa(int num){
	char *str = (char*) malloc(sizeof(char)*7);
	char tmp[7];
	int i = 0;
	while (num){
		tmp[i++] = (num % 10) + '0';
		num /= 10;
	}
	tmp[i] = 0;
	int j = 0;
	for (; j < i; ++j){
		str[j] = tmp[i - j - 1];
	}
	str[j] = '\0';
	return str;
}

int String::atoi(char* str){
	int res = 0;
	int i=0;
	while (str[i]){
		res = res * 10 + (str[i++] - '0');
	}
	return res;
}
char* String::strcpy(char* strDest, const char* strSrc){//�ַ�������
	assert(strDest != nullptr && strSrc != nullptr);
	char* address = strDest;
	while ((*address++ = *strSrc++) != '\0');
	return address;
	/*int i = 0;
	while (strSrc[i]){
		strDest[i] = strSrc[i];
		i++;
	}
	strDest[i] = '\0';
	return strDest;*/
}
void String::LoopMove(char* pStr, int steps){
	int len = strlen(pStr);
	char* tmp = (char*)malloc(sizeof(char)*len*2);
	strcpy(tmp, pStr + len - steps);//��pstr�ĺ���һ���ַ���������tmp��ǰ��һ��
	strcpy(tmp+steps, pStr);//��pstr����������tmp�ĺ���һ��[steps,...]
	//tmp[len] = 0;
	*(tmp + len) = '\0';
	strcpy(pStr, tmp);
}
