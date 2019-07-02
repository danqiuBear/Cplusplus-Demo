#include"string.h"
#define MAX 255
int main01(){
	String s;
	/*
	//测试itoa函数
	char *buf = s.itoa(1234);
	printf("string = %s\n", buf);

	//测试atoi函数
	//char str[7] = { '1', '2', '3', '4', '\0' };
	char* str = "1234";
	int num = s.atoi(buf);
	printf("integer = %d\n", num);


	//测试strcpy函数
	char* str2 = (char*)malloc(sizeof(char)*10);
	s.strcpy(str2, "hello");
	cout << str2 << endl;
	*/
	/*
	char src[] = "123456789123456789";char des[] = "123";
	cout << "des: " << des << endl;
	cout << "src: " << src << endl;
	s.strcpy(des, src);
	cout << "des: " << des << endl;
	cout << "src: " << src << endl;
	*/
	/*  TODO*/
	char a[] = "abcdefghi";//char* a = "abcfefg";写成这样就是作死， 此刻"abcfefg"是常量字符串，值不能被修改
	s.LoopMove(a, 2);
	cout << "a=: " << a << endl;
	

	system("pause");
	return 0;
}