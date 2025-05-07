#include"Sort.h"

int num = 0;

//展示排序后的数组key
void ShowKey(ReeType R[],int n)
{
	cout << "该数组的key顺序是：";
	for (int i = 0; i < n; i++)
		cout << R[i].key << " ";
	cout << endl;
}

//展示排序次数
void ShowNum(int& num)
{
	cout << "此算法的排序次数是：" << num << endl;
}

//展示过程
void ShowPrecess(ReeType R[])
{
	for (int i = 0; i < 10; i++)
		cout << R[i].key << " ";
	cout << endl;
}

//展示排序后的数组
void Show(ReeType R[], int n, int& num)
{
	ShowKey(R, n);
	//ShowNum(num);
	cout << endl;
	num = 0;
}

//获取随机数数组
void GetRand(ReeType R[], ReeType A[], ReeType B[], ReeType C[], ReeType D[], ReeType E[])
{
	for (int i = 0; i < 10; i++)
	{
		R[i].key = (rand() % 90) + 10;
		A[i] = B[i] = C[i] = D[i] = E[i] = R[i];
	}
}


//获取随机数数组
void GetRand(ReeType R[])
{
	for (int i = 0; i < 10; i++)
		R[i].key = (rand() % 90) + 10;
}

//直插排序法
void InsertSort(ReeType R[], int n)
{
	if (n <= 1) return;

	for (int i = 1; i < n; i++)
	{
		ReeType temp;
		if (R[i].key < R[i - 1].key)
		{
			temp = R[i];
			int j = i - 1;
			do
			{
				R[j + 1] = R[j];
				j--;
				num++;
				//ShowPrecess(R);
			} while (j >= 0 && temp.key < R[j].key);
			R[j + 1] = temp;
		}
	}
	Show(R, n, num);
}

//冒泡排序法
void BubbletSort(ReeType A[], int n)
{
	if (n <= 1) return;

	ReeType temp;
	bool exchange;
	for (int i = 0; i < n - 1; i++)
	{
		exchange = false;
		for (int j = n-1; j > i; j--)
		{
			if (A[j].key < A[j - 1].key)
			{
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				exchange = true;
				num++;
				ShowPrecess(A);
			}
		}
		if (!exchange)
		{
			Show(A, n, num);
			return;
		}
	}
}

//双向冒泡排序法
void BubbletSort1(ReeType R[], int n)
{
	if (n <= 1) return;

	bool swapped = false;
	int start = 0, end = n - 1, i;
	ReeType temp;

	while (start < end) 
	{
		swapped = false;
		for (i = start; i < end; i++) 
		{
			if (R[i].key > R[i + 1].key) 
			{
				temp = R[i];
				R[i] = R[i + 1];
				R[i + 1] = temp;
				swapped = true;
				num++;  
				ShowPrecess(R);
			}
		}
		if (!swapped) 
			break;  

		swapped = false;
		end--; 
		for (i = end; i > start; i--) 
		{
			if (R[i].key < R[i - 1].key) 
			{ 
				temp = R[i];
				R[i] = R[i - 1];
				R[i - 1] = temp;
				swapped = true;
				num++;  
				ShowPrecess(R);
			}
		}
		start++;  
	}
	Show(R, n, num); 
}

//快速排序法
int partion(ReeType R[], int s, int t, int& n)
{
	ReeType base = R[t];         // 基准选择为 R[t]
	int i = s, j = t - 1;        // `j` 初始为 t - 1，因为 t 是基准

	while (i <= j)
	{
		while (i <= j && R[i].key <= base.key) // 从左边找到比基准大的元素
			i++;

		while (i <= j && R[j].key >= base.key) // 从右边找到比基准小的元素
			j--;

		if (i < j) 
		{
			ReeType temp = R[i];
			R[i] = R[j];
			R[j] = temp;
			n++;
			ShowPrecess(R);
		}
	}

	// 将基准值放到最终位置
	ReeType temp = R[i];
	R[i] = base;
	R[t] = temp;
	n++; // 记录基准交换
	ShowPrecess(R);

	return i; // 返回基准位置
}

void QuickSort(ReeType R[], int s, int t, int& n)
{
	if (s >= t) return; // 递归结束条件

	int i = partion(R, s, t, n); 
	QuickSort(R, s, i - 1, n);   // 左分区递归
	QuickSort(R, i + 1, t, n);   // 右分区递归
}


//堆排序法
void Sift(ReeType R[], int low, int high,int& no)
{
	int i = low, j = 2 * i + 1;
	ReeType temp = R[i];
	while (j <= high)
	{
		if (j + 1 <= high && R[j].key < R[j + 1].key)
			j++;
		if (temp.key < R[j].key)
		{
			R[i] = R[j];
			i = j;
			j = 2 * i + 1;
			no++;
			ShowPrecess(R);
		}
		else 
			break;
	}
	R[i] = temp;
}

void HeapSort(ReeType R[], int n, int& no)
{
	if (n <= 1) return;

	int i;
	ReeType temp;
	for (i = n / 2-1; i >= 0; --i)
		Sift(R, i, n-1, no);
	for (i = n-1; i > 0; --i)
	{
		temp = R[0];
		R[0] = R[i];
		R[i] = temp;
		no++;
		ShowPrecess(R);
		Sift(R, 0, i - 1, no);
	}
}

//二路归并排序法
void Merge(ReeType R[], int low, int mid, int high,int &no)
{
	if (high <= low) return;

	ReeType* R1;
	int i = low, j = mid + 1, k = 0;
	R1 = new ReeType[high - low + 1];
	while (i <= mid && j <= high)
	{
		if (R[i].key <= R[j].key)
		{
			R1[k] = R[i];
			i++; 
		}
		else 
		{
			R1[k] = R[j];
			j++; 
		}
		k++;
	}
	while (i <= mid)
	{
		R1[k] = R[i];
		i++; k++;
	}
	while (j <= high)
	{
		R1[k] = R[j];
		j++; k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)
		R[i] = R1[k];
	delete[]R1;
	no++;
	ShowPrecess(R);
}

void MergePass(ReeType R[], int length, int n, int& no)
{
	int i;
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
		Merge(R, i, i + length - 1, i + 2 * length - 1, no);
	if (i + length - 1 < n - 1)
		Merge(R, i, i + length - 1, n - 1, no);
}

void MergeSort(ReeType R[], int n, int& no)
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n, no);
}

//获取随机16个字母数组（字母不重复）
void GetRand(char* ch)
{
	bool used[26] = { false };  //标记已经使用过的字母
	int count = 0;
	srand(time(0));

	while (count < 16)
	{
		int randIndex = rand() % 26;  

		if (!used[randIndex])  //检查字母是否重复
		{
			ch[count] = 'a' + randIndex;
			used[randIndex] = true;
			count++;
		}
	}

	cout << "这个数组的元素是：";
	for (int i = 0; i < 16; i++)
		cout << ch[i] << " ";
	cout << endl;
}

//顺序查找
void SeqSearch(char R[], KeyType k)
{
	for (int i = 0; R[i] != '\0'; i++)
		if (R[i] == k)
		{
			cout << "查找成功！其是第" << i + 1 << "个元素" << endl;
			return;
		}
	cout << "查找失败，没有这个元素" << endl;
}

//非递归二分查找
int BinSearch_0(ReeType R[], KeyType k, int n)
{
	num = 0;
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		num++;
		mid = (low + high) / 2;
		if (R[mid].key == k)
		{
			cout << "查找成功！查找的次数是：" << num << endl;
			return mid + 1;
		}
		if (k < R[mid].key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << "查找失败！查找的次数是：" << num << endl;
	return 0;
}

//递归二分查找
int BinSearch_1(ReeType R[], KeyType k, int low, int high)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (R[mid].key == k)
			return mid + 1;
		if (R[mid].key > k)
			BinSearch_1(R, k, mid - 1, high);
		else
			BinSearch_1(R, k, low, mid + 1);
	}
	else 
		return 0;
}

//插入排序二叉树的一个结点
BSTNode* InsertBSTNode(BSTNode*& root, char k)
{
	if (root == nullptr)
	{
		root = new BSTNode;
		root->key = k;
		root->lchild = root->rchild = nullptr;
		return root;
	}
	if (root->key > k)
		root->lchild = InsertBSTNode(root->lchild, k);
	else
		root->rchild = InsertBSTNode(root->rchild, k);
	return root;
}

//生成二叉排序树
void CreatBSTree(BSTNode*& root, char* ch)
{
	root = nullptr;
	for (int i = 0; i < 10; i++)
		InsertBSTNode(root, ch[i]);
}

//递归输出先序序列
void PreOrder(BSTNode* root)
{
	if (root == nullptr)
		return;
	cout << root->key << " ";
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

//递归输出中序序列
void InOrder(BSTNode* root)
{
	if (root == nullptr) 
		return;
	InOrder(root->lchild);
	cout << root->key << " ";
	InOrder(root->rchild);
}

//二叉排序树的非递归查找
BSTNode* SearchBST_0(BSTNode* root, KeyType k)
{
	while (root != nullptr)
	{
		if (root->key == k)
			return root;
		if (root->key > k)
			root = root->lchild;
		else
			root = root->rchild;
	}
	return nullptr;
}

//二叉排序树的递归查找
BSTNode* SearchBST_1(BSTNode* root, KeyType k)
{
	if (root == nullptr || root->key == k)
		return root;
	if (root->key > k)
		return SearchBST_1(root->lchild, k);
	else
		return SearchBST_1(root->rchild, k);
}

//快速排序算法
int partion1(ReeType R[], int s, int t, int& n)
{
	int i = s, j = t;
	ReeType base = R[i];
	while (i < j)
	{
		while (i < j && base.key <= R[j].key)
			j--;
		if (i < j)
		{
			R[i] = R[j];
			i++;
			n++;
		}
		while (i < j && R[j].key <= base.key)
			i++;
		if (i < j)
		{
			R[j] = R[i];
			j--;
			n++;
		}
	}
	R[i] = base;
	return i;
}