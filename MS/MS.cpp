#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> max_index;
    vector<int> POSITION;
public:
    int maxDistance(vector<int>& position, int m)
    {
        vector<int> difference;
        for (int i = 0; i < position.size() - 1; i++) {
            difference.push_back(position[i + 1] - position[i]);
            POSITION.push_back(position[i]);
        }
        POSITION.push_back(position[position.size() - 1]);
        int max_temp = 0;
        for (int i = 1; i <= m - 2; i++) {
            int index = 0;
            for (int j = 0; j < difference.size(); j++)
                if (max_temp < difference[j]) {
                    max_temp = difference[j];
                    index = j;
                }
            difference[index] = -1;
            max_index.push_back(index);
        }
        vector<int> indexs;
        return Finding(m - 2, indexs);
    }
    int Finding(int m, vector<int> indexs)
    {
        if (m == 0)    return small_decence(indexs);
        int result1;
        int result2;
        if (POSITION[max_index[max_index.size() - m]-1] != POSITION[0] &&
            POSITION[max_index[max_index.size() - m]-1] != POSITION[POSITION.size() - 1]) {
            indexs.push_back(max_index[max_index.size() - m]);
            result1 = Finding(m - 1, indexs);
            indexs.pop_back();
        }
        if (POSITION[max_index[max_index.size() - m]] != POSITION[0] &&
            POSITION[max_index[max_index.size() - m]] != POSITION[POSITION.size() - 1]) {
            indexs.push_back(max_index[max_index.size() - m]+1);
            result2 = Finding(m - 1, indexs);
        }
        if (result1 < result2)
            return result2;
        else
            return result1;
    }
    int small_decence(vector<int> indexs)
    {
        int small = 9999;
        indexs.push_back(POSITION[0]);
        indexs.push_back(POSITION[POSITION.size() - 1]);
        sort(indexs.begin(), indexs.end());
        for (int i = 0; i < indexs.size() - 1; i++) {
            //int temp = POSITION[indexs[i + 1]-1] - POSITION[indexs[i]-1];
            int temp = indexs[i + 1] - indexs[i];
            if (small > temp)
                small = temp;
        }
        return small;
    }
};

void COUNTING_SORT(vector<vector<int>>& A, vector<vector<int>>& B, int max)
{
    vector<int> C(max + 1);
    for (int i = 0; i <= max; i++)
        C[i] = 0;
    for (int j = 0; j < A.size(); j++)
        C[A[j][1]]++;
    for (int i = 1; i <= max; i++)
        C[i] += C[i - 1];
    for (int j = A.size()-1; j >= 0; j--) {
        B[C[A[j][1]]][1] = A[j][1];
        B[C[A[j][1]]][0]=A[j][0];
        C[A[j][1]]--;
    }
}
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int length = intervals.size();
    if (length == 1)   return 1;
    int max = 0;
    for (int i = 0; i < length; i++)
        if (max < intervals[i][1])
            max = intervals[i][1];
    vector<vector<int>> result(length + 1, vector<int>(2));
    COUNTING_SORT(intervals, result, max);
    for (int i = 1; i < length + 1; i++)
        cout << result[i][0] << " " << result[i][1] << endl;
    return 1;
}

void MERGE(vector<vector<int>>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<vector<int>>L;
    for (int i = 0; i < n1; i++)
        L.push_back({ A[p + i][0],A[p + i][1] });
    L.push_back({ -1,-1 });
    vector<vector<int>>R;
    for (int i = 1; i <= n2; i++)
        R.push_back({ A[q + i][0],A[q + i][1] });
    R.push_back({ -1,-1 });
    int L_index = 0;
    int R_index = 0;
    for (int i = p; i <= r; i++) {
        if (L[L_index] > R[R_index]) {
            A[i][0] = L[L_index][0];
            A[i][1] = L[L_index][1];
            L_index++;
        }
        else {
            A[i][0] = R[R_index][0];
            A[i][1] = R[R_index][1];
            R_index++;
        }
    }
}
void MERGE_SORT(vector<vector<int>>& A, int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}

#define MAXSIZE 20
typedef int ElemType;
typedef struct SqList
{
    ElemType* elem;
    int length;
};
void deleteItem(SqList& L, ElemType item)
{
    int j = L.length;
    int numsItem = 0;
    for (int k = L.length - 1; k >= 0; k--) {
        if (L.elem[k] != item) {
            j = k + 1;
            break;
        }
        L.length--;
    }
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == item) {
            j--;
            int temp = L.elem[i];
            L.elem[i] = L.elem[j];
            L.elem[j] = temp;
            L.length--;
        }
    }
}

typedef struct Listnode
{
    ElemType elem;
    struct Listnode* next;
}ListNode,*LinkList;

void nodeDecompose(LinkList& A)
{
    LinkList B = new ListNode{ 0, nullptr };
    LinkList C = new ListNode{ 0, nullptr };
    A = A->next;
    while (A) {
        if (A->elem < 0) {
            LinkList temp = new ListNode{ A->elem, nullptr };
            B->next = temp;
            B = B->next;
        }
        else {
            LinkList temp = new ListNode{ A->elem, nullptr };
            C->next = temp;
            C = C->next;
        }
        A = A->next;
    }
}

void findIntersection(LinkList& A, LinkList& B)
{
    LinkList a = A;
    if (a->elem > B->elem)
        while (B && B->elem < a->elem)
            B = B->next;
    else
        while (a && a->elem < B->elem)
            a = a->next;
    LinkList Ahead = a;
    while (a->next && B->next && a->next->elem == B->next->elem) {
        a = a->next;
        B = B->next;
    }
    LinkList Atail = a;
    A = Ahead;
    Atail->next = nullptr;
}

int main()
{
    LinkList A = new ListNode{ 1, nullptr };
    LinkList B = new ListNode{ 2, nullptr };
    LinkList C = new ListNode{ 3, nullptr };
    LinkList D = new ListNode{ 4, nullptr };
    LinkList E = new ListNode{ 5, nullptr };
    LinkList F = new ListNode{ 6, nullptr };
    LinkList G = new ListNode{ 7, nullptr };
    LinkList H = new ListNode{ 8, nullptr };
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;
    F->next = G;
    G->next = H;
    LinkList a = new ListNode{ 3, nullptr };
    LinkList b = new ListNode{ 4, nullptr };
    LinkList c = new ListNode{ 5, nullptr };
    LinkList d = new ListNode{ 6, nullptr };
    LinkList e = new ListNode{ 7, nullptr };
    LinkList f = new ListNode{ 8, nullptr };
    LinkList g = new ListNode{ 9, nullptr };
    LinkList h = new ListNode{ 10, nullptr };
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    findIntersection(A, a);
    while (A) {
        cout << A->elem << " ";
        A = A->next;
    }
    cout << endl;

    /*SqList L;
    L.length = 6;
    L.elem = new ElemType[6];
    L.elem[0] = 3;
    L.elem[1] = 2;
    L.elem[2] = 7;
    L.elem[3] = 2;
    L.elem[4] = 5;
    L.elem[5] = 2;
    deleteItem(L, 2);
    for (int i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl<<L.length << endl;*/
    return 0;
}

int MAIN0()
{
    string text = "Keep calm and code on";
    text[0] += 'a' - 'A';
    vector<vector<int>> SortString;
    int Index_string = 0;
    int Length_word = 0;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ' || i + 1 == text.length()) {
            SortString.push_back({ Length_word,Index_string });
            Index_string = i + 1;
            Length_word = 0;
            continue;
        }
        Length_word++;
    }
    SortString[SortString.size() - 1][0]++;
    /*for (int i = 0; i < SortString.size(); i++) {
        for (int j = 0; j < SortString[i].size(); j++)
            cout << SortString[i][j] << " ";
        cout << endl;
    }
    cout << endl;*/
    MERGE_SORT(SortString, 0, SortString.size() - 1);
    /*for (int i = 0; i < SortString.size(); i++) {
        for (int j = 0; j < SortString[i].size(); j++)
            cout << SortString[i][j] << " ";
        cout << endl;
    }*/
    string result;
    for (int i = SortString.size() - 1; i >= 0; i--) {
        for (int j = 0; j < SortString[i][0]; j++)
            result += text[SortString[i][1] + j];
        if (i != 0) result += ' ';
    }
    result[0] -= 'a' - 'A';
    cout<< result;
    return 0;
        //int n;
    //cin >> n;
    //    int rea = n;
    //    for (int i = 2; i * i <= n; i++)
    //        if (n % i == 0)//第一次找到的必为素因子
    //        {
    //            rea = rea - rea / i;
    //            do
    //                n /= i;//把该素因子全部约掉
    //            while (n % i == 0);
    //        }
    //    if (n > 1)
    //        rea = rea - rea / n;
    //    cout << rea;
    //    return 0;
    
}


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