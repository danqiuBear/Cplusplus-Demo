#include"sort.h"

void Sort::Print(vector<int> A){
	for (int i = 0; i < A.size(); ++i){
		cout << A[i] << " ";
	}
	cout << endl;
}

void Sort::merge_sort(vector<int>& A, int n){
	cout << "n is not legal" << endl;
	merge_sort_c(A, 0, n - 1);
}
void Sort::quick_sort(vector<int>& A, int n){
	cout << "n is not legal" << endl;
	quick_sort_c(A, 0, n - 1);
}

void Sort::bubbleSort(vector<int>& A, int n){
	if (n <= 1)return;
	for (int i = 0; i < n; ++i){
		bool flag = false;
		for (int j = 0; j < n - i - 1; ++j){
			if (A[j]>A[j + 1]){
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				flag = true;//表示有数据交换
			}
		}
		if (flag == false) break;
	}

}
void Sort::selectionSort(vector<int>& A, int n){
	if (n <= 1)return;
	for (int i = 0; i < n; ++i){
		int min = i;
		for (int j = i+1; j < n; ++j){
			if (A[min] > A[j]){
				min = j;
			}
		}
		swap(A[i], A[min]);
	}
}
void Sort::insertionSort(vector<int>& A, int n){
	if (n <= 1)return;
	for (int i = 1; i < n; ++i){
		int value = A[i];
		int j = i - 1;//寻找插入的位置
		for (; j>=0; --j){
			if (A[j] > value){
				A[j + 1] = A[j];//前面的大数往后移
			}
			else{
				break;
			}
		}
		A[j+1] = value;//插入数据
	}
}
void Sort::shellSort(vector<int>&A, int n){
	n = A.size();
	if (n <= 1)return;
	int left = 0;
	int right = n - 1;
	int d = n;
	while (d > 1){
		d = d/3+1;//经过验证，写成d = (d+1)/2会有错
		for (int i = left; i + d <= right; ++i){
			if (A[i] > A[i+d]){
				/*int tmp = A[i];
				A[i] = A[i + d];
				A[i + d] = tmp;*/
				swap(A[i], A[i + d]);
			}
		}
	}
}



int Sort::kth_element(vector<int>& A, int n, int k){
	if (k > n || n>A.size()) cout<<"n is not legal"<<endl;
	int p = 0;
	int r = n - 1;
	int q = partition(A, p, r);
	while (q + 1 != k){
		if (k < q + 1){
			r = q - 1;
			q = partition(A, p, r);
		}
		else{
			p = q + 1;
			q = partition(A, p, r);
		}
	}
	return A[q];
}

void Sort::countingSort(vector<int>& A, int n){//n=A.size()
	if (n <= 1)return;
	int max = A[0];
	for (int i = 1; i < n; ++i){//查找数组中数的范围
		if (max < A[i]){
			max = A[i];
		}
	}
	vector<int> c(max+1, 0);//申请一个计数数组
	for (int i = 0; i < n; ++i){//
		c[A[i]]++; 
	}
	//将计数数组依次累加
	for (int i = 1; i <= max; ++i){
		c[i] = c[i] + c[i - 1];
	}
	vector<int>r(n, 0);
	for (int i = 0; i < n; ++i){
		int index = c[A[i]] - 1;
		r[index] = A[i];
		c[A[i]]--;
	}
	for (int i = 0; i < n; ++i){
		A[i] = r[i];
	}

}



void Sort::merge_sort_c(vector<int>& A, int p, int r){
	if (p >= r) return;
	int q = (p + r) / 2;
	merge_sort_c(A, 0, q);
	merge_sort_c(A, q + 1, r);
	merge(A, p, q, r);
}
void Sort::merge(vector<int>& A, int p, int q, int r){
	vector<int> tmp(r - p + 1, 0);
	int i = p;
	int j = q + 1;
	int k = 0;
	while (i <= q && j <= r){
		if (A[i] <= A[j]){
			tmp[k++] = A[i++];
		}
		else{
			tmp[k++] = A[j++];
		}
	}
	while (i <= q){
		tmp[k++] = A[i++];
	}
	while (j <= r){
		tmp[k++] = A[j++];
	}
	for (int start = 0; start < k; ++start){
		A[p + start] = tmp[start];
	}
}

void Sort::quick_sort_c(vector<int>& A, int p, int r){
	if (p >= r)return;
	int q = partition(A, p, r);
	quick_sort_c(A, p, q - 1);
	quick_sort_c(A, q + 1, r);
}
int  Sort::partition(vector<int>& A, int p, int r){
	int i = p;
	for (int j = p; j < r; ++j){
		if (A[j] < A[r]){
			swap(A[i], A[j]);
			++i;
		}
	}
	swap(A[i], A[r]);
	return i;
}
