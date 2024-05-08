#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define s second
#define f first
const int inf = 1e9;

int main() {
	pair < int, int > a[5] = {mp(4, 5), mp(5, 3), mp(3, 6), mp(6, 4), mp(4, 5)};
	int dp[5][5], s[5][5];
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			dp[i][j] = -1, s[i][j] = -1;

	for (int i = 4; i >= 0; --i)
		for (int j = i; j < 5; ++j) {
			if (i == j) {
				dp[i][j] = 0; 
				continue;
			}
			if (i + 1 == j) {
				dp[i][j] = a[i].f * a[i].s * a[j].s;
				continue;
			}
			int val1 = dp[i + 1][j] + a[i].f * a[i].s * a[j].s;
			int val2 = dp[i][j - 1] + a[i].f * a[j].f * a[j].s;
			if (val1 < val2) {
				dp[i][j] = val1;
				s[i][j] = 0;
			} else {
				dp[i][j] = val2;
				s[i][j] = 1;
			}
		}

	for (int i = 0; i < 5; ++i, cout << endl)
		for (int j = 0; j < 5; ++j)
			cout << dp[i][j] << ' ';

	cout << endl;
	for (int i = 0; i < 5; ++i, cout << endl)
		for (int j = 0; j < 5; ++j)
			cout << s[i][j] << ' ';
}