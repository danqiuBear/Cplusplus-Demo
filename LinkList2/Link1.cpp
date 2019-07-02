#include"Link1.h"
#include<iostream>
using namespace std;

node *Link1::creat(){
	node *head, *p, *s;
	int x, cycle = 1;
	head = (node*)malloc(sizeof(node));
	p = head;
	while (cycle){
		cout << "please input the data(int):" << endl;
		cin >> x;
		if (x != 0){
			s = (node*)malloc(sizeof(node));
			s->data = x;
			p->next = s;
			p = p->next;
		}
		else{
			cycle = 0;
		}
	}
	head = head->next;
	p->next = nullptr;
	cout << " yyy " << head->data << endl;
	return head;
}
int Link1::length(node* head){
	node* p = head;
	int len = 0;
	while (p != nullptr){
		len++;
		p = p->next;
	}
	return len;
}
void Link1::Print(node* head){
	node* p = head;
	while (p != nullptr){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
node* Link1::del(node* head, int num){
	node dummy;
	dummy.data = -1;
	dummy.next = head;
	node* p = head;
	node* pre = &dummy;
	while (p != nullptr){
		if (p->data != num){
			pre = p;
			p = p->next;
		}
		else{
			pre->next = p->next;
			free(p);
			break;
		}
	}
	return dummy.next;
}
node* Link1::insert(node* head, int i, int num){//在第i个元素之前插入元素num, head为第0个元素, 0<=i <= head.length(), 若i大于范围，则插在末尾, 小于范围，插在头结点。
	
	node dummy;
	dummy.data = -1;
	dummy.next = head;
	node* p = &dummy;
	node* s;
	while (i-- > 0){
		if (p ->next == nullptr){
			break;
		}
		p = p->next;
	}
	s = (node*)malloc(sizeof(node));
	s->data = num;
	s->next = p->next;
	p->next = s;
	return dummy.next;
}
node* Link1::removeHead(node* head){
	if (!head || !head->next)return nullptr;
	node* dummy = (node*)malloc(sizeof(node));
	dummy->data = -1;
	dummy->next = head;
	dummy->next = head->next;
	free(head);
	return dummy->next;

}
void Link1::searchmid1(node* head, node*& mid){//左中
	mid = head;
	node* fast = head;
	while (fast->next && fast->next->next){
		mid = mid->next;
		fast = fast->next->next;
	}
}
void Link1::searchmid2(node* head, node*& mid){//右中
	mid = head;
	node* fast = head;
	while (fast && fast->next){
		mid = mid->next;
		fast = fast->next->next;
	}
}
node* Link1::sort1(node* head){//从小到大排序 插入排序
	if (!head || !head->next) return head;
	int len = length(head);
	node* p = head;
	node* next = p->next;
	for (int i = 1; i < len; ++i){
		node* s = head;
		p = next;//找到要操作的节点
		int tmp = p->data;
		head = del(head, tmp);//删除节点p;
		int j = 0;
		while (tmp > s->data && j < i){//重头开始找第一个小于tmp的节点。然后在i位置处进行插入操作
			++j;
			s = s->next;
		}
		head = insert(head, j, tmp);
	}
	return head;
}

node* Link1::sort2(node* head){//选择排序
	if (!head || !head->next) return head;
	int len = length(head);
	node* p = head;
	node* s = p;
	for (int i = 1; i < len; ++i){
		for (int j = i; j < len; ++j){
			s = s->next;
			if (p->data > s->data){
				int tmp = p->data;
				p->data = s->data;
				s->data = tmp;
			}
		}
		p = p->next;
		s = p;
	}
	return head;
}

node* Link1::reverse(node* head){
	if (!head || !head->next) return head;
	node* pre = head;
	node* cur = head->next;
	node* next;
	while (cur){
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head->next = nullptr;
	return pre;
}
