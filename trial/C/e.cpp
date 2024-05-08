#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 11;



int n, m;
string s, t = "uddu";
long long dp[N][10], p;


int main () {
	cin >> s;
	n = s.size();
	m = t.size();
	dp[0][0] = 1;                                                        
	p = 1;
	for (int i = 0; i < 31; ++i)
		p *= 2;
	p--;

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j) {
			if (i > 0)
				dp[i][j] = dp[i - 1][j];
			if (i > 0 && j > 0 && s[i - 1] == t[j - 1])
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % p;
		}
			
	cout << dp[n][m] << endl;
}   	                       