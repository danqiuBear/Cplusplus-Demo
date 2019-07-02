#include"heap.h"
void Heap::Print(vector<int> A){
	for (int i = 0; i < A.size(); ++i){
		cout << A[i] << " ";
	}
	cout << endl;
}

//�����ɾ��������������ʱ�临�Ӷȶ���O(logn)
//����һ�����ݵ�ʱ�����ǰ��²�������ݷŵ��������Ȼ��������϶ѻ�
void Heap::insert(int data){//���µ��ϲ���Ԫ��
	A.push_back(data);
	++count;
	int n = A.size()-1;//A[0]���洢�κ���
	while (n > 1){
		if (A[n] <= A[n / 2]){//֪���ӽڵ�С�ڸ��ڵ㣬�ѻ����
			break;
		}
		swap(A[n], A[n / 2]);//���ӽڵ���ڸ��ڵ㣬�򽻻�
		n /= 2;
	}
}

//ɾ���Ѷ�Ԫ�ص�ʱ�����ǰ����������һ��Ԫ�طŵ��Ѷ���Ȼ��������¶ѻ���
void Heap::removeMax(){//ɾ���������Ԫ�� ���ϵ��µ���
	if (count == 0)return;
	A[1] = A[count];//A[0]���洢�κ���, �����һ�������ɾ�������������Ȼ����жѻ�����
	--count;
	heapify(A, count, 1);//���±�Ϊ1�����ݽ��жѻ���countΪ���ݵĸ��������޶��˶ѻ����ݵķ�Χ
}


void Heap::heapify(vector<int>&A, int n, int i){//���±�Ϊi�����ݽ��жѻ���nΪ���������ݵĸ���
	if (n >= A.size())return;//�����±���1...n,����n<A.size();
	while (true){
		int maxPos = i;
		if (2 * i <= n && A[maxPos] < A[2 * i]) maxPos = 2 * i;				//!!!!!!!!!!!! '<='�еġ�=����������
		if (2 * i + 1 <= n && A[maxPos] < A[2 * i + 1])maxPos = 2 * i + 1;	//!!!!!!!!!!!! '<='�еġ�=����������
		if (maxPos == i) break;//���ڵ�Ⱥ��ӽڵ㶼�󣬶ѻ�����
		swap(A[i], A[maxPos]);
		i = maxPos;
	}
}

void Heap::buildHeap(vector<int>& B, int n){
	if (n >= B.size())return;//�����±���1...n,����n<A.size();
	for (int i = n / 2; i >= 1; --i){//���±��n/2��1�����ݽ��жѻ���ʹ���Ϊһ�����ѣ� ���ѵ�ʱ�临�Ӷ�ΪO(n)
		heapify(B, n, i);
	}
}

//����������������̣����Ѻ��������ǽ��±��n/2��1�Ľڵ㣬���ν��д��ϵ��µĶѻ�������Ȼ��Ϳ��Խ������е�����
//��֯�ɶ��������ݽṹ�������������ǵ����ؽ��Ѷ���Ԫ�طŵ���ĩβ�������Ѵ�С��һ��Ȼ���ٶѻ����ظ�������̣�ֱ������
//ֻʣ��һ��Ԫ�أ����������е����ݾͶ����������ˡ�
void Heap::sort(vector<int>& A, int n){
	if (n >= A.size())return;//�����±���1...n,����n<A.size();
	buildHeap(A, n);
	int k = n;
	while (k > 1){
		swap(A[1], A[k]);//������ŵ�����ĩβ
		--k;
		heapify(A, k, 1);//������A[1...k]�±�Ϊ1�Ľڵ���жѻ�����ʹ��������ڶѶ���
	}
	
}

