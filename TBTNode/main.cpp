#include"TBTNode.h"

int main()
{
	TBTNode* root;
	TreeInit(root);
	char a[100] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	CreateBTree_Pre(root, a);  // 创建一个非线索化二叉树
    DispBtree(root);  // 遍历二叉树（非线索）
	cout << endl;

	root = CreatThread(root);  // 中序线索化二叉树
	ThInOrder(root);  // 遍历线索化二叉树
	cout << endl;

	cout << "请输入你想查询的节点：" << endl;
	DataType node;
	cin >> node;
	FindPreAndNext(root, node);

	ClearBTree(root);  // 销毁二叉树
}
