#include"Link2.h"

dnode* DLink::creat(){
	dnode* head = (dnode*)malloc(sizeof(dnode));
	dnode* pre = head;
	int num;
	int cycle = 1;
	while (cycle){
		cout << "please input a number(int): ";
		cin >> num ;
		cout << endl;
		if (num != 0){
			dnode* cur = (dnode*)malloc(sizeof(dnode));
			cur->data = num;
			cur->pre = pre;
			pre->next = cur;
			pre = cur;
		}
		else{
			cycle = 0;
		}
	}
	pre->next = nullptr;
	head->next->pre = nullptr;
	return head->next;
}

void DLink::Print(dnode* head){
	dnode* p = head;
	while (p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

dnode* DLink::del(dnode* head, int num){
	dnode dummy;
	dummy.next = head;
	dnode* pre = &dummy;
	dnode* p = head;
	while (p){
		if (p->data == num){
			pre->next = p->next;
			p->next->pre = pre;
			free(p);
			break;//别把这一步忘了啊啊啊啊啊啊！！！！！！！！！！！！
		}
		pre = p;
		p = p->next;
	}
	return dummy.next;
}
dnode* DLink::insert(dnode* head, int i, int num){
	dnode *dummy = (dnode*)malloc(sizeof(dnode));
	dummy->next = head;
	dnode *p = dummy;
	while (i > 0 && p->next){
		p = p->next;
	}
	dnode* node = (dnode*)malloc(sizeof(dnode));
	node->data = num;
	node->next = p->next;
	node->pre = p;
	p->next = node;
	return dummy->next;
}