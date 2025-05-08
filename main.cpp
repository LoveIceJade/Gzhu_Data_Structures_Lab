#include "BiTree.h"

int main()
{
	//创建二叉树
	BTNode* root;
	char a[100] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	CreateBTree_Pre(root, a);

	//输出二叉树
	DispBtree(root);
	cout << endl;
	cout << endl;

	//H结点的孩子度数
	char H = 'H';
	cout << "'H'结点的孩子的度数是" << BTreeChildNum(root, H) << endl;

	//输出该二叉树的结点个数、叶子结点个数、二叉树的度和高度
	cout << "这棵树的结点个数是" << DegreeCount(root) << endl;
	cout << "这棵树的叶子数是" << LeafCount(root) << endl;
	cout << "这棵树的度是" << CountDegree(root) << endl;
	cout << "这棵树的高度是" << BTreeDepth(root) << endl;


	//下面是三种递归遍历
	cout << endl;
	cout << "下面是三种递归遍历" << endl;
	cout << "先序遍历：";
	PreOrder_01(root);
	cout << endl;
	cout << "中序遍历：";
	InOrder_01(root);
	cout << endl;
	cout << "后序遍历：";
	PostOrder_01(root);
	cout << endl;

	//下面是三种非递归遍历
	cout << endl;
	cout << "下面是三种非递归遍历" << endl;
	cout << "先序遍历：";
	PreOrder_02(root);
	cout << "中序遍历：";
	InOrder_02(root);
	cout << "后序遍历：";
	PostOrder_02(root);
	cout << endl;

	ClearBTree(root);  //销毁树
}