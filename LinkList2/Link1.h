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
	node* sort1(node* head);//插入排序  从小到大排序
	node* sort2(node* head);//冒泡排序  从小到大排序
	node* reverse(node* head);
};