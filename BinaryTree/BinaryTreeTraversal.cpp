#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"BinaryTreeTraversal.h"
#include<functional>
//#include<utility>
void CBinaryTreeTraversal::CreateLinkList(vector<int> const buf, ListNode*& head){//尾插法建立单链表
	ListNode* p = head;
	int len = buf.size();
	if (buf.empty()) return;

	ListNode *cur, *r;
	
	head = new ListNode(buf[0]);
	r = head;
	for (int i = 1; i < len; ++i){
		cur = new ListNode(buf[i]);
		r->next = cur;
		r = cur;
	}
}



vector<int> CBinaryTreeTraversal::PreorderTraversal1(TreeNode *root){
	vector<int> result;
	stack<const TreeNode*> s;
	if (root != nullptr){
		s.push(root);
	}
	while (!s.empty()){
		const TreeNode* p = s.top();
		s.pop();
		result.push_back(p->val);

		if (p->right != nullptr) s.push(p->right);
		if (p->left != nullptr) s.push(p->left);
	}
	return result;
}
vector<int> CBinaryTreeTraversal::PreorderTraversal2(TreeNode *root){
	vector<int>result;
	TreeNode *pre = nullptr;
	TreeNode *cur = root;
	while (cur != nullptr){
		if (cur->left == nullptr){
			result.push_back(cur->val);
			pre = cur;                   //cur刚刚被访问过
			cur = cur->right;
		}
		else{
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur){
				node = node->right;
			}
			if (node->right == nullptr){ //还没线索化，则建立线索
				result.push_back(cur->val); //仅这一行的位置与中序不同
				node->right = cur;
				pre = cur;                  //cur刚刚被访问过
				cur = cur->left;
			}
			else{
				node->right = nullptr;
				//pre = cur       不能有这句，因为cur之前被访问了！！！！！
				cur = cur->right;
			}
		}
	}
	
	return result;
}

vector<int> CBinaryTreeTraversal::InorderTraversal1(TreeNode *root){
	stack<TreeNode*> s;
	vector<int> result;
	TreeNode *p = root;
	while (!s.empty() || p != nullptr){
		if (p != nullptr){
			s.push(p);
			p = p->left;
		}
		else{
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p->right;
		}
	}
	return result;
}
vector<int> CBinaryTreeTraversal::InorderTraversal2(TreeNode *root){
	vector<int> result;
	TreeNode *pre = nullptr;
	TreeNode *cur = root;
	while (cur != nullptr){
		if (cur->left == nullptr){
			result.push_back(cur->val);
			pre = cur;
			cur = cur->right;
		}
		else{
			//查找前驱
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur){
				node = node->right;
			}
			if (node->right == nullptr){
				node->right = cur;//还没线索化，则建立线索
				//pre = cur  不能有这句，cur还没有被访问
				cur = cur->left;
			}
			else{//已经被线索化，则访问节点，并删除线索
				node->right = nullptr;
				result.push_back(cur->val);
				pre = cur;
				cur = cur->right;
			}
		}
	}
	return result;

}

vector<int> CBinaryTreeTraversal::PostorderTraversal1(TreeNode *root){
	vector<int> result;
	stack<TreeNode *> s;
	TreeNode *cur = root;
	TreeNode *pre = nullptr;

	do{
		while (cur != nullptr){
			s.push(cur);
			cur = cur->left;
		}
		pre = nullptr;
		while (!s.empty()){
			cur = s.top();
			s.pop();
			//右孩子不存在 或者已经被访问，访问之
			if (cur->right == pre){
				result.push_back(cur->val);
				pre = cur;//保存刚刚被访问过的节点
			}
			else{//当前节点不能访问，需要二次进栈
				s.push(cur);
				//先处理完右子树
				cur = cur->right;//即将被压入栈
				break;
			}
		}
	} while (!s.empty());
	return result;
}

vector<int> CBinaryTreeTraversal::PostorderTraversal2(TreeNode *root){
	vector<int> result;
	TreeNode dummy(-1);
	TreeNode *cur, *pre = nullptr;
	function< void(const TreeNode*) > visit = 
		[&result](const TreeNode* node){
		result.push_back(node->val);
	};
	dummy.left = root;
	cur = &dummy;
	while (cur != nullptr){
		if (cur->left == nullptr){
			pre = cur;  //必须要有
			cur = cur->right;
		}
		else{
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur){
				node = node->right;
			}
			if (node->right == nullptr){
				node->right = cur;
				pre = cur;
				cur = cur->left;
			}
			else{
				visit_reverse(cur->left, pre, visit);
				pre->right = nullptr;
				pre = cur;//必须要有
				cur = cur->right;
			}
		}
	}
	return result;
}

//逆转路径
void CBinaryTreeTraversal::reverse(TreeNode *from, TreeNode *to){
	TreeNode *x = from, *y = from->right, *z;
	if (from == to) return;

	while (x != to){
		z = y->right;
		y->right = x;
		x = y;
		y = z;
	}
}

//访问逆转后的路径上的所有节点
void CBinaryTreeTraversal::visit_reverse(TreeNode* from, TreeNode* to,
	function<void(const TreeNode*)>& visit){
	TreeNode *p = to;
	reverse(from, to);

	while (true)
	{
		visit(p);
		if (p == from)
			break;
		p = p->right;
	}

	reverse(to, from);
}


vector<vector<int>> CBinaryTreeTraversal::LevelOrder1(TreeNode *root){
	vector<vector<int>> result;
	traverse(root, 1, result);
	return result;
}

void CBinaryTreeTraversal::traverse(TreeNode* root, rsize_t level, vector<vector<int>>&result){
	if (root == nullptr) return;
	if (level > result.size()) result.push_back(vector<int>());
	result[level - 1].push_back(root->val);
	traverse(root->left, level + 1, result);
	traverse(root->right, level + 1, result);
}

vector<vector<int>> CBinaryTreeTraversal::LevelOrderBottom(TreeNode *root){
	vector<vector<int>> result;
	queue<TreeNode*> current, next;
	if (root == nullptr){ return result; }
	else{
		current.push(root);
		while (!current.empty()){
			vector<int> level;
			while (!current.empty()){
				TreeNode* node = current.front();
				current.pop();
				level.push_back(node->val);
				if (node->left != nullptr){ next.push(node->left); }
				if (node->right != nullptr){ next.push(node->right); }
			}
			result.push_back(level);
			swap(current, next);
		}
	}
	std::reverse(result.begin(), result.end());//***********************************************去掉此行就和LevelOrder1效果一样
	return result;
}


vector<vector<int>> CBinaryTreeTraversal::ZigzagLevelOrder1(TreeNode *root){
	vector<vector<int>> result;
	zigzag_traverse(root, 1, result,true);
	return result;
}
void CBinaryTreeTraversal::zigzag_traverse(TreeNode* root, rsize_t level, vector<vector<int>>&result, bool left_to_right){
	if (root == nullptr) return;
	if (level > result.size()){ result.push_back(vector<int>()); }
	if (left_to_right){
		result[level - 1].push_back(root->val);
	}
	else{
		result[level - 1].insert(result[level - 1].begin(), root->val);
	}
	zigzag_traverse(root->left, level + 1, result, !left_to_right);
	zigzag_traverse(root->right, level + 1, result, !left_to_right);
}

vector<vector<int>> CBinaryTreeTraversal::ZigzagLevelOrderBottom(TreeNode *root){
	vector<vector<int>> result;
	queue<TreeNode*>current, next;
	bool left_to_right = true;
	if (root == nullptr){ return result; }
	else{
		current.push(root);
	}
	while (!current.empty()){
		vector<int> level;
		while (!current.empty()){
			TreeNode* node = current.front();
			current.pop();
			level.push_back(node->val);
			if (node->left){ next.push(node->left); }
			if (node->right){ next.push(node->right); }
		}
		if (!left_to_right){
			std::reverse(level.begin(), level.end());////从下到上
		}
		result.push_back(level);
		swap(current, next);
		left_to_right = !left_to_right;	
	}
	std::reverse(result.begin(), result.end());
	return result;
}

//Recover Binary Search Tree
void CBinaryTreeTraversal::recoverTree1(TreeNode* root){
	vector<TreeNode*> list;
	vector<int> vals;
	vector<int> vals_new;
	//inorder(root, list, vals);
	ShowTraverse(vals);
	sort(vals.begin(), vals.end());
	for (int i = 0; i < list.size(); i++){
		list[i]->val = vals[i];
	}
	//inorder(root, list, vals_new);
	//ShowTraverse(vals_new);   //这两行用于测试

}
void CBinaryTreeTraversal::inorder(TreeNode* root, vector<TreeNode*> &list, vector<int>& vals){//中序遍历   左跟右
	stack<TreeNode*> s;
	TreeNode *p = root;
	while (!s.empty() || p != nullptr){
		if (p != nullptr){
			s.push(p);
			p = p->left;//当前元素有左孩子则入栈,没有则访问栈顶元素
		}
		else{ //最左边的节点已经入栈，则访问栈顶元素
			p = s.top();
			s.pop();
			vals.push_back(p->val);//访问当前节点说明其没有左孩子或者左孩子已经被访问，
			//所以下一步考虑其右孩子，再对其右孩子（若存在）考虑是否存在左右孩子
			list.push_back(p);
			p = p->right;//若已访问节点的存在右孩子，则将其有孩子入栈，否则继续访问之前入栈的栈顶节点
		}
	}
}

void CBinaryTreeTraversal::recoverTree2(TreeNode* root){
	pair<TreeNode*, TreeNode*> broken;
	TreeNode* prev = nullptr;
	TreeNode* cur = root;
	while (cur != nullptr)
	{
		if (!cur->left){
			detect(broken, prev, cur);/////**********************就当做是访问当前节点吧
			prev = cur;
			cur = cur->right;
		}
		else{
			TreeNode* node = cur->left;
			while (node->right && node->right != cur){
				node = node->right;
			}
			if (!node->right){
				node->right = cur;
				cur = cur->left;
			}
			else{
				node->right = nullptr;
				detect(broken, prev, cur);/////**********************就当做是访问当前节点吧
				prev = cur;
				cur = cur->right;
			}
		}
	}
	swap(broken.first->val, broken.second->val);
}

void CBinaryTreeTraversal::detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current){
	if (prev && prev->val > current->val){
		if (!broken.first){
			broken.first = prev;//找到第一个结点
		}
		broken.second = current;
	}
}

//Same Tree 判断两颗二叉树是否完全相同
bool CBinaryTreeTraversal::IsSameTree1(TreeNode* first, TreeNode* second){//递归版，时间复杂度O（n），空间复杂度O(log(n))
	if (!first && !second) return true;      //终止条件1  两棵树均为空树
	if (!first || !second) return false;     //终止条件2       其中一棵树为空树 另外一棵树为非空树   返回false
	return first->val == second->val         //三方合并  树的根节点val相等 &&  根节点的左子树完全相同  &&根节点的右子树完全相同  则两棵树完全相同
		&& IsSameTree1(first->left, second->left)
		&& IsSameTree1(first->right, second->right);
}

bool CBinaryTreeTraversal::IsSameTree2(TreeNode* first, TreeNode* second){//迭代版，时间复杂度O（n），空间复杂度O(log(n))
	stack<TreeNode*> s;
	s.push(first);
	s.push(second);
	while (!s.empty()){
		first = s.top();  s.pop();
		second = s.top(); s.pop();
		if (!first && !second) continue;
		if (!first || !second) return false;
		if (first->val != second->val) return false;
		
		s.push(first->left);
		s.push(second->left);

		s.push(first->right);
		s.push(second->right);
	}
	return true;
}

//判断一颗二叉树是否对称
bool CBinaryTreeTraversal::IsSymmetric1(TreeNode* root){//递归版本，时间复杂度O（n），空间复杂度O(log(n))
	if (!root) return true;
	return IsSymmetric1(root->left, root->right);

}
bool CBinaryTreeTraversal::IsSymmetric1(TreeNode* first, TreeNode* second){//函数的重载，递归版本
	if (!first && !second) return true;  //终止条件
	if (!first || !second) return false; //终止条件
	return first->val == second->val     //三方合并
		&& IsSymmetric1(first->left, second->right)
		&& IsSymmetric1(first->right, second->left); 
}

bool CBinaryTreeTraversal::IsSymmetric2(TreeNode* root){//迭代版，时间复杂度O（n），空间复杂度O(log(n))
	stack<TreeNode*> s;
	TreeNode* first;
	TreeNode* second;	
	if (!root) return true;
	s.push(root->left);
	s.push(root->right);
	while (!s.empty()) {
		first = s.top(); s.pop();
		second = s.top(); s.pop();

		if (!first && !second) continue;
		if (!first && !second) return false;

		if (first->val != second->val) return false;
		
		s.push(first->left);
		s.push(second->right);

		s.push(first->right);
		s.push(second->left);
	}
	return true;
	
}

//判断一棵树是否是平衡二叉树
bool CBinaryTreeTraversal::IsBalanced(TreeNode* root){
	return BalancedHeight(root) >= 0;
}
int CBinaryTreeTraversal::BalancedHeight(TreeNode *root){
	if (!root) return 0;  //终止条件
	int left = BalancedHeight(root->left);
	int right = BalancedHeight(root->right);
	if (left < 0 || right < 0 || abs(left - right) >= 2) return -1;//剪枝
	return max(left, right) + 1;//三方合并
}

void CBinaryTreeTraversal::Flatten1(TreeNode* root){//递归版本1  时间复杂度O（n),空间复杂度O(log(n))
	if (!root) return;//递归终止条件
	Flatten1(root->left);
	Flatten1(root->right);
	if (!root->left) return;
	TreeNode* p = root->left;
	while (p->right) { p = p->right; }//
	p->right = root->right;//合并链表
	root->right = root->left;
	root->left = nullptr;
}
void CBinaryTreeTraversal::Flatten2(TreeNode* root){//递归版本2  时间复杂度O（n),空间复杂度O(log(n))
	Flatten2(root, nullptr);

}
TreeNode* CBinaryTreeTraversal::Flatten2(TreeNode* root, TreeNode* tail){//递归版本2  时间复杂度O（n),空间复杂度O(log(n))
	if (!root) return tail;
	//若root->left!=nullptr,则 root->right = root->left;
	//若root->left==nullptr,则 root->right = tail;
	root->right = Flatten2(root->left, Flatten2(root->right, tail));
	root->left = nullptr;
	return root;

}
void CBinaryTreeTraversal::Flatten3(TreeNode* root){//迭代版本   时间复杂度O（n),空间复杂度O(log(n))  用栈和前序遍历的思想
	if (!root) return;
	stack<TreeNode*> s;
	s.push(root);
	TreeNode* p;
	while (!s.empty())
	{
		p = s.top();
		s.pop();

		if (p->right) s.push(p->right);
		if (p->left) s.push(p->left);
		if (!s.empty()) p->right = s.top();
		p->left = nullptr;
	}
}

void CBinaryTreeTraversal::Connect1(TreeLinkNode *root){//递归解法，时间复杂度O(n),空间复杂度O(1)
	if (!root) return;//递归终止条件
	TreeLinkNode dummy(-1);
	for (TreeLinkNode *curr = root, *prev = &dummy; curr; curr = curr->next){
		if (curr->left){
			prev->next = curr->left;
			prev = prev->next;
		}
		if (curr->right){
			prev->next = curr->right;
			prev = prev->next;
		}
	}
	Connect1(dummy.next);
}
void CBinaryTreeTraversal::Connect2(TreeLinkNode *root){//非递归解法，时间复杂度O(n),空间复杂度O(1)
	while (root) {
		TreeLinkNode * next = nullptr; // the first node of next level 
		TreeLinkNode * prev = nullptr; // previous node on the same level 
		for (; root; root = root->next) {
			if (!next) next = root->left ? root->left : root->right;
			if (root->left) {
				if (prev) prev->next = root->left;
				prev = root->left;
			}
			if (root->right) {
				if (prev) prev->next = root->right;
				prev = root->right;
			}
		}
		root = next; // turn to next level }
	}
}

int CBinaryTreeTraversal::NumTrees(int n){
	vector<int> f(n + 1, 0);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; ++i){
		for (int k = 0; k <= i-1; k++){
			f[i] += f[k] * f[i-1 - k];
		}
	}
	return f[n];
}

vector<TreeNode*> CBinaryTreeTraversal::GenerateTrees(int n){
	if (n == 0) return GenerateTrees(1, 0);
	return GenerateTrees(1, n);
}

vector<TreeNode*> CBinaryTreeTraversal::GenerateTrees(int start, int end){
	vector<TreeNode*> subTree;
	if (start > end){
		subTree.push_back(nullptr);
		return subTree;
	}
	for (int k = start; k <= end; ++k){
		vector<TreeNode*> leftSubs = GenerateTrees(start, k - 1);
		vector<TreeNode*> rightSubs = GenerateTrees(k + 1, end);
		for (auto i : leftSubs){
			for (auto j : rightSubs){
				TreeNode* node = new TreeNode(k);
				node->left = i;
				node->right = j;
				subTree.push_back(node);
			}
		}
	}
	return subTree;
}

bool CBinaryTreeTraversal::IsValidateBST(TreeNode* root){
	return IsValidateBST(root, INT_MIN, INT_MAX);
}
bool CBinaryTreeTraversal::IsValidateBST(TreeNode* root, int lower, int upper){
	if (root == nullptr) return true;
	return root->val > lower && root->val < upper &&
		IsValidateBST(root->left, lower, root->val) &&
		IsValidateBST(root->right, root->val, upper);
}


//5.3.5 Convert Sorted List to Binary Search Tree 将升序排列的链表转换成二叉搜索树
//分治法，自顶向下 时间复杂度O(n^2),空间复杂度O（logn)
TreeNode* CBinaryTreeTraversal::sortedListToBST(ListNode* head, int len){
	if (len == 0) return nullptr;
	int mid = len / 2 + 1;
	TreeNode* root = new TreeNode(nth_node(head, mid)->val);
	root->left = sortedListToBST(head, mid - 1);
	root->right = sortedListToBST(nth_node(head, mid + 1), len - mid);
	return root;

}
int CBinaryTreeTraversal::ListLength(ListNode* node){
	int n = 0;
	while (node){
		n++;
		node = node->next;
	}
	return n;
}
ListNode* CBinaryTreeTraversal::nth_node(ListNode* node, int n){
	while (--n){
		node = node->next;
	}
	return node;
}

TreeNode* CBinaryTreeTraversal::sortedListToBST2(ListNode*& list, int start, int end){
	if (start > end)return nullptr;
	int mid = start + (end - start) / 2;
	TreeNode* leftChild = sortedListToBST2(list, start, mid - 1);
	TreeNode* parent = new TreeNode(list->val);
	parent->left = leftChild;
	list = list->next;
	parent->right = sortedListToBST2(list, mid + 1, end);
	return parent;
}

//5.4 二叉树的递归
//5.4.1 Minimum Depth of Binary Tree 求二叉树的最小深度
int CBinaryTreeTraversal::minDepth(const TreeNode* root){
	return minDepth(root, false);
}
int CBinaryTreeTraversal::minDepth(const TreeNode* root, bool hasbrother){
	if (root == nullptr)return hasbrother ? INT_MAX : 0;
	return 1 + (min(minDepth(root->left, root->right != nullptr), minDepth(root->right, root->left != nullptr)));
}
//迭代版本
int CBinaryTreeTraversal::minDepth2( TreeNode* root){
	if (root == nullptr) return 0;
	int result = INT_MAX;
	stack<pair<TreeNode*, int>> s;
	s.push(std::make_pair( root, 1));
	while (!s.empty()){
		TreeNode* node = s.top().first;
		int depth = s.top().second;
		s.pop();
		if ( !node->left && !node->right)
			result = min(result, depth);
		if (node->left)
			s.push(std::make_pair(node->left, depth + 1));//深度控制， 剪枝
		if (node->right)
			s.push(std::make_pair(node->right, depth + 1));//深度控制，剪枝
	}
	return result;
}

//5.4.2 Maximum Depth of Binary Tree 求二叉树的最大深度
//递归版本
int CBinaryTreeTraversal::maxDepth(const TreeNode* root){
	if (!root) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

//5.4.3 Path Sum  判断二叉树从根节点到叶子节点是否存在一条路径的val的总和为Sum
bool CBinaryTreeTraversal::hasPathSum(TreeNode* root, int sum){
	if (!root) return false;
	if (!root->left && !root->right)
		return sum == root->val;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//5.4.4 Path SumII  返回二叉树从根节点到叶子节点中存在总和为Sum 的所有路径，以vector<vector<int>>的形式存储
vector<vector<int>> CBinaryTreeTraversal::pathSum(TreeNode* root, int sum){
	vector<vector<int>> result;
	vector<int> cur;
	pathSum(root, sum, cur, result);
	return result;
}
void CBinaryTreeTraversal::pathSum(TreeNode* root, int gap, vector<int>&cur, vector<vector<int>>& result){
	if (!root) return;

	cur.push_back(root->val);

	if (!root->left && !root->right){
		if (gap == root->val){
			result.push_back(cur);
		}
	}
	pathSum(root->left, gap - root->val, cur, result);
	pathSum(root->right, gap - root->val, cur, result);
	cur.pop_back();
}



//5.4.5 Binary Tree Maximum Path Sum  给定一颗二叉树，返回树种任意两个节点之间的路径的最大值
int CBinaryTreeTraversal::maxPathSum(TreeNode* root){
	max_sum = INT_MIN;
	dfs(root);
	return max_sum;
}
int CBinaryTreeTraversal::dfs(const TreeNode* root){
	if (!root)   return 0;
	int l = dfs(root->left);
	int r = dfs(root->right);
	int sum = root->val;
	if (l > 0) sum += l;
	if (r > 0) sum += r;//sum为以当前节点为父节点，左右子树加上当前节点所组成的所有路径中的最大值
	max_sum = max(max_sum, sum);
	return max(l, r) > 0 ? root->val + max(l, r) : root->val;//返回给父节点的当然是一个方向上的最大值啦
}

//5.4.6 Populatting Next Right Pointers in Each Node 给每个节点添加next右指针（此树是一颗完全二叉树）
//Connect1和Connect2均可解此题
void CBinaryTreeTraversal::Connect3(TreeLinkNode *root){
	Connect3(root, nullptr);
}
void CBinaryTreeTraversal::Connect3(TreeLinkNode *root, TreeLinkNode* sibling){
	if (!root) return;
	root->next = sibling;
	Connect3(root->left, root->right);
	if (sibling){
		Connect3(root->right, sibling->left);
	}
	else{
		Connect3(root->right, nullptr);
	}
}

//5.4.7 Sum Root to Leaf Numbers 返回由根到叶子节点所组成的数组的和
int CBinaryTreeTraversal::SumNums(TreeNode* root){
	return SumNumsDFS(root, 0);
}
int CBinaryTreeTraversal::SumNumsDFS(TreeNode* root, int sum){
	if (!root) return 0;
	if (!root->left && !root->right)
		return root->val + sum * 10;
	return SumNumsDFS(root->left, sum * 10 + root->val) +
		SumNumsDFS(root->right, sum * 10 + root->val);

}

void CBinaryTreeTraversal::ShowTraverse(vector<int> v){
	for (TElemType data1 : v){
		cout << data1 << " ";
	}
	cout << endl;                                                                                             
}

