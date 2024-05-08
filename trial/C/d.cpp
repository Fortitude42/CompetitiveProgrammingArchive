#include <bits/stdc++.h>

using namespace std;
const int N = 1.2e6 + 11;



int n;
long long dp[N][3], p;


int main () {
	cin >> n;
	p = 1;
	for (int i = 0; i < 31; ++i)
		p *= 2;
	p--;

	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			for (int x = 0; x < 3; ++x)
				if (j == 2 || x == 3 || j != x)
					dp[i][j] = (dp[i][j] + dp[i - 1][x]) % p;

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % p;
}   	