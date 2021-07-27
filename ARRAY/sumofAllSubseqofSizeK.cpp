#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++)
		res = res * i;
	return res;
}

int nCr(int n, int r) {
	return fact(n) / (fact(r) * fact(n - r));
}


int sumSubseq(int arr[], int n, int k)
{

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	int subseq;
	subseq = nCr(n, k);
	int ans = sum * ((k * subseq) / n);
    
	return ans;
}

int main()
{

	int arr[] = { 7, 8, 9};
	int K = 3;
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << sumSubseq(arr, n, K);
	return 0;
}
