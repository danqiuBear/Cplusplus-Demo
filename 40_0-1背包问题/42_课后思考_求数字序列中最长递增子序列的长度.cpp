#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	//��̬�滮���
	//a[0...i]�����������Ϊ��
	//a[i]֮ǰ����С������Ԫ�������г��ȵ����ֵ + 1
	int maxOrderedSeqDP(const vector<int> seq){
		//����һ�����飬����i��Ӧ����Ԫ�ص��±꣬�洢a[0...i]����������д�С
		//��ʼ��Ϊ1����Ϊ��С�ĳ���Ϊ1��
		vector<int> lss_lengths(seq.size(), 1);
		for (int i = 1; i < seq.size(); ++i){
			for (int j = 0; j < i; ++j){
				if (seq[i] > seq[j]){
					lss_lengths[i] = max(lss_lengths[j] + 1, lss_lengths[i]);
				}
			}
		}
		//���������ҵ�����������Ϊ����������еĴ�С
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