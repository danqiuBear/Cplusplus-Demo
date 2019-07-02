#include"Link1.h"
#include<iostream>
using namespace std;
int main(){
	Link1 lnode;
	node* head = lnode.creat();
	int len = lnode.length(head);
	lnode.Print(head);
	head = lnode.del(head, 2);
	lnode.Print(head);

	head = lnode.insert(head, 0, 9);
	lnode.Print(head);

	head = lnode.removeHead(head);
	lnode.Print(head);

	node* mid1 = (node*)malloc(sizeof(node));

	lnode.searchmid1(head, mid1);
	cout << "mid1->data: " << mid1->data << endl;

	lnode.searchmid2(head, mid1);
	cout << "mid2->data: " << mid1->data << endl;

	head = lnode.sort2(head);
	lnode.Print(head);

	head = lnode.reverse(head);
	lnode.Print(head);

	system("pause");
	return 0;
}