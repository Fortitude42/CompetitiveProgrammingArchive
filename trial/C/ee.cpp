#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 11;



int n, m;
string s, t = "uddu";
long long dp[N][10], p;


int main () {
	cin >> s;
	n = s.size(), m = t.size();
	int ans= 0 ;
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) != m)
			continue;
		string tt = "";
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
				tt += s[i];
		if (t == tt)
			++ans;
	}
	cout << ans << endl;
}   	                       