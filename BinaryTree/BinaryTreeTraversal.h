#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

typedef int Status;
typedef int TElemType;
struct TreeNode{
	TElemType val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(TElemType x) : val(x), left(nullptr), right(nullptr){ }
};

struct TreeLinkNode{
	TElemType val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(TElemType x) : val(x), left(nullptr), right(nullptr),next(nullptr){ }
};

struct ListNode{
	TElemType val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){ }
};
class CBinaryTreeTraversal{
public:

	template<typename T>//����������������鹹��������
	void CreateBiTree(vector<int> const buf, int &i, T* &root){

		if (i >= buf.size()) return;
		if (buf[i] == -1){
			root = nullptr;
		}
		else{
			root = new T(buf[i]);
			CreateBiTree(buf, ++i, root->left);
			CreateBiTree(buf, ++i, root->right);
		}
	}

	template<typename T>//���ݲ�����������鹹��������
	void CreateLevelOrderBiTree(vector<int> const buf, int &i, T* &root){
		int head = 0, tail = 0;
		i = 0;
		T* Temp;
		vector<T*> sequence;//���������ڵ�浽������
		if (buf[i] == -1) return;
		else{
			root = new TreeNode(buf[i]);
			sequence.push_back(root);
			++tail;                  //ÿ����һ���������ڵ㣬β��ָ���1���൱�ڶ������������ж��ٸ��������ڵ㣬tail����ֵ��Ϊ����
		}
		while (head < tail){
			if (buf[++i] != -1){      //����ǰ�ڵ�����Ӳ�Ϊ��  ��������������������
				Temp = new T(buf[i]);
				sequence[head]->left = Temp;  //��ÿ��sequence[head]�ڵ�����жϣ������Ƿ����
				sequence.push_back(Temp);     //�ǿգ�-1���������������
				++tail;              //ÿ����һ���������ڵ㣬β��ָ���1���൱�ڶ������������ж��ٸ��������ڵ㣬tail����ֵ��Ϊ����
			}
			if (buf[++i] != -1){     //����ǰ�ڵ���Һ��Ӳ�Ϊ��  ��������������������
				Temp = new T(buf[i]);
				sequence[head]->right = Temp;
				sequence.push_back(Temp);   //�ǿգ�-1���������������
				++tail;             //ÿ����һ���������ڵ㣬β��ָ���1���൱�ڶ������������ж��ٸ��������ڵ㣬tail����ֵ��Ϊ����
			}
			head++;
		}
	}

	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder){//���������������������鹹��������
		return buildTree1(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}

	TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder){//��������ͺ�����������鹹��������
		return buildTree2(begin(inorder), end(inorder), begin(postorder), end(postorder));
	}

	//�����齨��������5.3.5��Ҫ�õ��ĺ�������
	void CreateLinkList(vector<int> const buf, ListNode*& head);//β�巨����������


	vector<int> PreorderTraversal1(TreeNode *root);//���������ʹ��ջ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
	vector<int> PreorderTraversal2(TreeNode *root);//ʹ��Morris��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)

	vector<int> InorderTraversal1(TreeNode *root);//���������ʹ��ջ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
	vector<int> InorderTraversal2(TreeNode *root);//ʹ��Morris��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)

	vector<int> PostorderTraversal1(TreeNode *root);//���������ʹ��ջ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
	vector<int> PostorderTraversal2(TreeNode *root);//ʹ��Morris��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)

	vector<vector<int>> LevelOrder1(TreeNode *root);//������������ϲ㵽�ײ㣬�ݹ�棬ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
	vector<vector<int>> LevelOrderBottom(TreeNode *root);//����������ӵײ㵽�ϲ㣬�����棬ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n) ��ֻ����һ�����������һ��reverse����

	vector<vector<int>> ZigzagLevelOrder1(TreeNode *root);//Z���β�����������ϲ㵽�ײ㣬�ݹ�棬ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
	vector<vector<int>> ZigzagLevelOrderBottom(TreeNode *root);//Z���β���������ӵײ㵽�ϲ㣬�����棬ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n) ��ֻ����һ�����������һ��reverse����

	//ԭ����ǰ�������������ڵ�����������У�ͬʱ��val��������һ���������У�
	//��ѭ��������Žڵ�������������val���������������θ�����ڵ㼴��
	void recoverTree1(TreeNode* root);     //Recover Binary Search Tree  ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O��n��  ����ȽϺ����  
	void recoverTree2(TreeNode* root);    //Recover Binary Search Tree   ��Morris���������ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O��1��

	//Same Tree �ж����Ŷ������Ƿ���ȫ��ͬ
	bool IsSameTree1(TreeNode* first, TreeNode* second);//�ݹ�棬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))
	bool IsSameTree2(TreeNode* first, TreeNode* second);//�����棬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))

	//�ж�һ�Ŷ������Ƿ�Գ�
	bool IsSymmetric1(TreeNode* root);//�ݹ�汾��ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))
	bool IsSymmetric1(TreeNode* first, TreeNode* second);//���������أ��ݹ�汾

	bool IsSymmetric2(TreeNode* root);//�����棬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))

	//�ж�һ�����Ƿ���ƽ�������
	bool IsBalanced(TreeNode* root);
	int BalancedHeight(TreeNode *root);


	//�����������һ��������
	void Flatten1(TreeNode* root);//�ݹ�汾1  ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O(log(n))
	void Flatten2(TreeNode* root);//�ݹ�汾2  ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O(log(n))
	void Flatten3(TreeNode* root);//�����汾   ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O(log(n))  ��ջ��ǰ�������˼��



	//Populating Next Right Pointers in Each NodeII
	//ע�⣬���´���ԭ�ⲻ����Ҳ�ܽ�� Populating Next Right Pointers in Each NodeI���������������һ����ȫ��������
	void Connect1(TreeLinkNode *root);//�ݹ�ⷨ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
	void Connect2(TreeLinkNode *root);//�ǵݹ�ⷨ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)

	//5.3 ���������
	//5.3.1 Unique Binary Search Trees
	int NumTrees(int n);

	//5.3.2 Unique Binary Search TreesII ���������ɵ����еĶ���������
	vector<TreeNode*> GenerateTrees(int n);

	//5.3.3 Validate Binary Search Tree  �ж�һ�����Ƿ�������������
	bool IsValidateBST(TreeNode* root);

	//5.3.4 Converted Sorted Array to Binary Search Tree ���������е�����ת���ɶ���������
	TreeNode* SortedArrayToBST(vector<int>& num){
		return SortedArrayToBST(num.begin(), num.end());
	}
	template<typename RandomAccessIterator>
	TreeNode* SortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last){
		const auto length = distance(first, last);
		if (length <= 0) return nullptr;

		auto mid = first + length / 2;
		TreeNode* root = new TreeNode(*mid);
		root->left = SortedArrayToBST(first, mid);
		root->right = SortedArrayToBST(mid + 1, last);
		return root;
	}
	//5.3.5 Convert Sorted List to Binary Search Tree ���������е�����ת���ɶ���������
	//���η����Զ����� ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O��logn)
	TreeNode* sortedListToBST(ListNode* head){
		return sortedListToBST(head, ListLength(head));
	}
	TreeNode* sortedListToBST(ListNode* head, int len);
	int ListLength(ListNode* node);
	ListNode* nth_node(ListNode* node, int n);
	//5.3.5 Convert Sorted List to Binary Search Tree ���������е�����ת���ɶ���������
	//�Ե�����  ==�������ӣ�������
	TreeNode* sortedListToBST2(ListNode* head){
		return sortedListToBST2(head, 1, ListLength(head));
	}
	TreeNode* sortedListToBST2(ListNode*& list, int start, int end);

	//5.4 �������ĵݹ�
	//5.4.1 Minimum Depth of Binary Tree �����������С���
	//�ݹ�汾
	int minDepth(const TreeNode* root);
	int minDepth(const TreeNode* root, bool hasbrother);
	//�����汾
	int minDepth2(TreeNode* root);


	//5.4.2 Maximum Depth of Binary Tree ���������������
	//�ݹ�汾
	int maxDepth(const TreeNode* root);

	//5.4.3 Path Sum  �ж϶������Ӹ��ڵ㵽Ҷ�ӽڵ��Ƿ����һ��·����val���ܺ�ΪSum
	bool hasPathSum(TreeNode* root, int sum);

	//5.4.4 Path SumII  ���ض������Ӹ��ڵ㵽Ҷ�ӽڵ��д����ܺ�ΪSum ������·������vector<vector<int>>����ʽ�洢
	vector<vector<int>> pathSum(TreeNode* root, int sum);
	void pathSum(TreeNode* root, int gap, vector<int>&cur, vector<vector<int>>& result);

	//5.4.5 Binary Tree Maximum Path Sum  ����һ�Ŷ������������������������ڵ�֮���·�������ֵ
	int maxPathSum(TreeNode* root);

	//5.4.6 Populatting Next Right Pointers in Each Node ��ÿ���ڵ����next��ָ�루������һ����ȫ��������
	//Connect1��Connect2���ɽ����
	void Connect3(TreeLinkNode *root);
	
	//5.4.7 Sum Root to Leaf Numbers �����ɸ���Ҷ�ӽڵ�����ɵ�����ĺ�
	int SumNums(TreeNode* root);
	
	void ShowTraverse(vector<int> v);//������̬����
private:

	//��ת·��==����������ʹ��
	static void reverse(TreeNode *from, TreeNode *to);

	//������ת���·���ϵ����нڵ�==��==����������ʹ��
	static void visit_reverse(TreeNode* from, TreeNode* to, function<void(const TreeNode*)>& visit);

	void traverse(TreeNode* root, rsize_t level, vector<vector<int>>&result);
	void zigzag_traverse(TreeNode* root, rsize_t level, vector<vector<int>>&result, bool left_to_right);

	void inorder(TreeNode* root, vector<TreeNode*> &list, vector<int>& vals);

	//5.1.7 recover Binary Search Tree �õ��ĺ���
	void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current);//5.1.7 recover Binary Search Tree �õ��ĺ���

	TreeNode* Flatten2(TreeNode* root, TreeNode* tail); // �ݹ�汾2  ʱ�临�Ӷ�O��n), �ռ临�Ӷ�O(log(n))

	template<typename InputIterator>//���������������������鹹��������
	TreeNode* buildTree1(InputIterator pre_first, InputIterator pre_last,
		InputIterator in_first, InputIterator in_last){
		if (pre_first == pre_last){ return nullptr; }
		if (in_first == in_last){ return nullptr; }

		auto root = new TreeNode(*pre_first);

		auto inRootPos = find(in_first, in_last, *pre_first);
		auto leftSize = distance(in_first, inRootPos);

		root->left = buildTree1(next(pre_first), next(pre_first, 1 + leftSize), in_first, inRootPos);
		root->right = buildTree1(next(pre_first, 1 + leftSize), pre_last, next(inRootPos), in_last);

		return root;
	}

	template<typename InputIterator>//��������ͺ�����������鹹��������
	TreeNode* buildTree2(InputIterator in_first, InputIterator in_last, InputIterator post_first, InputIterator post_last){
		if (in_first == in_last){ return nullptr; }
		if (post_first == post_last){ return nullptr; }

		auto root = new TreeNode(*prev(post_last));

		auto inRootPos = find(in_first, in_last, *prev(post_last));
		auto leftSize = distance(in_first, inRootPos);

		root->left = buildTree2(in_first, inRootPos, post_first, next(post_first, leftSize));
		root->right = buildTree2(next(inRootPos), in_last, next(post_first, leftSize), prev(post_last));

		return root;
	}

	//5.3.2 Unique Binary Search TreesII ���������ɵ����еĶ���������
	vector<TreeNode*> GenerateTrees(int start, int end);

	//5.3.3 Validate Binary Search Tree  �ж�һ�����Ƿ�������������
	bool IsValidateBST(TreeNode* root, int lower, int upper);

	//5.4.5 Binary Tree Maximum Path Sum  ����һ�Ŷ������������������������ڵ�֮���·�������ֵ
	int max_sum;
	int dfs(const TreeNode* root);
	
	//5.4.6 Populatting Next Right Pointers in Each Node ��ÿ���ڵ����next��ָ�루������һ����ȫ��������
	//Connect1��Connect2���ɽ����
	void Connect3(TreeLinkNode *root, TreeLinkNode* sibling);

	//5.4.7 Sum Root to Leaf Numbers �����ɸ���Ҷ�ӽڵ�����ɵ�����ĺ�
	int SumNumsDFS(TreeNode* root, int sum);
};