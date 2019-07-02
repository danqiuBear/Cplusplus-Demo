#include"sort.h"
#include"heap.h"
int main(){
	vector<int> A1 = { 1, 5, 6, 2, 3, 4 };
	vector<int> A2 = { 6, 11, 3, 9, 8 };
	vector<int> A3 = { 2, 5, 3, 0, 2, 3, 0, 3 };
	vector<int> A4 = { 49, 38, 65, 97, 76, 13, 27, 49, 55,44 };
	vector<int> A5 = { 0, 49, 38, 65, 97, 76, 13, 27, 49, 55, 44 };
	Sort s;
	cout << s.kth_element(A1, 6, 3) << endl;
	s.merge_sort(A1, 6);
	s.Print(A1);

	cout << s.kth_element(A2, 5, 3) << endl;
	s.quick_sort(A2, 5);
	s.Print(A2);

	s.countingSort(A3, 8);
	s.Print(A3);

	s.shellSort(A4, 10);
	s.Print(A4);

	Heap hp;
	hp.sort(A5, 10);
	hp.Print(A5);

	Heap hp2;
	hp2.insert(8);
	hp2.insert(5);
	hp2.insert(6);
	hp2.insert(35);
	hp2.insert(22);
	hp2.Print();
	hp2.removeMax();
	hp2.Print();
	system("pause");
	return 0;
}