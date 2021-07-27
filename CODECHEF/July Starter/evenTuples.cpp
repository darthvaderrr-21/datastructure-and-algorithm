#include <bits/stdc++.h>
using namespace std;

int numSubseq(int arr[], int n, int k) {

	int dp[n][k + 1], ans = -1;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		dp[i][1] = arr[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				for (int l = 1; l <= k - 1; l++) {
					if (dp[j][l] != -1) {

						dp[i][l + 1] = max(dp[i][l + 1],dp[j][l] + arr[i]);
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans < dp[i][k])
			ans = dp[i][k];
	}
    
	return (ans == -1) ? 0 : ans;
}

// Driver function
int main()
{
	int n = 8, k = 3;
	int arr[n] = { 8, 5, 9, 10, 5, 6, 21, 8 };
	int ans = numSubseq(arr, n, k);
	cout << ans << "\n";
	return 0;
}
