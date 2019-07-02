#include<iostream>
using namespace std;
typedef struct student{
	int data;
	struct student* pre;
	struct student* next;
}dnode;
class DLink{
public:
	dnode* creat();
	void Print(dnode* head);
	dnode* del(dnode* head, int num);
	dnode* insert(dnode* head, int i, int num);
};