#include"Link2.h"
int main(){
	DLink dlink;
	dnode*head = dlink.creat();
	dlink.Print(head);

	head = dlink.del(head, 2);
	dlink.Print(head);

	head = dlink.insert(head, 0, 9);
	dlink.Print(head);

	system("pause");
	return 0;
}