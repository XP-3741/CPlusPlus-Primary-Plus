#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAX 5
#define REQUIRE 11 

int main()
{
	int text[5] = { 1,11,111,1111,11111 };
	int W = 2;

	for (W = 0; W <= 7; W++) {
		
		for (int k : text) {
			cout.width(W);
			cout << k << " ";
		}

		cout << endl << "now_width: " << W << endl << endl;
	}
	return 0;
}

int MAIN()
{
	float input[MAX] = { 8.02,7.43,4.57,5.39,9.78 };
	float max = 0;
	int max_index = 0;
	for(int i=0;i<MAX;i++)
		if (input[i] > max) {
			max = input[i];
			max_index = i;
		}
	int sum = 0;
	float length = 0;
	int chu = 2;
	while (input[max_index] / chu > 0.01) {
		max = input[max_index];
		length = max / chu;
		length = (int)(length * 100) / 100.0;
		for (int i = 0; i < MAX; i++)
			sum += (int)(input[i] / length);
		if (sum >= REQUIRE) {
			cout << "Length: " << length << endl;
			cout << "sum: " << sum << endl;
			return 0;
		}
		chu *= 2;
		sum = 0;
	}
	cout << "Fail Length: " << length;
	return 0;
}