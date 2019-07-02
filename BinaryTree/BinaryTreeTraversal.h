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

	template<typename T>//根据先序遍历的数组构建二叉树
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

	template<typename T>//根据层序遍历的数组构建二叉树
	void CreateLevelOrderBiTree(vector<int> const buf, int &i, T* &root){
		int head = 0, tail = 0;
		i = 0;
		T* Temp;
		vector<T*> sequence;//将二叉树节点存到容器中
		if (buf[i] == -1) return;
		else{
			root = new TreeNode(buf[i]);
			sequence.push_back(root);
			++tail;                  //每存入一个二叉树节点，尾部指针加1，相当于二叉树链表中有多少个二叉树节点，tail的数值就为多少
		}
		while (head < tail){
			if (buf[++i] != -1){      //若当前节点的左孩子不为空  则将其左孩子送入容器当中
				Temp = new T(buf[i]);
				sequence[head]->left = Temp;  //对每个sequence[head]节点进行判断，看其是否大于
				sequence.push_back(Temp);     //非空（-1）则进入容器当中
				++tail;              //每存入一个二叉树节点，尾部指针加1，相当于二叉树链表中有多少个二叉树节点，tail的数值就为多少
			}
			if (buf[++i] != -1){     //若当前节点的右孩子不为空  则将其左孩子送入容器当中
				Temp = new T(buf[i]);
				sequence[head]->right = Temp;
				sequence.push_back(Temp);   //非空（-1）则进入容器当中
				++tail;             //每存入一个二叉树节点，尾部指针加1，相当于二叉树链表中有多少个二叉树节点，tail的数值就为多少
			}
			head++;
		}
	}

	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder){//根据先序和中序遍历的数组构建二叉树
		return buildTree1(begin(preorder), end(preorder), begin(inorder), end(inorder));
	}

	TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder){//根据中序和后序遍历的数组构建二叉树
		return buildTree2(begin(inorder), end(inorder), begin(postorder), end(postorder));
	}

	//由数组建立单链表5.3.5需要用到的函数部分
	void CreateLinkList(vector<int> const buf, ListNode*& head);//尾插法建立单链表


	vector<int> PreorderTraversal1(TreeNode *root);//先序遍历，使用栈，时间复杂度O(n),空间复杂度O(n)
	vector<int> PreorderTraversal2(TreeNode *root);//使用Morris，时间复杂度O(n),空间复杂度O(1)

	vector<int> InorderTraversal1(TreeNode *root);//中序遍历，使用栈，时间复杂度O(n),空间复杂度O(n)
	vector<int> InorderTraversal2(TreeNode *root);//使用Morris，时间复杂度O(n),空间复杂度O(1)

	vector<int> PostorderTraversal1(TreeNode *root);//后序遍历，使用栈，时间复杂度O(n),空间复杂度O(n)
	vector<int> PostorderTraversal2(TreeNode *root);//使用Morris，时间复杂度O(n),空间复杂度O(1)

	vector<vector<int>> LevelOrder1(TreeNode *root);//层序遍历，从上层到底层，递归版，时间复杂度O(n),空间复杂度O(n)
	vector<vector<int>> LevelOrderBottom(TreeNode *root);//层序遍历，从底层到上层，迭代版，时间复杂度O(n),空间复杂度O(n) ，只比上一个层序遍历多一个reverse函数

	vector<vector<int>> ZigzagLevelOrder1(TreeNode *root);//Z字形层序遍历，从上层到底层，递归版，时间复杂度O(n),空间复杂度O(n)
	vector<vector<int>> ZigzagLevelOrderBottom(TreeNode *root);//Z字形层序遍历，从底层到上层，迭代版，时间复杂度O(n),空间复杂度O(n) ，只比上一个层序遍历多一个reverse函数

	//原理就是按照中序遍历将节点存入容器当中，同时将val存入另外一个容器当中，
	//再循环遍历存放节点的容器，将存放val的容器的数组依次赋予给节点即可
	void recoverTree1(TreeNode* root);     //Recover Binary Search Tree  时间复杂度O（n),空间复杂度O（n）  这个比较好理解  
	void recoverTree2(TreeNode* root);    //Recover Binary Search Tree   用Morris中序遍历，时间复杂度O（n),空间复杂度O（1）

	//Same Tree 判断两颗二叉树是否完全相同
	bool IsSameTree1(TreeNode* first, TreeNode* second);//递归版，时间复杂度O（n），空间复杂度O(log(n))
	bool IsSameTree2(TreeNode* first, TreeNode* second);//迭代版，时间复杂度O（n），空间复杂度O(log(n))

	//判断一颗二叉树是否对称
	bool IsSymmetric1(TreeNode* root);//递归版本，时间复杂度O（n），空间复杂度O(log(n))
	bool IsSymmetric1(TreeNode* first, TreeNode* second);//函数的重载，递归版本

	bool IsSymmetric2(TreeNode* root);//迭代版，时间复杂度O（n），空间复杂度O(log(n))

	//判断一棵树是否是平衡二叉树
	bool IsBalanced(TreeNode* root);
	int BalancedHeight(TreeNode *root);


	//将二叉树变成一条单链表
	void Flatten1(TreeNode* root);//递归版本1  时间复杂度O（n),空间复杂度O(log(n))
	void Flatten2(TreeNode* root);//递归版本2  时间复杂度O（n),空间复杂度O(log(n))
	void Flatten3(TreeNode* root);//迭代版本   时间复杂度O（n),空间复杂度O(log(n))  用栈和前序遍历的思想



	//Populating Next Right Pointers in Each NodeII
	//注意，以下代码原封不动，也能解决 Populating Next Right Pointers in Each NodeI（这里面二叉树是一颗完全二叉树）
	void Connect1(TreeLinkNode *root);//递归解法，时间复杂度O(n),空间复杂度O(1)
	void Connect2(TreeLinkNode *root);//非递归解法，时间复杂度O(n),空间复杂度O(1)

	//5.3 二叉查找树
	//5.3.1 Unique Binary Search Trees
	int NumTrees(int n);

	//5.3.2 Unique Binary Search TreesII 返回所生成的所有的二叉搜索树
	vector<TreeNode*> GenerateTrees(int n);

	//5.3.3 Validate Binary Search Tree  判断一棵树是否是搜索二叉树
	bool IsValidateBST(TreeNode* root);

	//5.3.4 Converted Sorted Array to Binary Search Tree 将升序排列的数组转换成二叉搜索树
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
	//5.3.5 Convert Sorted List to Binary Search Tree 将升序排列的链表转换成二叉搜索树
	//分治法，自顶向下 时间复杂度O(n^2),空间复杂度O（logn)
	TreeNode* sortedListToBST(ListNode* head){
		return sortedListToBST(head, ListLength(head));
	}
	TreeNode* sortedListToBST(ListNode* head, int len);
	int ListLength(ListNode* node);
	ListNode* nth_node(ListNode* node, int n);
	//5.3.5 Convert Sorted List to Binary Search Tree 将升序排列的链表转换成二叉搜索树
	//自底向上  ==》先求孩子，再求父亲
	TreeNode* sortedListToBST2(ListNode* head){
		return sortedListToBST2(head, 1, ListLength(head));
	}
	TreeNode* sortedListToBST2(ListNode*& list, int start, int end);

	//5.4 二叉树的递归
	//5.4.1 Minimum Depth of Binary Tree 求二叉树的最小深度
	//递归版本
	int minDepth(const TreeNode* root);
	int minDepth(const TreeNode* root, bool hasbrother);
	//迭代版本
	int minDepth2(TreeNode* root);


	//5.4.2 Maximum Depth of Binary Tree 求二叉树的最大深度
	//递归版本
	int maxDepth(const TreeNode* root);

	//5.4.3 Path Sum  判断二叉树从根节点到叶子节点是否存在一条路径的val的总和为Sum
	bool hasPathSum(TreeNode* root, int sum);

	//5.4.4 Path SumII  返回二叉树从根节点到叶子节点中存在总和为Sum 的所有路径，以vector<vector<int>>的形式存储
	vector<vector<int>> pathSum(TreeNode* root, int sum);
	void pathSum(TreeNode* root, int gap, vector<int>&cur, vector<vector<int>>& result);

	//5.4.5 Binary Tree Maximum Path Sum  给定一颗二叉树，返回树种任意两个节点之间的路径的最大值
	int maxPathSum(TreeNode* root);

	//5.4.6 Populatting Next Right Pointers in Each Node 给每个节点添加next右指针（此树是一颗完全二叉树）
	//Connect1和Connect2均可解此题
	void Connect3(TreeLinkNode *root);
	
	//5.4.7 Sum Root to Leaf Numbers 返回由根到叶子节点所组成的数组的和
	int SumNums(TreeNode* root);
	
	void ShowTraverse(vector<int> v);//遍历动态数组
private:

	//逆转路径==》后续遍历使用
	static void reverse(TreeNode *from, TreeNode *to);

	//访问逆转后的路径上的所有节点==》==》后续遍历使用
	static void visit_reverse(TreeNode* from, TreeNode* to, function<void(const TreeNode*)>& visit);

	void traverse(TreeNode* root, rsize_t level, vector<vector<int>>&result);
	void zigzag_traverse(TreeNode* root, rsize_t level, vector<vector<int>>&result, bool left_to_right);

	void inorder(TreeNode* root, vector<TreeNode*> &list, vector<int>& vals);

	//5.1.7 recover Binary Search Tree 用到的函数
	void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current);//5.1.7 recover Binary Search Tree 用到的函数

	TreeNode* Flatten2(TreeNode* root, TreeNode* tail); // 递归版本2  时间复杂度O（n), 空间复杂度O(log(n))

	template<typename InputIterator>//根据先序和中序遍历的数组构建二叉树
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

	template<typename InputIterator>//根据中序和后序遍历的数组构建二叉树
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

	//5.3.2 Unique Binary Search TreesII 返回所生成的所有的二叉搜索树
	vector<TreeNode*> GenerateTrees(int start, int end);

	//5.3.3 Validate Binary Search Tree  判断一棵树是否是搜索二叉树
	bool IsValidateBST(TreeNode* root, int lower, int upper);

	//5.4.5 Binary Tree Maximum Path Sum  给定一颗二叉树，返回树中任意两个节点之间的路径的最大值
	int max_sum;
	int dfs(const TreeNode* root);
	
	//5.4.6 Populatting Next Right Pointers in Each Node 给每个节点添加next右指针（此树是一颗完全二叉树）
	//Connect1和Connect2均可解此题
	void Connect3(TreeLinkNode *root, TreeLinkNode* sibling);

	//5.4.7 Sum Root to Leaf Numbers 返回由根到叶子节点所组成的数组的和
	int SumNumsDFS(TreeNode* root, int sum);
};