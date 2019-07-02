#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"BinaryTreeTraversal.h"
#include<functional>
//#include<utility>
void CBinaryTreeTraversal::CreateLinkList(vector<int> const buf, ListNode*& head){//β�巨����������
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
			pre = cur;                   //cur�ոձ����ʹ�
			cur = cur->right;
		}
		else{
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur){
				node = node->right;
			}
			if (node->right == nullptr){ //��û����������������
				result.push_back(cur->val); //����һ�е�λ��������ͬ
				node->right = cur;
				pre = cur;                  //cur�ոձ����ʹ�
				cur = cur->left;
			}
			else{
				node->right = nullptr;
				//pre = cur       ��������䣬��Ϊcur֮ǰ�������ˣ���������
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
			//����ǰ��
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur){
				node = node->right;
			}
			if (node->right == nullptr){
				node->right = cur;//��û����������������
				//pre = cur  ��������䣬cur��û�б�����
				cur = cur->left;
			}
			else{//�Ѿ���������������ʽڵ㣬��ɾ������
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
			//�Һ��Ӳ����� �����Ѿ������ʣ�����֮
			if (cur->right == pre){
				result.push_back(cur->val);
				pre = cur;//����ոձ����ʹ��Ľڵ�
			}
			else{//��ǰ�ڵ㲻�ܷ��ʣ���Ҫ���ν�ջ
				s.push(cur);
				//�ȴ�����������
				cur = cur->right;//������ѹ��ջ
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
			pre = cur;  //����Ҫ��
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
				pre = cur;//����Ҫ��
				cur = cur->right;
			}
		}
	}
	return result;
}

//��ת·��
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

//������ת���·���ϵ����нڵ�
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
	std::reverse(result.begin(), result.end());//***********************************************ȥ�����оͺ�LevelOrder1Ч��һ��
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
			std::reverse(level.begin(), level.end());////���µ���
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
	//ShowTraverse(vals_new);   //���������ڲ���

}
void CBinaryTreeTraversal::inorder(TreeNode* root, vector<TreeNode*> &list, vector<int>& vals){//�������   �����
	stack<TreeNode*> s;
	TreeNode *p = root;
	while (!s.empty() || p != nullptr){
		if (p != nullptr){
			s.push(p);
			p = p->left;//��ǰԪ������������ջ,û�������ջ��Ԫ��
		}
		else{ //����ߵĽڵ��Ѿ���ջ�������ջ��Ԫ��
			p = s.top();
			s.pop();
			vals.push_back(p->val);//���ʵ�ǰ�ڵ�˵����û�����ӻ��������Ѿ������ʣ�
			//������һ���������Һ��ӣ��ٶ����Һ��ӣ������ڣ������Ƿ�������Һ���
			list.push_back(p);
			p = p->right;//���ѷ��ʽڵ�Ĵ����Һ��ӣ������к�����ջ�������������֮ǰ��ջ��ջ���ڵ�
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
			detect(broken, prev, cur);/////**********************�͵����Ƿ��ʵ�ǰ�ڵ��
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
				detect(broken, prev, cur);/////**********************�͵����Ƿ��ʵ�ǰ�ڵ��
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
			broken.first = prev;//�ҵ���һ�����
		}
		broken.second = current;
	}
}

//Same Tree �ж����Ŷ������Ƿ���ȫ��ͬ
bool CBinaryTreeTraversal::IsSameTree1(TreeNode* first, TreeNode* second){//�ݹ�棬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))
	if (!first && !second) return true;      //��ֹ����1  ��������Ϊ����
	if (!first || !second) return false;     //��ֹ����2       ����һ����Ϊ���� ����һ����Ϊ�ǿ���   ����false
	return first->val == second->val         //�����ϲ�  ���ĸ��ڵ�val��� &&  ���ڵ����������ȫ��ͬ  &&���ڵ����������ȫ��ͬ  ����������ȫ��ͬ
		&& IsSameTree1(first->left, second->left)
		&& IsSameTree1(first->right, second->right);
}

bool CBinaryTreeTraversal::IsSameTree2(TreeNode* first, TreeNode* second){//�����棬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))
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

//�ж�һ�Ŷ������Ƿ�Գ�
bool CBinaryTreeTraversal::IsSymmetric1(TreeNode* root){//�ݹ�汾��ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))
	if (!root) return true;
	return IsSymmetric1(root->left, root->right);

}
bool CBinaryTreeTraversal::IsSymmetric1(TreeNode* first, TreeNode* second){//���������أ��ݹ�汾
	if (!first && !second) return true;  //��ֹ����
	if (!first || !second) return false; //��ֹ����
	return first->val == second->val     //�����ϲ�
		&& IsSymmetric1(first->left, second->right)
		&& IsSymmetric1(first->right, second->left); 
}

bool CBinaryTreeTraversal::IsSymmetric2(TreeNode* root){//�����棬ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O(log(n))
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

//�ж�һ�����Ƿ���ƽ�������
bool CBinaryTreeTraversal::IsBalanced(TreeNode* root){
	return BalancedHeight(root) >= 0;
}
int CBinaryTreeTraversal::BalancedHeight(TreeNode *root){
	if (!root) return 0;  //��ֹ����
	int left = BalancedHeight(root->left);
	int right = BalancedHeight(root->right);
	if (left < 0 || right < 0 || abs(left - right) >= 2) return -1;//��֦
	return max(left, right) + 1;//�����ϲ�
}

void CBinaryTreeTraversal::Flatten1(TreeNode* root){//�ݹ�汾1  ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O(log(n))
	if (!root) return;//�ݹ���ֹ����
	Flatten1(root->left);
	Flatten1(root->right);
	if (!root->left) return;
	TreeNode* p = root->left;
	while (p->right) { p = p->right; }//
	p->right = root->right;//�ϲ�����
	root->right = root->left;
	root->left = nullptr;
}
void CBinaryTreeTraversal::Flatten2(TreeNode* root){//�ݹ�汾2  ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O(log(n))
	Flatten2(root, nullptr);

}
TreeNode* CBinaryTreeTraversal::Flatten2(TreeNode* root, TreeNode* tail){//�ݹ�汾2  ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O(log(n))
	if (!root) return tail;
	//��root->left!=nullptr,�� root->right = root->left;
	//��root->left==nullptr,�� root->right = tail;
	root->right = Flatten2(root->left, Flatten2(root->right, tail));
	root->left = nullptr;
	return root;

}
void CBinaryTreeTraversal::Flatten3(TreeNode* root){//�����汾   ʱ�临�Ӷ�O��n),�ռ临�Ӷ�O(log(n))  ��ջ��ǰ�������˼��
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

void CBinaryTreeTraversal::Connect1(TreeLinkNode *root){//�ݹ�ⷨ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
	if (!root) return;//�ݹ���ֹ����
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
void CBinaryTreeTraversal::Connect2(TreeLinkNode *root){//�ǵݹ�ⷨ��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
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


//5.3.5 Convert Sorted List to Binary Search Tree ���������е�����ת���ɶ���������
//���η����Զ����� ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O��logn)
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

//5.4 �������ĵݹ�
//5.4.1 Minimum Depth of Binary Tree �����������С���
int CBinaryTreeTraversal::minDepth(const TreeNode* root){
	return minDepth(root, false);
}
int CBinaryTreeTraversal::minDepth(const TreeNode* root, bool hasbrother){
	if (root == nullptr)return hasbrother ? INT_MAX : 0;
	return 1 + (min(minDepth(root->left, root->right != nullptr), minDepth(root->right, root->left != nullptr)));
}
//�����汾
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
			s.push(std::make_pair(node->left, depth + 1));//��ȿ��ƣ� ��֦
		if (node->right)
			s.push(std::make_pair(node->right, depth + 1));//��ȿ��ƣ���֦
	}
	return result;
}

//5.4.2 Maximum Depth of Binary Tree ���������������
//�ݹ�汾
int CBinaryTreeTraversal::maxDepth(const TreeNode* root){
	if (!root) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

//5.4.3 Path Sum  �ж϶������Ӹ��ڵ㵽Ҷ�ӽڵ��Ƿ����һ��·����val���ܺ�ΪSum
bool CBinaryTreeTraversal::hasPathSum(TreeNode* root, int sum){
	if (!root) return false;
	if (!root->left && !root->right)
		return sum == root->val;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

//5.4.4 Path SumII  ���ض������Ӹ��ڵ㵽Ҷ�ӽڵ��д����ܺ�ΪSum ������·������vector<vector<int>>����ʽ�洢
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



//5.4.5 Binary Tree Maximum Path Sum  ����һ�Ŷ������������������������ڵ�֮���·�������ֵ
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
	if (r > 0) sum += r;//sumΪ�Ե�ǰ�ڵ�Ϊ���ڵ㣬�����������ϵ�ǰ�ڵ�����ɵ�����·���е����ֵ
	max_sum = max(max_sum, sum);
	return max(l, r) > 0 ? root->val + max(l, r) : root->val;//���ظ����ڵ�ĵ�Ȼ��һ�������ϵ����ֵ��
}

//5.4.6 Populatting Next Right Pointers in Each Node ��ÿ���ڵ����next��ָ�루������һ����ȫ��������
//Connect1��Connect2���ɽ����
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

//5.4.7 Sum Root to Leaf Numbers �����ɸ���Ҷ�ӽڵ�����ɵ�����ĺ�
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

