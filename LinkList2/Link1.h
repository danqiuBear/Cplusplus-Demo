typedef struct student{
	int data;
	struct student* next;
}node;
class Link1{
public:
	node *creat();
	int length(node* head);
	void Print(node* head);
	node* del(node* head, int num);
	node* insert(node* head, int i, int num);
	node* removeHead(node* head);
	void searchmid1(node* head, node*& mid);
	void searchmid2(node* head, node*& mid);
	node* sort1(node* head);//��������  ��С��������
	node* sort2(node* head);//ð������  ��С��������
	node* reverse(node* head);
};