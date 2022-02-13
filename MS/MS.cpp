#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define ARRAY_SIZE 4
int input[ARRAY_SIZE][ARRAY_SIZE];
int target[ARRAY_SIZE][ARRAY_SIZE];
struct RESULT
{
	int i;
	int j;
	int times = 6666;
};

void reset_input(int index)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		for (int j = 0; j < ARRAY_SIZE; j++)
			if (input[i][j] == index)
				input[i][j] = 0;
}

RESULT DFS(int i, int j,int times,int MODE,int index)
{
	if (MODE == 1 && target[i][j] == 1) {
		times++;
		RESULT result = { i,j,times };
		return result;
	}
	else if (MODE == 0 && times!=-1 && target[i][j] == 1) {
		times++;
		RESULT result = { i,j,times };
		return result;
	}
	times++;
	RESULT results[4];
	if (i - 1 >= 0 && input[i - 1][j] == 0) {
		input[i][j] = index;
		results[0] = DFS(i - 1, j, times, MODE, index+1);
		reset_input(index + 1);
	}
	if (i + 1 < ARRAY_SIZE && input[i + 1][j] == 0) {
		input[i][j] = index;
		results[1] = DFS(i + 1, j, times, MODE, index+1);
		reset_input(index + 1);
	}
	if (j - 1 >= 0 && input[i][j - 1] == 0) {
		input[i][j] = index;
		results[2] = DFS(i, j - 1, times, MODE, index+1);
		reset_input(index + 1);
	}
	if (j + 1 < ARRAY_SIZE && input[i][j + 1] == 0) {
		input[i][j] = index;
		results[3] = DFS(i, j + 1, times, MODE, index+1);
		reset_input(index + 1);
	}
	int result_index = 0;
	for (int index = 0; index < 4; index++)
		if (results[result_index].times > results[index].times)
			result_index = index;
	if (MODE == 1) {
		input[results[result_index].i][results[result_index].j] = 2;
		input[i][j] = 0;
	}
	else {
		input[results[result_index].i][results[result_index].j] = 0;
		input[i][j] = 2;
	}
	if (results[result_index].times == 6666)
		results[result_index].times = 0;
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

	for (int i = 0; i < ARRAY_SIZE; i++)
		for (int j = 0; j < ARRAY_SIZE; j++) {
			if (input[i][j] == 1 && target[i][j] == 0)
				move_times += DFS(i, j, -1, 1, 3).times;
			else if (input[i][j] == 0 && target[i][j] == 1)
				move_times += DFS(i, j, -1, 0, 3).times;
			else if (input[i][j] == 1 && target[i][j] == 1)
				input[i][j] = 2;
		}

	cout << move_times << endl;

	return 0;
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
/* Ëã24 */
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