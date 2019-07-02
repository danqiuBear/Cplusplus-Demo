#include<iostream>
#include<vector>
using namespace std;
class Heap{
public:
	Heap(){
		A.push_back(0);
		count = 0;
	}
	void insert(int data);//往A中插入元素，使其依然为最大堆
	void removeMax();//删除堆顶元素，使剩下的元素依然为最大堆,这是自上到下的堆化调节方式
	void sort(vector<int>& A, int n);
	void Print(vector<int> A);//打印数组
	void Print()
	{
		for (int i = 1; i <= count; ++i){
			cout << A[i] << " ";
		}
		cout << endl;
	}
private:
	vector<int> A;
	int capacity;//由于用了容器，没有在堆中分配内存，所以这个是可以不要的
	int count;//堆中元素的个数
	void heapify(vector<int>&A, int n, int i);//堆化，以A[i]为堆顶开始堆化
	void buildHeap(vector<int>& B, int n);//对无序数组B进行堆化，对下标从n/2到1的数据进行堆化，使其成为一个最大堆， 建堆的时间复杂度为O(n)
};