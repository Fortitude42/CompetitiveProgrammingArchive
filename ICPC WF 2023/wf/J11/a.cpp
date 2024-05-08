#include <bits/stdc++.h>


#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair < int, int >
#define mp make_pair
#define ppb pop_back
#define f first
#define s second
#define sz(s) (int)s.size()
#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

const short inf = 1000;
const int N = 200;
const int M = N + 1;
const int maxn = 1e6 + 11;


vector < pair < int, pii > > vals;
bool ok[maxn][323];
int n, t[M][2];
short dp[maxn][323];

void precalc() {
	for (int i = 1; i <= N; ++i) {		
		t[i][0] = (i == 1 ? 0 : t[i - 2][0]) + i*i;
		t[i][1] = t[i - 1][1] + i*i;

		if (i >= 2 && t[i][1] <= 1e6)
			vals.pb(mp(t[i][1], mp(i, 1)));
		if (i >= 3 && t[i][0] <= 1e6)
			vals.pb(mp(t[i][0], mp(i, 0)));
	}

	sort(all(vals));


	memset(dp, -1, sizeof dp);
}

short rec(int n, int k) {
	short &res = dp[n][k];
	if (res != -1)
		return res;
	res = inf;

	if (!n)
		return res = 0;
	
	int cur = vals[k].f;
	if (!k) {
		if (cur == n) {
		    ok[n][k] = 1;
			return res = 1;
		}
		return res = inf;
	}

	ok[n][k] = 1;
	if (n >= cur)
		res = min(res, (short)(rec(n - cur, k - 1) + 1));

	short tmp = rec(n, k - 1);
	if (tmp < res) {
		res = tmp;
		ok[n][k] = 0;
	}

	return res;
}

void solve(int tt) {
	cin >> n;
	if (!n)
		exit(0);

	cout << "Case " << tt << ": ";

	short cur = rec(n, sz(vals) - 1);

	if (cur == inf) {
		cout << "impossible\n";
		return;
	}

	vector < pii > ans;
	int k = sz(vals) - 1;
	while (n > 0) {
		if (!ok[n][k]) {
			k--;
			continue;
		}

		ans.pb(vals[k].s);
		int cur = vals[k].f;
		n -= cur;
		k--;
	}

//	reverse(all(ans));
	for (auto x : ans) {
		cout << x.f;
		if (x.s == 1)
			cout << "H ";
		else
			cout << "L ";
	}

	cout << "\n";
}

int main() {
	precalc();
	fastio;
	for (int tt = 1; ; ++tt) {
		solve(tt);
	}	
	
	return 0;
}