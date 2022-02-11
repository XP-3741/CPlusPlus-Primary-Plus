#include<iostream>
#include<string>
//#include <algorithm> 

using std::cin;
using std::cout;
using std::endl;
using std::string;
//using std::next_permutation;
//using std::prev_permutation;

#define ARRAY_SIZE 4
int input[ARRAY_SIZE][ARRAY_SIZE];
int target[ARRAY_SIZE][ARRAY_SIZE];
struct RESULT
{
	int i;
	int j;
	int times = -1;
};

RESULT DFS(int i, int j,int times)
{
	times++;
	if (target[i][j] == 1) {
		RESULT result = { i,j,times };
		return result;
	}
	RESULT results[4];
	if (i - 1 >= 0 && input[i - 1][j] != 1)	results[0] = DFS(i - 1, j, times);
	if (i + 1 < ARRAY_SIZE && input[i + 1][j] != 1)	results[1] = DFS(i + 1, j, times);
	if (j - 1 >= 0 && input[i][j - 1] != 1)	results[2] = DFS(i, j - 1, times);
	if (i + 1 < ARRAY_SIZE && input[i][j + 1] != 1)	results[3] = DFS(i, j + 1, times);
	int result_index = 0;
	for (int index = 0; index < 4; index++)
		if (results[index].times != -1 && results[result_index].times > results[index].times)
			result_index = index;

	input[results[result_index].i][results[result_index].j] = 1;
	input[i][j] = 0;
	target[results[result_index].i][results[result_index].j] = 2;
	return results[result_index];
}

int main()
{
	int move_times = 0;
	string input_string;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cin >> input_string;
		for (int j = 0; j < ARRAY_SIZE; j++)
			input[i][j] = input_string[j] - '0';
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cin >> input_string;
		for (int j = 0; j < ARRAY_SIZE; j++)
			target[i][j] = input_string[j] - '0';
	}

	for(int i=0;i< ARRAY_SIZE;i++)
		for (int j = 0; j < ARRAY_SIZE; j++) {
			if (input[i][j] == 1 && target[i][j] == 0)
				move_times += DFS(i, j, 0).times;
			else if (input[i][j] == 1 && target[i][j] == 1)
				target[i][j] = 2;
		}

	cout << move_times << endl;

	return 0;
}

/* Ëã24 */
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