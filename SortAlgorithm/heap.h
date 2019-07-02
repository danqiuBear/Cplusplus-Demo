#include<iostream>
#include<vector>
using namespace std;
class Heap{
public:
	Heap(){
		A.push_back(0);
		count = 0;
	}
	void insert(int data);//��A�в���Ԫ�أ�ʹ����ȻΪ����
	void removeMax();//ɾ���Ѷ�Ԫ�أ�ʹʣ�µ�Ԫ����ȻΪ����,�������ϵ��µĶѻ����ڷ�ʽ
	void sort(vector<int>& A, int n);
	void Print(vector<int> A);//��ӡ����
	void Print()
	{
		for (int i = 1; i <= count; ++i){
			cout << A[i] << " ";
		}
		cout << endl;
	}
private:
	vector<int> A;
	int capacity;//��������������û���ڶ��з����ڴ棬��������ǿ��Բ�Ҫ��
	int count;//����Ԫ�صĸ���
	void heapify(vector<int>&A, int n, int i);//�ѻ�����A[i]Ϊ�Ѷ���ʼ�ѻ�
	void buildHeap(vector<int>& B, int n);//����������B���жѻ������±��n/2��1�����ݽ��жѻ���ʹ���Ϊһ�����ѣ� ���ѵ�ʱ�临�Ӷ�ΪO(n)
};