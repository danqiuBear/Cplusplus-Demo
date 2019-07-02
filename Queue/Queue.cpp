#include<iostream>
using namespace std;
typedef struct student{
	int data;
	struct student* next;
}node;
typedef struct linkqueue{
	node* first;
	node* rear;
}queue;
//队列的入队
queue *insert(queue *HQ, int x){
	node* q = (node*)malloc(sizeof(node));
	q->data = x;
	q->next = nullptr;

	if (nullptr == HQ->rear){
		HQ->first = q;
		HQ->rear = q;
	}
	else{
		HQ->rear->next = q;
		HQ->rear = q;
	}
	
	return HQ;
}
//队列的出队
queue *del(queue* HQ){
	node* q;
	int x;
	if (nullptr == HQ->first){
		return nullptr;
	}
	else{
		x = HQ->first->data;
		q = HQ->first;
		if (HQ->first == HQ->rear){
			HQ->first == nullptr;
			HQ->rear == nullptr;
		}
		else{
			HQ->first = HQ->first->next;
			free(q);
		}
	}
	return HQ;
}
void Print(queue* HQ){
	node* q = HQ->first;
	while (q){
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}
int main(){
	queue *HQ = (queue*)malloc(sizeof(queue));
	HQ->first = nullptr;
	HQ->rear = nullptr;
	insert(HQ, 1);
	Print(HQ);

	insert(HQ, 2);
	Print(HQ);

	insert(HQ, 3);
	Print(HQ);
	
	del(HQ);
	Print(HQ);
	
	insert(HQ, 4);
	Print(HQ);
	if (!HQ){
		free(HQ);
		HQ = nullptr;
	}
	
	system("pause");
	return 0;

}