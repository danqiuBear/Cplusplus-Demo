#include<iostream>
#include"BinaryTreeTraversal.h"

int main(){
	vector<int> buf1 = { 1, 2, 4, -1, 8, -1, -1, 5, 7, -1, -1, -1, 3, 6 };
	//vector<int> buf2 = { 1, 2, 4, 8, -1, -1, 9, -1,10, -1,11,-1, -1,12,13,-1,-1,14,-1,15,
	//	-1,-1,16,17,-1,19,-1,-1,18,20,22,-1,-1,23,-1,-1,21,24,-1,-1,25 };
	//vector<int> buf3 = { 1, 2, 3, -1, 4, 5, -1, -1, -1, -1, -1 };
	//vector<int> buf4 = { 1, 3, -1, -1, 2, -1, -1 };//层序遍历构建二叉树
	vector<int> buf5 = { 3, 1, 4, -1, -1, 2, -1, -1, -1 };//层序遍历构建二叉树
	vector<int> buf6 = { 5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1,  5, 1, -1, -1, -1, -1, -1, -1, -1, -1  };//层序遍历构建二叉树   题5.4.4中图
	vector<int> buf7 = { 1, 2, 2, 3, 4, 4, 3, 4, 5, 6, 7, 7, 6, 5, 4,//层序遍历构建对称二叉树
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	vector<int> buf8 = { 1, 2, 2, 3, 4, 4, 3, 4, 5, 6, 7, 7, 6, 5, 10,//层序遍历构建非对称二叉树
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	vector<int> buf9 = { 1, 2, -1, -1, 3, -1, 4, -1, 5 };//先序遍历构建非平衡二叉树
	vector<int> buf10 = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 7 };//先序遍历构建二叉树,测试connect()函数
	vector<int> buf11 = { 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7 };//先序遍历构建完全二叉树,测试Connect3()函数
	vector<int> preOrder = { 1, 2, 4, 5, 8, 3, 6, 7, 9 };
	vector<int> inOrder = { 4, 2, 8, 5, 1, 6, 3, 7, 9 };
	vector<int> postOrder = { 4, 8, 5, 2, 6, 9, 7, 3, 1 };

	int i = 0;
	TreeNode* NodeT;
	TreeNode* NodeT2;
	TreeNode* NodeT3;
	TreeNode* NodeT4;
	TreeNode* NodeT5;
	TreeNode* NodeT6;
	TreeNode* NodeT7;
	TreeNode* NodeT8;
	TreeNode* NodeT9;
	TreeLinkNode* NodeT10;//先序遍历构建二叉树,测试Connect()函数
	TreeLinkNode* NodeT11;//先序遍历构建完全二叉树,测试Connect3()函数
	CBinaryTreeTraversal BinaryTree;
	//BinaryTree.CreateBiTree(buf1, i, NodeT);//先序遍历构建二叉树

	//vector<TElemType> preorderTraversal1 = BinaryTree.PreorderTraversal1(NodeT);
	//BinaryTree.ShowTraverse(preorderTraversal1);

	//vector<TElemType> preorderTraversal2 = BinaryTree.PreorderTraversal2(NodeT);
	//BinaryTree.ShowTraverse(preorderTraversal2);

	//vector<TElemType> inorderTraversal1 = BinaryTree.InorderTraversal1(NodeT);
	//BinaryTree.ShowTraverse(inorderTraversal1);

	//vector<TElemType> inorderTraversal2 = BinaryTree.InorderTraversal2(NodeT);
	//BinaryTree.ShowTraverse(inorderTraversal2);

	//vector<TElemType> postorderTraversal1 = BinaryTree.PostorderTraversal1(NodeT);
	//BinaryTree.ShowTraverse(postorderTraversal1);
	
	//vector<TElemType> postorderTraversal2 = BinaryTree.PostorderTraversal2(NodeT);
	//BinaryTree.ShowTraverse(postorderTraversal2);
	/*
	vector<vector<TElemType> > levelOrder1 = BinaryTree.ZigzagLevelOrder1(NodeT);
	for (int j = 0; j < levelOrder1.size();j++){
		BinaryTree.ShowTraverse(levelOrder1[j]);
		//cout << endl;
	}
	vector<vector<TElemType> > levelOrder2 = BinaryTree.ZigzagLevelOrderBottom(NodeT);
	for (int j = 0; j < levelOrder2.size(); j++){
		BinaryTree.ShowTraverse(levelOrder2[j]);
		//cout << endl;
	}
	BinaryTree.CreateBiTree(buf1, i, NodeT);
	BinaryTree.CreateLevelOrderBiTree(buf5, i, NodeT5);//层序遍历构建二叉树
	//BinaryTree.recoverTree1(NodeT);
	BinaryTree.CreateLevelOrderBiTree(buf6, i, NodeT6);//层序遍历构建二叉树
	BinaryTree.CreateLevelOrderBiTree(buf7, i, NodeT7);//层序遍历构建对称二叉树
	BinaryTree.CreateLevelOrderBiTree(buf8, i, NodeT8);//层序遍历构建非对称二叉树
	BinaryTree.CreateBiTree(buf9, i=0, NodeT9);          //先序遍历构建非平衡二叉树
	cout << BinaryTree.IsSameTree1(NodeT, NodeT5) << endl;
	cout << BinaryTree.IsSameTree1(NodeT5, NodeT6) << endl;

	cout << "Symmetric:" << endl;
	cout << BinaryTree.IsSymmetric1(NodeT7) << endl; //true OK 
	cout << BinaryTree.IsSymmetric1(NodeT8) << endl; //false OK
	cout << BinaryTree.IsSymmetric2(NodeT7) << endl; //true OK
	cout << BinaryTree.IsSymmetric2(NodeT8) << endl; //false OK

	cout << "Balance:" << endl;
	cout << BinaryTree.IsBalanced(NodeT8) << endl; //true OK
	cout << BinaryTree.IsBalanced(NodeT9) << endl; //false OK
	
	BinaryTree.Flatten1(NodeT7);
	BinaryTree.Flatten1(NodeT8);
	BinaryTree.Flatten1(NodeT9);
	
	
	BinaryTree.CreateBiTree(buf10,  i = 0, NodeT10);
	BinaryTree.Connect1(NodeT10);*/

	//TreeNode* root1 = BinaryTree.buildTree1(preOrder, inOrder);
	TreeNode* root2 = BinaryTree.buildTree2(inOrder, postOrder);
	//cout << BinaryTree.NumTrees(4) << endl;

	//测试GenerateTrees方法
	vector<TreeNode*> subTrees = BinaryTree.GenerateTrees(4);
	cout << BinaryTree.IsValidateBST(root2) << endl;
	cout << BinaryTree.IsValidateBST(subTrees[1]) << endl;

	//测试将数组转换成搜索二叉树
	vector<int> num = { 1, 2, 3, 4, 5, 6, 7, 8 };
	TreeNode* numToBST = BinaryTree.SortedArrayToBST(num);
	ListNode* head;
	BinaryTree.CreateLinkList(num, head);//尾插法建立单链表
	TreeNode* listToBST2 = BinaryTree.sortedListToBST2(head);
	int minDepth = BinaryTree.minDepth2(listToBST2);//求最小深度
	int maxDepth = BinaryTree.maxDepth(listToBST2);//求最小深度
	cout << "minDepth: " << minDepth << endl;
	cout << "maxDepth: " << maxDepth << endl;
	BinaryTree.CreateLevelOrderBiTree(buf6, i, NodeT6);//层序遍历构建二叉树
	vector<vector<int>> pathSumVector = BinaryTree.pathSum(NodeT6, 22);

	//给定一颗二叉树，返回树中任意两个节点之间的路径的最大值，树图见5.4.4
	int maxPathSum = BinaryTree.maxPathSum(NodeT6);
	cout << "maxPathSum: " <<maxPathSum << endl;
	
	//先序遍历构建完全二叉树,测试Connect3()函数
	BinaryTree.CreateBiTree(buf11, i = 0, NodeT11);
	BinaryTree.Connect3(NodeT11);

	BinaryTree.CreateBiTree(buf9, i = 0, NodeT9);
	int sumNumbers = BinaryTree.SumNums(NodeT9);
	cout << "sumNumbers: " << sumNumbers << endl;//OK
	system("pause");
}