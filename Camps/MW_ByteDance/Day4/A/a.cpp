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

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 4005;

vector < int > st[12][N];
int n, a, b, c, q, mod, ar[N][N], lim[N];

inline int get(int x, int y, int len) {
	int cur = lim[len];
	return max(st[cur][x][y - 1], st[cur][x][y + len - 1 - (1 << cur) + 1 - 1]);
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
	
	scanf("%d %d %d %d %d %d", &n, &ar[1][1], &a, &b, &c, &mod);
	st[0][1].pb(ar[1][1]);
	for (int i = 2; i <= n; i++) {
		ar[i][1] = (ar[i - 1][1] + 0ll) * c % mod;
		st[0][i].pb(ar[i][1]);
		for (int j = 2; j <= i; j++) {
			ar[i][j] = ((ar[i][j - 1] + 0ll) * a + (ar[i - 1][j - 1] + 0ll) * b) % mod;
			st[0][i].pb(ar[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int pw = 1; (1 << pw) <= i; pw++) {
			lim[i] = pw;
			st[pw][i].reserve(i - (1 << pw) + 1);
			for (int j = 1; j <= i - (1 << pw) + 1; j++) {
				st[pw][i].pb(max(st[pw - 1][i][j - 1], st[pw - 1][i][j + (1 << (pw - 1)) - 1]));
			}
		}
	}
	scanf("%d", &q);
	while (q--) {
		int x, y, len;
		scanf("%d %d %d", &x, &y, &len);
		int ans = 0;
		for (int i = x; i <= x + len - 1; i++)
			ans = max(ans, get(i, y, i - x + 1));
		printf("%d\n", ans);
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
