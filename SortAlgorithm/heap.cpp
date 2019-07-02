#include"heap.h"
void Heap::Print(vector<int> A){
	for (int i = 0; i < A.size(); ++i){
		cout << A[i] << " ";
	}
	cout << endl;
}

//插入和删除这两个操作的时间复杂度都是O(logn)
//插入一个数据的时候，我们把新插入的数据放到数组最后，然后从下往上堆化
void Heap::insert(int data){//从下到上插入元素
	A.push_back(data);
	++count;
	int n = A.size()-1;//A[0]不存储任何数
	while (n > 1){
		if (A[n] <= A[n / 2]){//知道子节点小于父节点，堆化完成
			break;
		}
		swap(A[n], A[n / 2]);//若子节点大于父节点，则交换
		n /= 2;
	}
}

//删除堆顶元素的时候，我们把数组中最后一个元素放到堆顶，然后从上往下堆化。
void Heap::removeMax(){//删除堆中最大元素 从上到下调整
	if (count == 0)return;
	A[1] = A[count];//A[0]不存储任何数, 用最后一个数来填补删除掉的最大数，然后进行堆化处理
	--count;
	heapify(A, count, 1);//对下表为1的数据进行堆化，count为数据的个数，即限定了堆化数据的范围
}


void Heap::heapify(vector<int>&A, int n, int i){//对下标为i的数据进行堆化。n为数组中数据的个数
	if (n >= A.size())return;//数组下标是1...n,所以n<A.size();
	while (true){
		int maxPos = i;
		if (2 * i <= n && A[maxPos] < A[2 * i]) maxPos = 2 * i;				//!!!!!!!!!!!! '<='中的‘=’不能落下
		if (2 * i + 1 <= n && A[maxPos] < A[2 * i + 1])maxPos = 2 * i + 1;	//!!!!!!!!!!!! '<='中的‘=’不能落下
		if (maxPos == i) break;//父节点比孩子节点都大，堆化结束
		swap(A[i], A[maxPos]);
		i = maxPos;
	}
}

void Heap::buildHeap(vector<int>& B, int n){
	if (n >= B.size())return;//数组下标是1...n,所以n<A.size();
	for (int i = n / 2; i >= 1; --i){//对下标从n/2到1的数据进行堆化，使其成为一个最大堆， 建堆的时间复杂度为O(n)
		heapify(B, n, i);
	}
}

//堆排序包括两个过程，建堆和排序。我们将下标从n/2到1的节点，依次进行从上到下的堆化操作，然后就可以将数组中的数据
//组织成堆这种数据结构。接下来，我们迭代地将堆顶的元素放到堆末尾，并将堆大小减一，然后再堆化，重复这个过程，直到堆中
//只剩下一个元素，整个数组中的数据就都有序排列了。
void Heap::sort(vector<int>& A, int n){
	if (n >= A.size())return;//数组下标是1...n,所以n<A.size();
	buildHeap(A, n);
	int k = n;
	while (k > 1){
		swap(A[1], A[k]);//最大数放到数组末尾
		--k;
		heapify(A, k, 1);//对数组A[1...k]下标为1的节点进行堆化处理，使得最大数在堆顶。
	}
	
}

