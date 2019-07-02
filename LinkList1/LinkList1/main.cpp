#include"LinkList.h"
char array1[] = { 'a', 'b', 'c', 'b', 'a' };
bool isPalindrome(LinkList *list, int length);
bool isPalindrome(LinkList *list, int length){
	int i;
	char *buff1 = (char *)malloc(sizeof(char)*length);
	char *buff2 = (char *)malloc(sizeof(char)*length);
	ElemType e;
	for (i = 0; i < length; i++){
		GetListElem(list, i, e);//������ȡ����Ԫ�ز���������
		buff1[i] = e;//�������� 0 1 2 3 4
		buff2[length -1- i] = e;//��������4 3 2 1 0
	}
	buff1[i] = '\0';
	buff2[i] = '\0';
	i = 0;
	while (i < length){
		if (buff1[i] == buff2[i]){
			i++;
		}
		else{
			return false;
		}
	}
	return true;
}

bool isPalindrome1(LinkList *list);
bool isPalindrome1(LinkList *list){//�����һ��Ϊ��
	LinkList *copy_list = ListCopy(list);
	LinkList *slow = copy_list->next;
	LinkList *fast = copy_list->next;
	LinkList *prev = nullptr;
	while (fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev = nullptr;//cut at middle
	ListReverse(slow);
	ShowList(list);
	//ShowList(copy_list);

	LinkList *L1 = copy_list->next;//�����ǰ�벿��  ==>����ΪN/2
	LinkList *L2 = slow;//����ĺ�벿�־���reverse ==>����ΪN-N/2
	while (L1){
		if (L1->data == L2->data){
			L1 = L1->next;
			L2 = L2->next;
		}
		else
			return false; 
	}
	return true;
}

int main(){
	LinkList *list;
	//ElemType e = 'a';
	int length = sizeof(array1) / sizeof(array1[0]);
	InitList(list);
	CreateListTail(list, array1, length);//β�巨����һ���б�
	if (isPalindrome(list, length))
		printf("isPalindrome\n");
	else
		printf("isNotPalindrome\n");
	if (isPalindrome1(list))
		printf("isPalindrome\n");
	else
		printf("isNotPalindrome\n");
	system("pause");
	return 0;
}
