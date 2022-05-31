#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<ctime>
#include <opencv2/opencv.hpp>
using namespace cv;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void output_Mode()				// 输出模式
{
	cout.width(5);				//设置宽度
	cout.setf(std::ios::left);	//设置对齐方式为left
	cout.fill(' ');				//设置填充，缺省为空格
}

int main()
{
	Mat picture = imread("E:/MS/壁纸/C++.jpg", IMREAD_REDUCED_COLOR_8);  //图片的路径
	resize(picture, picture, Size(picture.cols / 2, picture.rows / 2));
	imshow("测试OpenCV", picture);
	waitKey(0);
	return 0;
}



typedef int ElemType;
struct TreeChainNode
{
	ElemType Data;
	TreeChainNode* LChild;
	TreeChainNode* RChild;

	TreeChainNode(ElemType D, TreeChainNode* L, TreeChainNode* R) {
		Data = D;
		LChild = L;
		RChild = R;
	}
};

int leafCounts(TreeChainNode* T)
{
	if (T->LChild == nullptr && T->RChild == nullptr)	return 1;
	int leafSum = 0;
	if (T->LChild)	leafSum += leafCounts(T->LChild);
	if (T->RChild)	leafSum += leafCounts(T->RChild);
	return leafSum;
}

void changeLR(TreeChainNode* T)
{
	if (T->LChild == nullptr && T->RChild == nullptr)	return;
	TreeChainNode* temp = T->LChild;
	T->LChild = T->RChild;
	T->RChild = temp;
	if (T->LChild)	changeLR(T->LChild);
	if (T->RChild)	changeLR(T->RChild);
}

void All(TreeChainNode* T)
{
	cout << T->Data << endl;
	if (T->LChild)	All(T->LChild);
	if (T->RChild)	All(T->RChild);
}


struct chainNode
{
	char element;
	chainNode* leftChild;
	chainNode* rightChild;
};

struct HuffmanTree
{
	int weight;                 //结点的权值
	int Lchild, Rchild, Parent; //存放左右结点,父结点下标
	char letter;                //存放所表示的字符
};

void toChain(HuffmanTree* Tree, int index, vector<chainNode*>& hufTreeNode)
{
	if (Tree[index].Lchild == 0 || Tree[index].Rchild == 0) {
		hufTreeNode[index]->leftChild = NULL;
		hufTreeNode[index]->rightChild = NULL;
		return;
	}
	hufTreeNode[index]->leftChild = hufTreeNode[Tree[index].Lchild];
	hufTreeNode[index]->rightChild = hufTreeNode[Tree[index].Rchild];

	toChain(Tree, Tree[index].Lchild, hufTreeNode);
	toChain(Tree, Tree[index].Rchild, hufTreeNode);
}

void preOrder(chainNode* T)
{
	if (T)
	{
		cout << T->element << " ";
		preOrder(T->leftChild);
		preOrder(T->rightChild);
	}
}

int H(int x)
{
	return (3 * x) % 11;
}

int main_1()
{
	vector<vector<int>>test;
	test.push_back({ 0,99 });
	test.push_back({ 1,25 });
	test.push_back({ 2,74 });

	vector<int> ts = test[0];
	test[0] = test[1];
	test[1] = ts;
	for (int i = 0; i < test.size(); i++)
		cout << test[i][0] << "   " << test[i][1] << endl;
	return 0;

	unsigned int temp = 1600000;

	cout << 0.000001 * temp << endl << 1 / (0.000001 * temp);

	unsigned int t1 = 1 / (0.000001 * temp);
	cout << endl << t1;

	return 0;
	vector<int> s(3);
	s[0] = 1; s[1] = 2; s[2] = 3;
	vector<int> t(3);
	t.insert(t.begin() + 0, s[0]);
	for (int k : t)
		cout << k << " ";
	return 0;

	cout << "32: " << H(32) << endl;
	cout << "13: " << H(13) << endl;
	cout << "49: " << H(49) << endl;
	cout << "24: " << H(24) << endl;
	cout << "38: " << H(38) << endl;
	cout << "21: " << H(21) << endl;
	cout << "4: " << H(4) << endl;
	cout << "12: " << H(12) << endl;
	return 0;

	int i = 10;
	int j = 12;
	i = i ^ j;
	j = j ^ i;
	i = i ^ j;
	cout << i << " " << j;
	return 0;

	const int n = 10;
	int dp[n][n];
	cout << sizeof(dp);
	return 0;

	HuffmanTree Tree[16];
	Tree[1].Parent = 9;		Tree[1].Lchild = 0;		Tree[1].Rchild = 0;
	Tree[2].Parent = 14;	Tree[2].Lchild = 0;		Tree[2].Rchild = 0;
	Tree[3].Parent = 10;	Tree[3].Lchild = 0;		Tree[3].Rchild = 0;
	Tree[4].Parent = 10;	Tree[4].Lchild = 0;		Tree[4].Rchild = 0;
	Tree[5].Parent = 12;	Tree[5].Lchild = 0;		Tree[5].Rchild = 0;
	Tree[6].Parent = 13;	Tree[6].Lchild = 0;		Tree[6].Rchild = 0;
	Tree[7].Parent = 9;		Tree[7].Lchild = 0;		Tree[7].Rchild = 0;
	Tree[8].Parent = 11;	Tree[8].Lchild = 0;		Tree[8].Rchild = 0;
	Tree[9].Parent = 11;	Tree[9].Lchild = 7;		Tree[9].Rchild = 1;
	Tree[10].Parent = 12;	Tree[10].Lchild = 3;	Tree[10].Rchild = 4;
	Tree[11].Parent = 13;	Tree[11].Lchild = 9;	Tree[11].Rchild = 8;
	Tree[12].Parent = 14;	Tree[12].Lchild = 5;	Tree[12].Rchild = 10;
	Tree[13].Parent = 15;	Tree[13].Lchild = 11;	Tree[13].Rchild = 6;
	Tree[14].Parent = 15;	Tree[14].Lchild = 2;	Tree[14].Rchild = 12;
	Tree[15].Parent = 0;	Tree[15].Lchild = 13;	Tree[15].Rchild = 14;
	for (int i = 1; i < 16; i++)
		Tree[i].letter = '0' + i - 1;

	int index_root = 1;
	while (Tree[index_root].Parent != 0)	index_root++;

	vector<chainNode*> hufTreeNode(16);
	for (int i = 1; i <= 15; i++) {
		hufTreeNode[i] = new chainNode;
		hufTreeNode[i]->element = Tree[i].letter;
	}
	toChain(Tree, index_root, hufTreeNode);

	chainNode* rootHuf = hufTreeNode[index_root];

	preOrder(rootHuf);

	return 0;
}



struct xy {
	int x;
	int y;
};
vector<xy> indexs;

int MidSubarrays(vector<int>& nums, int r, int x, int y)
{
	int first_zf = nums[r] - nums[r - 1];
	int left_index, right_index;
	int judge_right = 0;
	if (first_zf != 0) {
		int judge = (first_zf > 0) ? 1 : -1;
		judge_right = judge * -1;
		left_index = r - 1;
		while (left_index > x) {
			if ((nums[left_index] - nums[left_index - 1]) * judge >= 0)  break;
			left_index--;
			judge *= -1;
		}
	}
	else
		left_index = r;
	first_zf = nums[r + 1] - nums[r];
	if (first_zf != 0) {
		if (judge_right == 0)
			judge_right = (first_zf > 0) ? 1 : -1;
		right_index = r + 1;
		while (right_index < y) {
			if ((nums[right_index + 1] - nums[right_index]) * judge_right >= 0)  break;
			right_index++;
			judge_right *= -1;
		}
	}
	else
		right_index = r;
	indexs.push_back({ left_index,right_index });
	return (right_index == left_index) ? 1 : right_index - left_index + 1;
}

int LRSubarrays(vector<int>& nums, int x, int y)
{
	if (x == y)    return 1;
	if (x + 1 == y)  return 2;
	int index = x + 1;
	int first_zf = nums[index] - nums[x];
	if (first_zf != 0) {
		int judge = (first_zf > 0) ? 1 : -1;
		index++;
		while (index <= y) {
			if ((nums[index] - nums[index - 1]) * judge >= 0)    break;
			index++;
			judge *= -1;
		}
	}
	if (index > y) {
		indexs.push_back({ x,y });
		return y - x + 1;
	}

	int r = (x + y) / 2;
	int left_max = LRSubarrays(nums, x, r - 1);
	int right_max = LRSubarrays(nums, r + 1, y);
	int mid_max = MidSubarrays(nums, r, x, y);
	int largest_ = 0;
	if (left_max > right_max)  largest_ = left_max;
	else    largest_ = right_max;
	if (mid_max > largest_)    largest_ = mid_max;
	return largest_;
}

int wiggleMaxLength(vector<int>& nums) {
	return LRSubarrays(nums, 0, nums.size() - 1);
}

static bool cmp(const vector<int>& index1, const vector<int>& index2)
{
	if (index1.front() > index2.front())
		return true;
	return false;
}

int maxSumDivThree(vector<int>& nums) {
	vector<vector<int>>sum_index(nums.size(), vector<int>(2));
	sum_index[0][0] = nums[0];
	sum_index[0][1] = (nums[0] % 3 == 0) ? 1 : 0;
	for (int i = 1; i < nums.size(); i++) {
		if ((nums[i] + sum_index[i - 1][0]) % 3 == 0) {
			sum_index[i][0] = nums[i] + sum_index[i - 1][0];
			sum_index[i][1] = sum_index[i - 1][1] + 1;
		}
		else {
			int j = i - 2;
			while (j >= 0) {
				if ((nums[i] + sum_index[j][0]) % 3 == 0) {
					sum_index[i][0] = nums[i] + sum_index[j][0];
					sum_index[i][1] = sum_index[j][1] + 1;
					break;
				}
				j--;
			}
			if (j < 0) {
				sum_index[i][0] = nums[i];
				sum_index[i][1] = 1;
			}
		}
	}
	sort(sum_index.begin(), sum_index.end(), cmp);

	for (int i = 0; i < sum_index.size(); i++) {
		cout << sum_index[i][0] << " " << sum_index[i][1] << endl;
	}

	return sum_index[0][0];
}

//int main()
//{
//	int pField[7] = { 0,4,2,3,6,1,5 };
//	wchar_t* screan = new wchar_t[7];
//
//	for (int i = 0; i < 7; i++) {
//		screan[i] = L" ABCDE#"[pField[i]];
//		printf("%c ", screan[i]);
//	}
//
//	return 0;
//}









std::stack<int>right;
std::stack<int>left;
vector<int>Nsums;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int addVector(TreeNode* root);
bool isValidBST(TreeNode* root, int& theSum);
int addAllSums(TreeNode* root);

int maxSumBST(TreeNode* root) {
	int theSum = 0;
	if (isValidBST(root, theSum)) {
		int anotherSum = addAllSums(root);
		Nsums.clear();
		if (anotherSum > theSum)   return anotherSum;
		return theSum;
	}
	else {
		while (!right.empty())   right.pop();
		while (!left.empty())   left.pop();
		int Lsum = 0;
		int Rsum = 0;
		if (root->left)  Lsum = maxSumBST(root->left);
		if (root->right) Rsum = maxSumBST(root->right);
		if (Lsum > Rsum)   return Lsum;
		else    return Rsum;
	}
}

bool isValidBST(TreeNode* root, int& theSum) {
	if (root->right) {
		right.push(root->val);
		if (root->val >= root->right->val)  return false;
		else if (!left.empty() && root->right->val >= left.top())    return false;
		else if (!isValidBST(root->right, theSum))   return false;
		right.pop();
	}
	if (root->left) {
		left.push(root->val);
		if (root->val <= root->left->val)   return false;
		else if (!right.empty() && root->left->val <= right.top())    return false;
		else if (!isValidBST(root->left, theSum))    return false;
		left.pop();
	}
	theSum += root->val;
	return true;
}

int addAllSums(TreeNode* root)
{
	if (root->left)  addVector(root->left);
	if (root->right)  addVector(root->right);
	if (Nsums.empty())   return 0;
	sort(Nsums.begin(), Nsums.end());
	return Nsums[Nsums.size() - 1];
}

int addVector(TreeNode* root)
{
	if (!root->right && !root->left) { Nsums.push_back(root->val); return root->val; }
	else {
		int RightSum = 0;
		int LeftSum = 0;
		if (root->right) RightSum += addVector(root->right);
		if (root->left)  LeftSum += addVector(root->left);
		Nsums.push_back(RightSum + LeftSum + root->val);
		return RightSum + LeftSum + root->val;
	}
}

void MAIN()
{
	TreeNode* root8 = new TreeNode(10);
	TreeNode* root7 = new TreeNode(4, nullptr, root8);
	TreeNode* root6 = new TreeNode(-3);
	TreeNode* root5 = new TreeNode(-5, nullptr, root6);
	TreeNode* root4 = new TreeNode(1, root5, root7);
	TreeNode* root3 = new TreeNode(9);
	TreeNode* root2 = new TreeNode(6, root3, nullptr);
	TreeNode* root1 = new TreeNode(8, root2, root4);
	TreeNode* root = new TreeNode(4, root1, nullptr);
	cout << maxSumBST(root) << endl;
}



bool COMPARE(int x, int y)
{
	vector<int> X;
	while (x > 0) {
		X.push_back(x % 10);
		x /= 10;
	}
	vector<int> Y;
	while (y > 0) {
		Y.push_back(y % 10);
		y /= 10;
	}
	int i = X.size() - 1;
	int j = Y.size() - 1;
	while (i >= 0 && j >= 0) {
		if (X[i] < Y[j])
			return true;
		else if (X[i] > Y[j])
			return false;
		else {
			i--;
			j--;
		}
	}
	if (i < 0)	return true;
	else return false;
}

int PARTITION(int* A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
		if (COMPARE(A[j], x)) {
			i++;
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	int temp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = temp;
	return i + 1;
}

void QUICKSORT(int* A, int p, int r)
{
	if (p < r) {
		int q = PARTITION(A, p, r);
		QUICKSORT(A, p, q - 1);
		QUICKSORT(A, q + 1, r);
	}
}

void MERGE(int* A, int p, int q, int r)
{
	const int n1 = q - p + 1;
	const int n2 = r - q;
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	int i = 0;
	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	L[i] = 99999999;
	int j = 0;
	for (j = 0; j < n2; j++)
		R[j] = A[q + j + 1];
	R[j] = 99999999;
	for (int k = p, i = 0, j = 0; k < r; k++)
		if (COMPARE(L[i],R[j])) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	delete[]L;
	delete[]R;
}

void MERGE_SORT(int* A, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
}

void MAIN__fuck()
{
    long long nums;
    cin >> nums;
	int* input = new int[nums];
	for (int i = 0; i < nums; i++)
		cin >> input[i];
	for (int i = 0; i < nums; i++) {
		int theIndex = 0;
		for (int j = 1; j < nums; j++) {
			if (COMPARE(input[j], input[theIndex]))
				theIndex = j;
		}
		cout << input[theIndex] << ".mp4" << endl;
		input[theIndex] = 999999;
	}
	/*QUICKSORT(input, 0, nums - 1);
    for (int i = 0; i < nums; i++) {
        cout << input[i] << ".mp4" << endl;
    }*/
    //return 0;
}

/*DFS*/
//#include<iostream>
//#include<vector>
//using std::cin;
//using std::cout;
//using std::vector;
//
//long n;
//long long int result = 0;
//
//void DFS(int, int, long, int**);
//void DFS(int, int, long, vector<vector<int>>&);
//
//int main()
//{
//	long long int p;
//	cin >> n >> p;
//	vector<vector<int>>map(n, vector<int>(n, 0));
//	DFS(0, n - 1, 1, map);
//	result += (n - 1) * (n - 1);
//	cout << result % p;
//	/*long long int p;
//	cin >> n >> p;
//	int** map = new int* [n];
//	for (int i = 0; i < n; i++)
//		map[i] = new int[n];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			map[i][j] = 0;
//	DFS(0, n - 1, 1, map);
//	result += (n - 1) * (n - 1);
//	cout << result % p;*/
//	return 0;
//}
//
//void DFS(int x, int y, long counts, int** map)
//{
//	if (counts >= n * n)	return;
//	result++;
//	map[x][y] = 1;
//	if (x - 1 >= 0 && map[x - 1][y] != 1)	DFS(x - 1, y, counts + 1, map);
//	if (x + 1 < n && map[x + 1][y] != 1)	DFS(x + 1, y, counts + 1, map);
//	if (y - 1 >= 0 && map[x][y - 1] != 1)	DFS(x, y - 1, counts + 1, map);
//	if (y + 1 < n && map[x][y + 1] != 1)	DFS(x, y + 1, counts + 1, map);
//	map[x][y] = 0;
//}
//
//void DFS(int x, int y, long counts, vector<vector<int>>& map)
//{
//	if (counts >= n * n)	return;
//	result++;
//	map[x][y] = 1;
//	if (x - 1 >= 0 && map[x - 1][y] != 1)	DFS(x - 1, y, counts + 1, map);
//	if (x + 1 < n && map[x + 1][y] != 1)	DFS(x + 1, y, counts + 1, map);
//	if (y - 1 >= 0 && map[x][y - 1] != 1)	DFS(x, y - 1, counts + 1, map);
//	if (y + 1 < n && map[x][y + 1] != 1)	DFS(x, y + 1, counts + 1, map);
//	map[x][y] = 0;
//}



//class Solution {
//private:
//    vector<int> max_index;
//    vector<int> POSITION;
//public:
//    int maxDistance(vector<int>& position, int m)
//    {
//        vector<int> difference;
//        for (int i = 0; i < position.size() - 1; i++) {
//            difference.push_back(position[i + 1] - position[i]);
//            POSITION.push_back(position[i]);
//        }
//        POSITION.push_back(position[position.size() - 1]);
//        int max_temp = 0;
//        for (int i = 1; i <= m - 2; i++) {
//            int index = 0;
//            for (int j = 0; j < difference.size(); j++)
//                if (max_temp < difference[j]) {
//                    max_temp = difference[j];
//                    index = j;
//                }
//            difference[index] = -1;
//            max_index.push_back(index);
//        }
//        vector<int> indexs;
//        return Finding(m - 2, indexs);
//    }
//    int Finding(int m, vector<int> indexs)
//    {
//        if (m == 0)    return small_decence(indexs);
//        int result1;
//        int result2;
//        if (POSITION[max_index[max_index.size() - m]-1] != POSITION[0] &&
//            POSITION[max_index[max_index.size() - m]-1] != POSITION[POSITION.size() - 1]) {
//            indexs.push_back(max_index[max_index.size() - m]);
//            result1 = Finding(m - 1, indexs);
//            indexs.pop_back();
//        }
//        if (POSITION[max_index[max_index.size() - m]] != POSITION[0] &&
//            POSITION[max_index[max_index.size() - m]] != POSITION[POSITION.size() - 1]) {
//            indexs.push_back(max_index[max_index.size() - m]+1);
//            result2 = Finding(m - 1, indexs);
//        }
//        if (result1 < result2)
//            return result2;
//        else
//            return result1;
//    }
//    int small_decence(vector<int> indexs)
//    {
//        int small = 9999;
//        indexs.push_back(POSITION[0]);
//        indexs.push_back(POSITION[POSITION.size() - 1]);
//        sort(indexs.begin(), indexs.end());
//        for (int i = 0; i < indexs.size() - 1; i++) {
//            //int temp = POSITION[indexs[i + 1]-1] - POSITION[indexs[i]-1];
//            int temp = indexs[i + 1] - indexs[i];
//            if (small > temp)
//                small = temp;
//        }
//        return small;
//    }
//};
//
//void COUNTING_SORT(vector<vector<int>>& A, vector<vector<int>>& B, int max)
//{
//    vector<int> C(max + 1);
//    for (int i = 0; i <= max; i++)
//        C[i] = 0;
//    for (int j = 0; j < A.size(); j++)
//        C[A[j][1]]++;
//    for (int i = 1; i <= max; i++)
//        C[i] += C[i - 1];
//    for (int j = A.size()-1; j >= 0; j--) {
//        B[C[A[j][1]]][1] = A[j][1];
//        B[C[A[j][1]]][0]=A[j][0];
//        C[A[j][1]]--;
//    }
//}
//int removeCoveredIntervals(vector<vector<int>>& intervals) {
//    int length = intervals.size();
//    if (length == 1)   return 1;
//    int max = 0;
//    for (int i = 0; i < length; i++)
//        if (max < intervals[i][1])
//            max = intervals[i][1];
//    vector<vector<int>> result(length + 1, vector<int>(2));
//    COUNTING_SORT(intervals, result, max);
//    for (int i = 1; i < length + 1; i++)
//        cout << result[i][0] << " " << result[i][1] << endl;
//    return 1;
//}
//
//void MERGE(vector<vector<int>>& A, int p, int q, int r)
//{
//    int n1 = q - p + 1;
//    int n2 = r - q;
//    vector<vector<int>>L;
//    for (int i = 0; i < n1; i++)
//        L.push_back({ A[p + i][0],A[p + i][1] });
//    L.push_back({ -1,-1 });
//    vector<vector<int>>R;
//    for (int i = 1; i <= n2; i++)
//        R.push_back({ A[q + i][0],A[q + i][1] });
//    R.push_back({ -1,-1 });
//    int L_index = 0;
//    int R_index = 0;
//    for (int i = p; i <= r; i++) {
//        if (L[L_index] > R[R_index]) {
//            A[i][0] = L[L_index][0];
//            A[i][1] = L[L_index][1];
//            L_index++;
//        }
//        else {
//            A[i][0] = R[R_index][0];
//            A[i][1] = R[R_index][1];
//            R_index++;
//        }
//    }
//}
//void MERGE_SORT(vector<vector<int>>& A, int p, int r)
//{
//    if (p < r) {
//        int q = (p + r) / 2;
//        MERGE_SORT(A, p, q);
//        MERGE_SORT(A, q + 1, r);
//        MERGE(A, p, q, r);
//    }
//}
//
//#define MAXSIZE 20
//typedef int ElemType;
//typedef struct SqList
//{
//    ElemType* elem;
//    int length;
//};
//void deleteItem(SqList& L, ElemType item)
//{
//    int j = L.length;
//    int numsItem = 0;
//    for (int k = L.length - 1; k >= 0; k--) {
//        if (L.elem[k] != item) {
//            j = k + 1;
//            break;
//        }
//        L.length--;
//    }
//    for (int i = 0; i < L.length; i++) {
//        if (L.elem[i] == item) {
//            j--;
//            int temp = L.elem[i];
//            L.elem[i] = L.elem[j];
//            L.elem[j] = temp;
//            L.length--;
//        }
//    }
//}
//
//typedef struct Listnode
//{
//    ElemType elem;
//    struct Listnode* next;
//}ListNode,*LinkList;
//
//void nodeDecompose(LinkList& A)
//{
//    LinkList B = new ListNode{ 0, nullptr };
//    LinkList C = new ListNode{ 0, nullptr };
//    A = A->next;
//    while (A) {
//        if (A->elem < 0) {
//            LinkList temp = new ListNode{ A->elem, nullptr };
//            B->next = temp;
//            B = B->next;
//        }
//        else {
//            LinkList temp = new ListNode{ A->elem, nullptr };
//            C->next = temp;
//            C = C->next;
//        }
//        A = A->next;
//    }
//}
//
//void findIntersection(LinkList& A, LinkList& B)
//{
//    LinkList a = A;
//    if (a->elem > B->elem)
//        while (B && B->elem < a->elem)
//            B = B->next;
//    else
//        while (a && a->elem < B->elem)
//            a = a->next;
//    LinkList Ahead = a;
//    while (a->next && B->next && a->next->elem == B->next->elem) {
//        a = a->next;
//        B = B->next;
//    }
//    LinkList Atail = a;
//    A = Ahead;
//    Atail->next = nullptr;
//}
//
//int main()
//{
//    LinkList A = new ListNode{ 1, nullptr };
//    LinkList B = new ListNode{ 2, nullptr };
//    LinkList C = new ListNode{ 3, nullptr };
//    LinkList D = new ListNode{ 4, nullptr };
//    LinkList E = new ListNode{ 5, nullptr };
//    LinkList F = new ListNode{ 6, nullptr };
//    LinkList G = new ListNode{ 7, nullptr };
//    LinkList H = new ListNode{ 8, nullptr };
//    A->next = B;
//    B->next = C;
//    C->next = D;
//    D->next = E;
//    E->next = F;
//    F->next = G;
//    G->next = H;
//    LinkList a = new ListNode{ 3, nullptr };
//    LinkList b = new ListNode{ 4, nullptr };
//    LinkList c = new ListNode{ 5, nullptr };
//    LinkList d = new ListNode{ 6, nullptr };
//    LinkList e = new ListNode{ 7, nullptr };
//    LinkList f = new ListNode{ 8, nullptr };
//    LinkList g = new ListNode{ 9, nullptr };
//    LinkList h = new ListNode{ 10, nullptr };
//    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = e;
//    e->next = f;
//    f->next = g;
//    g->next = h;
//    findIntersection(A, a);
//    while (A) {
//        cout << A->elem << " ";
//        A = A->next;
//    }
//    cout << endl;
//
//    /*SqList L;
//    L.length = 6;
//    L.elem = new ElemType[6];
//    L.elem[0] = 3;
//    L.elem[1] = 2;
//    L.elem[2] = 7;
//    L.elem[3] = 2;
//    L.elem[4] = 5;
//    L.elem[5] = 2;
//    deleteItem(L, 2);
//    for (int i = 0; i < L.length; i++)
//        cout << L.elem[i] << " ";
//    cout << endl<<L.length << endl;*/
//    return 0;
//}
//
//int MAIN0()
//{
//    string text = "Keep calm and code on";
//    text[0] += 'a' - 'A';
//    vector<vector<int>> SortString;
//    int Index_string = 0;
//    int Length_word = 0;
//    for (int i = 0; i < text.length(); i++) {
//        if (text[i] == ' ' || i + 1 == text.length()) {
//            SortString.push_back({ Length_word,Index_string });
//            Index_string = i + 1;
//            Length_word = 0;
//            continue;
//        }
//        Length_word++;
//    }
//    SortString[SortString.size() - 1][0]++;
//    /*for (int i = 0; i < SortString.size(); i++) {
//        for (int j = 0; j < SortString[i].size(); j++)
//            cout << SortString[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;*/
//    MERGE_SORT(SortString, 0, SortString.size() - 1);
//    /*for (int i = 0; i < SortString.size(); i++) {
//        for (int j = 0; j < SortString[i].size(); j++)
//            cout << SortString[i][j] << " ";
//        cout << endl;
//    }*/
//    string result;
//    for (int i = SortString.size() - 1; i >= 0; i--) {
//        for (int j = 0; j < SortString[i][0]; j++)
//            result += text[SortString[i][1] + j];
//        if (i != 0) result += ' ';
//    }
//    result[0] -= 'a' - 'A';
//    cout<< result;
//    return 0;
//        //int n;
//    //cin >> n;
//    //    int rea = n;
//    //    for (int i = 2; i * i <= n; i++)
//    //        if (n % i == 0)//第一次找到的必为素因子
//    //        {
//    //            rea = rea - rea / i;
//    //            do
//    //                n /= i;//把该素因子全部约掉
//    //            while (n % i == 0);
//    //        }
//    //    if (n > 1)
//    //        rea = rea - rea / n;
//    //    cout << rea;
//    //    return 0;
//    
//}


/*
0100
0011
1100
0100

1100
0001
0011
1000
*/
/* 算24 */
//
//#include <algorithm> 
//using std::next_permutation;
//using std::prev_permutation;
// 
//#define ARRAY_SIZE 4
//
//bool search(double a[], const int x)
//{
//	if (x == 1 && fabs(a[0] - 24) <= 1e-6)	return true;
//	else if (x == 1)  return false;
//	double temp[ARRAY_SIZE];
//	for (int i = 0; i < x; i++)
//		temp[i] = a[i];
//	temp[x - 2] = a[x - 1] + a[x - 2];	if (search(temp, x - 1))return true;
//	temp[x - 2] = a[x - 1] - a[x - 2];	if (search(temp, x - 1))return true;
//	temp[x - 2] = a[x - 2] - a[x - 1];	if (search(temp, x - 1))return true;
//	temp[x - 2] = a[x - 1] * a[x - 2];	if (search(temp, x - 1))return true;
//	if (a[x - 2] != 0) {
//		temp[x - 2] = a[x - 1] / a[x - 2];	if (search(temp, x - 1))return true;
//	}
//	if (a[x - 1] != 0) {
//		temp[x - 2] = a[x - 2] / a[x - 1];	if (search(temp, x - 1))return true;
//	}
//	return false;
//}
//
//bool prem(double input[])
//{
//	double temp[ARRAY_SIZE];
//	for (int i = 0; i < ARRAY_SIZE; i++)
//		temp[i] = input[i];
//	do {
//		if (search(input, ARRAY_SIZE))
//			return true;
//	} while (next_permutation(input, input + ARRAY_SIZE));
//	while (prev_permutation(temp, temp + ARRAY_SIZE)) {
//		if (search(temp, ARRAY_SIZE))
//			return true;
//	}
//	return false;
//}
//
//int main()
//{
//	double input[ARRAY_SIZE];
//	while (1)
//	{
//		int sum = 0;
//		memset(input, 0, ARRAY_SIZE);
//		for (int i = 0; i < ARRAY_SIZE; i++) {
//			cin >> input[i];
//			sum += input[i];
//		}
//		if (sum == 0)break;
//
//		if (prem(input))
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}