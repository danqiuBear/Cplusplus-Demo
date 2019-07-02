#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

class PalindromeLinkList{
public:
	PalindromeLinkList(){
		m_head = nullptr;
	}
	void insert(ListNode *node, int position);
	void Output();
	bool isPalindrome();
	ListNode* reverse(ListNode* head);
private:
	ListNode* m_head;
};
void PalindromeLinkList::insert(ListNode *node, int position){//插入操作  在第position的位置插入节点node
	if (m_head == nullptr){
		m_head = node;
		return;
	}
	if (position == 0){
		node->next = m_head;
		m_head = node;
		return;
	}
	ListNode *current_node = m_head;
	int i = 0;
	while (current_node->next != nullptr && i < position - 1){
		current_node = current_node->next;
		i++;
	}
	if (i == position - 1){
		node->next = current_node->next;
		current_node->next = node;
	}
}
void PalindromeLinkList::Output(){//打印链表
	if (m_head == nullptr){
		return;
	}
	ListNode *current_node = m_head;
	while (current_node != nullptr){
		cout << current_node->val << " ";
		current_node = current_node->next;
	}
	cout << endl;
}

bool PalindromeLinkList::isPalindrome(){//判断是否是回文
	ListNode *slow = m_head;
	ListNode *fast = m_head;
	ListNode *prev = nullptr;
	while (fast && fast->next){
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	prev->next = nullptr;//cut at middle
	ListNode *L1 = m_head; //链表的前半部分  ==>长度为N/2
	ListNode *L2 = reverse(slow);//链表的后半部分经过reverse ==>长度为N-N/2
	while (L1){
		if (L1->val == L2->val){
			L1 = L1->next;
			L2 = L2->next;
		}
		else
			return false;
	}
	return true;
}
ListNode* PalindromeLinkList::reverse(ListNode* head){//反转链表
	if (head == nullptr || head->next == nullptr) return head;
	ListNode* prev = head;
	for (ListNode* curr = head->next, *next = curr->next; curr;
		prev = curr, curr = next, next = next ? next->next : nullptr){
		curr->next = prev;
	}
	head->next = nullptr;
	return prev;
}
int main(){
	PalindromeLinkList list;
	for (int i = 1; i < 7; i++){
		ListNode *node = new ListNode(i);
		list.insert(node, i - 1);
	}
	for (int i = 8, j = 6; i > 0; i--, j++){
		ListNode *node = new ListNode(i);
		list.insert(node, j);
	}
	list.Output();

	bool ret = list.isPalindrome();
	list.Output();
	if (ret){
		cout << "IsPalindrome" << endl;
	}
	else{
		cout << "IsNotPalindrome" << endl;
	}
	system("pause");
	return 0;
}