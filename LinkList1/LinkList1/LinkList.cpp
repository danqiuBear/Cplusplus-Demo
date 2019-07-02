#include"LinkList.h"
void CreateListHead(LinkList *&L, ElemType a[], int n){
	int i;
	LinkList *s;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = nullptr;
	for (i = 0; i < n; i++){       //ͷ�巨��������
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = L->next;
		L->next = s;               //Lʼ��Ϊ��ͷ
	}
}

void CreateListTail(LinkList *&L, ElemType a[], int n){//β�巨
	int i;
	LinkList *s, *r;
	L = (LinkList*)malloc(sizeof(LinkList));
	r = L;
	for (i = 0; i < n; i++){
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = nullptr;

}

void InitList(LinkList *&L){
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = nullptr;
}

void DestoryList(LinkList *&L){
	LinkList *pre = L , *cur = L->next;
	while (cur){//Դ���루wangzheng0822/algo/c-cpp/06_linkedlist/list_isPalindrome/LinkList���д˴��о��е�����ѽ!!������֤����������
		
		pre->next = cur ->next;//���Һ��¼ң����ͷ�
		free(cur);//ÿ��ɾ��ͷ�ڵ�L���һ��ɾ�����ݽڵ㣬
		cur = pre->next;
	}//ɾ����֮��ͷ�ڵ��next��Ϊnullptr��
}

bool ListEmpty(LinkList *L){
	return(L->next == nullptr);
}

int ListLength(LinkList *L){
	int n = 0;
	LinkList *p = L->next;//�����L�ǲ��洢���ݵ�ͷ�ڵ�
	while (p){//�����ͷ�ڵ㲻�洢����
		n++;
		p = p->next;
	}
	return(n);
}

void ShowList(LinkList *L){
	LinkList *p = L->next;
	while (p){
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");

}

bool GetListElem(LinkList *L, int i, ElemType &e){
	int j = 0;
	LinkList *p = L->next;
	while (j < i && p){
		j++;
		p = p->next;
	}
	if (p){
		e = p->data;
		return true;
	}
	else
		return false;
}
int LocateElem(LinkList *L, ElemType e)
{
	int i = 0;
	LinkList *p = L->next;
	while (p && p->data != e){
		p = p->next;
		i++;
	}
	if (!p){
		return(0);
	}
	else
		return(i);
}
bool ListInsert(LinkList *&L, int i, ElemType e){
	int j = 0;
	LinkList *p = L, *s;
	while (j < i  && p){
		j++;
		p = p->next;
	}
	if (!p){
		return false;
	}
	else{
		s = (LinkList*)malloc(sizeof(LinkList));//i=0��ʱ�������ͷ�ڵ������룬�൱�ڲ��������Ϊ�ڸ����ݽڵ㡣   ͷ�ڵ��ǲ��洢���ݵġ�
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
bool ListDelete(LinkList *&L, int i, ElemType &e){
	int j = 0;
	LinkList *p = L, *q;
	while (j < i  && p){
		j++;
		p = p->next;
	}
	if (!p){
		return false;
	}
	else{
		q = p->next;
		if (!p)//pҪɾ���ڵ�ǰ���һ���ڵ�
			return false;
		e = q->data; //qҪɾ���ڵ�
		p->next = q->next;
		free(q);
		return true;
	}
}
LinkList *ListCopy(LinkList *&list){
	LinkList *head = list;
	
	for (LinkList *cur = head; cur != nullptr;){
		LinkList *node = (LinkList*)malloc(sizeof(LinkList));
		node->data = cur->data;

		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}

	LinkList *dummy = (LinkList*)malloc(sizeof(LinkList));
	dummy->data = '?';
	LinkList *cur = head;
	LinkList *new_cur = dummy;

	for (; cur != nullptr;){
		new_cur->next = cur->next;
		new_cur = new_cur->next;
		cur->next = new_cur->next;
		cur = cur->next;
	}
	new_cur->next = nullptr;
	return dummy->next;
}
void ListReverse(LinkList *&head){
	if (head == nullptr || head->next == nullptr) return;
	LinkList *prev = head;
	for (LinkList* curr = head->next, *next = curr->next; curr;
			prev = curr,curr = next,next = next ? next->next:nullptr){
		curr->next = prev;
	}
	head->next = nullptr;
	head = prev;
}

