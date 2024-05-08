#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main() {
	int sizes[5] = {3, 5, 7, 8, 9};
	int values[5] = {4, 6, 7, 9, 10};	

	int dp[23];
	for (int i = 0; i < 23; ++i)
		dp[i] = -inf;
	dp[0] = 0;

	for (int j = 0; j < 5; ++j) {
		for (int i = 22 - sizes[j]; i >= 0; --i)
			dp[i + sizes[j]] = max(dp[i + sizes[j]], dp[i] + values[j]);
	}

	cout << *max_element(dp, dp + 23);
}