#include<iostream>
#include<vector>
using namespace std;

class Sort{//从小到大排序
public:


	void Print(vector<int> A);//打印数组
	void merge_sort(vector<int>& A, int n);//归并排序  时间复杂度O(nlogn)  空间复杂度O(n) 稳定算法
	void quick_sort(vector<int>& A, int n);//快排  时间复杂度最好O(nlogn) 平均O(nlogn), 最差O(n^2), 空间复杂度O(1) 不稳定的算法
	void bubbleSort(vector<int>& A, int n);//冒泡排序，最好O(n)，最坏，平均时间复杂度都是O(n^2), 空间复杂度为O(1),是原地排序稳定算法
	void selectionSort(vector<int>& A, int n);//选择排序，最好，最坏，平均时间复杂度都是O(n^2),是原地排序算法(空间复杂度为O(1))，不稳定
	void insertionSort(vector<int>& A, int n);//插入排序， 最好O(n)，最坏，平均时间复杂度都是O(n^2), 空间复杂度为O(1),是原地排序稳定算法
	void shellSort(vector<int>&A, int n);//希尔排序 时间复杂度是O（nlogn), 空间复杂度为O(1)  是直接插入排序的改进
	int kth_element(vector<int>& A, int n, int k);//O(n)时间复杂度找出无序数组中第k大元素，k=1,2,3,...  借用分区函数partition();
	void countingSort(vector<int>& A, int n);//计数排序，时间复杂度O(n)
	
	
	
private:
	
	void merge_sort_c(vector<int>& A, int p, int r);
	void merge(vector<int>& A, int p, int q, int r);

	void quick_sort_c(vector<int>& A, int p, int r);
	int  partition(vector<int>& A, int p, int r);
};
