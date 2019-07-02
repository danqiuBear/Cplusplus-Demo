#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	//动态规划求解
	//a[0...i]最长上升子序列为：
	//a[i]之前所有小于它的元素子序列长度的最大值 + 1
	int maxOrderedSeqDP(const vector<int> seq){
		//创建一个数组，索引i对应考察元素的下标，存储a[0...i]最长上升子序列大小
		//初始化为1（因为最小的长度为1）
		vector<int> lss_lengths(seq.size(), 1);
		for (int i = 1; i < seq.size(); ++i){
			for (int j = 0; j < i; ++j){
				if (seq[i] > seq[j]){
					lss_lengths[i] = max(lss_lengths[j] + 1, lss_lengths[i]);
				}
			}
		}
		//在数组里找到最大的数，即为最长上升子序列的大小
		int max_lss = 1;
		for (int i = 0; i < lss_lengths.size(); ++i){
			max_lss = max_lss > lss_lengths[i] ? max_lss : lss_lengths[i];
		}
		return max_lss;
	}

};

int main(){
	Solution s;
	vector<int> seq = { 2, 9, 3, 6, 5, 1, 7 };
	int maxSeqLen1 = s.maxOrderedSeqDP(seq);
	cout << "maxSeqLen1: " << maxSeqLen1 << endl;
	system("pause");
	return 0;
}