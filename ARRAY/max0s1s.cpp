/*
https://www.geeksforgeeks.org/maximum-count-of-0s-between-two-1s-in-given-range-for-q-queries/

Maximum count of 0s between two 1s in given range for Q queries

Given a binary string S of size N, and a 2D array Q[][] of queries consisting of M pairs of the form {L, R}, the task for each query is to find the maximum number of 0s lying between two 1s in the range [L, R].

*/

#include <iostream>
using namespace std;


void countOsBetween1s(string S, int N, int Q[][2])
{

	// Stores count of 0's that are
	// right to the most recent 1's
	int leftBound[N];

	// Stores count of 0's that are
	// left to the most recent 1's
	int rightBound[N];

	// Stores the count of zeros
	// in a prefix/suffix of array
	int count = 0;

	// Stores the count of total 0s
	int total = 0;

	for (int i = 0; i < N; i++) {

		if (S[i] == '1') {
			count = total;
		}

		else if (S[i] == '0') {
			total++;
		}

		rightBound[i] = count;
	}

	count = 0;
	total = 0;

	for (int i = N - 1; i >= 0; i--) {


		if (S[i] == '1') {
			count = total;
		}

		else if (S[i] == '0') {
			total++;
		}

		leftBound[i] = count;
	}

	for (int q = 0; q < 2; q++) {

		int L = Q[q][0];
		int R = Q[q][1];

		count = leftBound[L] + rightBound[R] - total;
		cout << count << " ";
	}
}

// Driver Code
int main()
{

	string S = "1001010";
	int Q[][2] = { { 0, 4 }, { 0, 5 } };
	int N = S.length();
	countOsBetween1s(S, N, Q);
	return 0;
}

