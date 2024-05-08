#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = 998244353ll;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 30050;

char s[N];

int n, pref[N];
ll dp[N], pw[N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	scanf("%s", s + 1);
	n = len(s + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + (s[i] == '?');
		pw[i] = pw[i - 1] * 26 % mod;
	}

	dp[0] = 1;
	for (int i = 1; i <= n / 2; i++) {
		if (s[i] == s[n - i + 1] || s[i] == '?' || s[n - i + 1] == '?') {
			int l1 = i, r1 = i, l2 = n - i + 1, r2 = n - i + 1;
			int cnt = (s[i] == '?' && s[n - i + 1] == '?');
			dp[r1] = (dp[r1] + dp[l1 - 1] * pw[cnt]) % mod;
			while (1 < l1 && r1 + 1 < l2 - 1 && r2 < n && (s[l1 - 1] == s[l2 - 1] || s[l1 - 1] == '?' || s[l2 - 1] == '?') && (s[r1 + 1] == s[r2 + 1] || s[r1 + 1] == '?' || s[r2 + 1] == '?')) {
				l1--, r1++, l2--, r2++;
				cnt += (s[l1] == '?' && s[l2] == '?') + (s[r1] == '?' && s[r2] == '?');
				dp[r1] = (dp[r1] + dp[l1 - 1] * pw[cnt]) % mod;
			}
		}
		if (i + 1 < n - i && (s[i] == s[n - i] || s[i] == '?' || s[n - i] == '?') && (s[i + 1] == s[n - i + 1] || s[i + 1] == '?' || s[n - i + 1] == '?')) {
			int l1 = i, r1 = i + 1, l2 = n - i, r2 = n - i + 1;
			int cnt = (s[i] == '?' && s[n - i] == '?') + (s[i + 1] == '?' && s[n - i + 1] == '?');
			dp[r1] = (dp[r1] + dp[l1 - 1] * pw[cnt]) % mod;
			//cerr << l1 << " " << r1 << " : " << dp[l1 - 1] << " " << pw[cnt] << "\n";
			while (1 < l1 && r1 + 1 < l2 - 1 && r2 < n && (s[l1 - 1] == s[l2 - 1] || s[l1 - 1] == '?' || s[l2 - 1] == '?') && (s[r1 + 1] == s[r2 + 1] || s[r1 + 1] == '?' || s[r2 + 1] == '?')) {
				l1--, r1++, l2--, r2++;
				cnt += (s[l1] == '?' && s[l2] == '?') + (s[r1] == '?' && s[r2] == '?');
				dp[r1] = (dp[r1] + dp[l1 - 1] * pw[cnt]) % mod;
				//cerr << l1 << " " << r1 << " : " << dp[l1 - 1] << " " << pw[cnt] << "\n";
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n / 2; i++) {
		int l = i + 1;
		int r = n - l + 1;
		//if (l <= r) {
			ans = (ans + dp[i] * pw[pref[r] - pref[l - 1]]) % mod;
			//cerr << i << " " << l << " " << r << " : " << dp[i] << " " << pref[r] - pref[l - 1] << "\n";
		//}
	}

	printf("%d", ans);
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
