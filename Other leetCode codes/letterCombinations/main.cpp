
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable:4996)

char map[10][5] = {
		{ ' ', ' ', ' ', ' ' }, //0
		{ ' ', ' ', ' ', ' ' }, //1
		{ 'a', 'b', 'c', ' ' }, //2
		{ 'd', 'e', 'f', ' ' }, //3
		{ 'g', 'h', 'i', ' ' }, //4
		{ 'j', 'k', 'l', ' ' },
		{ 'm', 'n', 'o', ' ' },
		{ 'p', 'q', 'r', 's' },
		{ 't', 'u', 'v', ' ' }, //8
		{ 'w', 'x', 'y', 'z' } //9
};

void letterComb(char* digits, int* returnSize, char *result, int ind, char **ans)
{
	int i = 0;
	char c;
	char *letter = map[digits[0] - '0'];
	//char *letter = *(map+(digits[0] - '0'));
	if (digits[0] == 0) {

		char *res = (char*)malloc(strlen(result) + 1);       //
		strcpy(res, result);
		ans[(*returnSize)] = res;
		//ans[(*returnSize)] = result;
		(*returnSize)++;
		return;
	}

	while ((c = letter[i]) != ' ') {
		result[ind] = c;
		letterComb(digits + 1, returnSize, result, ind + 1, ans);
		i++;
		if (i == 4)
			break;
	}
	return;
}

//求组合字符串的个数
int SizeCount(char*buf){
	int count = 1;
	for (int i = 0; i < strlen(buf); i++){
		if (buf[i] == '9' || buf[i] == '7')
			count *= 4;
		else
			count *= 3;
	}
	return count;
}

char** letterCombinations(char* digits, int* returnSize) {

	int ind = 0, size = 0;
	int len = strlen(digits) + 1;
	// ar result[len];
	char *result = (char*)malloc(sizeof(char)*len);

	if (digits == NULL || strlen(digits) == 0)
		return NULL;
	int flag = SizeCount(digits);
	char **ans = (char **)malloc(sizeof(char *)* flag);

	memset(result, 0, len);

	letterComb(digits, &size, result, ind, ans);
	*returnSize = size;

	return ans;
}



int main()
{
	char buf[100] = { 0 };
	int Size = 0;
	printf("请输入一个仅包含数字(2-9)的字符串:\n");
	scanf("%s", buf);
	//printf("Size = %d\n", SizeCount(buf));
	//printf("%s\n", buf);
	char **buf1 = letterCombinations(buf, &Size);
	printf("[");
	for (int i = 0; i < Size; i++){
		printf("%s ", buf1[i]);
	}
	printf("]\n");
	system("pause");
}
