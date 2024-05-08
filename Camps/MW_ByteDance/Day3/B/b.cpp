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
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 100500;
const int LOG = 20;

int n, t, ptr, a[N];
vector < vector < int > > ans[LOG];

void rec(int h) {
	vector < int > cur;
	for (int i = 1; i <= t; i++) {
		if (h)
			rec(h - 1);
		if (i < t)
			cur.pb(a[++ptr]);
	}
	ans[h].pb(cur);
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		scanf("%d %d", &t, &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		printf("Case #%d:\n", tt);
		if (n % (t - 1) != 0) {
			puts("INVALID");
			continue;
		}
		int need = n / (t - 1), h = -1;
		ll cur = 0, pw = 1;
		for (int i = 1; ; i++) {
			cur += pw;
			pw *= t;
			if (cur == need) {
				h = i;
				break;
			}
			if (cur > need)
				break;
		}
		if (h == -1) {
			puts("INVALID");
			continue;
		}
		sort(a + 1, a + 1 + n);
		rec(h - 1);
		for (int i = h - 1; i >= 0; i--) {
			for (int j = 0; j < sz(ans[i]); j++) {
				for (int k = 0; k < sz(ans[i][j]); k++) {
					printf("%d", ans[i][j][k]);
					printf(k + 1 < sz(ans[i][j]) ? " " : ";");
				}
				if (j + 1 < sz(ans[i]))
					printf(" ");
			}
			ans[i].clear();
			puts("");
		}
		ptr = 0;
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
