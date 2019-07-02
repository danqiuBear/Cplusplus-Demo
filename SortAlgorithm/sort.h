#include<iostream>
#include<vector>
using namespace std;

class Sort{//��С��������
public:


	void Print(vector<int> A);//��ӡ����
	void merge_sort(vector<int>& A, int n);//�鲢����  ʱ�临�Ӷ�O(nlogn)  �ռ临�Ӷ�O(n) �ȶ��㷨
	void quick_sort(vector<int>& A, int n);//����  ʱ�临�Ӷ����O(nlogn) ƽ��O(nlogn), ���O(n^2), �ռ临�Ӷ�O(1) ���ȶ����㷨
	void bubbleSort(vector<int>& A, int n);//ð���������O(n)�����ƽ��ʱ�临�Ӷȶ���O(n^2), �ռ临�Ӷ�ΪO(1),��ԭ�������ȶ��㷨
	void selectionSort(vector<int>& A, int n);//ѡ��������ã����ƽ��ʱ�临�Ӷȶ���O(n^2),��ԭ�������㷨(�ռ临�Ӷ�ΪO(1))�����ȶ�
	void insertionSort(vector<int>& A, int n);//�������� ���O(n)�����ƽ��ʱ�临�Ӷȶ���O(n^2), �ռ临�Ӷ�ΪO(1),��ԭ�������ȶ��㷨
	void shellSort(vector<int>&A, int n);//ϣ������ ʱ�临�Ӷ���O��nlogn), �ռ临�Ӷ�ΪO(1)  ��ֱ�Ӳ�������ĸĽ�
	int kth_element(vector<int>& A, int n, int k);//O(n)ʱ�临�Ӷ��ҳ����������е�k��Ԫ�أ�k=1,2,3,...  ���÷�������partition();
	void countingSort(vector<int>& A, int n);//��������ʱ�临�Ӷ�O(n)
	
	
	
private:
	
	void merge_sort_c(vector<int>& A, int p, int r);
	void merge(vector<int>& A, int p, int q, int r);

	void quick_sort_c(vector<int>& A, int p, int r);
	int  partition(vector<int>& A, int p, int r);
};
