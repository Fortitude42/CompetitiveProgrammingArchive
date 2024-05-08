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

const int N = 1500500;

pii p[N];
ll ans[5];
int w, h, n;
vector < int > allx, ally;
vector < pair < pii, pii > > hori, vert;

int W, H, t[N][3];
vector < pii > op[N], cl[N];
vector < pair < pii, int > > qr[N];

inline void upd(int i, int j, int add) {
	for (; i <= H; i += i & -i)
		t[i][j] += add;
}
inline int get(int i, int j) {
	int res = 0;
	for (; i >= 1; i -= i & -i)
		res += t[i][j];
	return res;
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
	
	scanf("%d %d %d", &w, &h, &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = {x, y};
	}
	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j < n && p[i].F == p[j + 1].F)
			j++;
		if (p[i].S) vert.pb({{p[i].F, 1}, {0, p[i].S - 1}});
		if (p[j].S < h) vert.pb({{p[j].F, 1}, {p[j].S + 1, h}});
		for (int k = i; k < j; k++) {
			if (p[k].S + 1 <= p[k + 1].S - 1)
				vert.pb({{p[k].F, 2}, {p[k].S + 1, p[k + 1].S - 1}});
		}
		i = j;
	}
	for (int i = 1; i <= n; i++) swap(p[i].F, p[i].S);
	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j < n && p[i].F == p[j + 1].F)
			j++;
		if (p[i].S) hori.pb({{p[i].F, 1}, {0, p[i].S - 1}});
		if (p[j].S < w) hori.pb({{p[j].F, 1}, {p[j].S + 1, w}});
		for (int k = i; k < j; k++) {
			if (p[k].S + 1 <= p[k + 1].S - 1)
				hori.pb({{p[k].F, 2}, {p[k].S + 1, p[k + 1].S - 1}});
		}
		i = j;
	}
	//vert[i] = {{x, type}, {yL, yR}}
	//hori[i] = {{y, type}, {xL, xR}};
	for (auto i : vert) allx.pb(i.F.F), ally.pb(i.S.F), ally.pb(i.S.S);
	for (auto i : hori) ally.pb(i.F.F), allx.pb(i.S.F), allx.pb(i.S.S);
	sort(all(allx));
	sort(all(ally));
	allx.resize(unique(all(allx)) - allx.bg);
	ally.resize(unique(all(ally)) - ally.bg);
	for (auto &i : vert) {
		ans[i.F.S] += i.S.S - i.S.F + 1;
		i.F.F = lower_bound(all(allx), i.F.F) - allx.bg + 1;
		i.S.F = lower_bound(all(ally), i.S.F) - ally.bg + 1;
		i.S.S = lower_bound(all(ally), i.S.S) - ally.bg + 1;
		qr[i.F.F].pb({{i.S.F, i.S.S}, i.F.S});
	}
	for (auto &i : hori) {
		ans[i.F.S] += i.S.S - i.S.F + 1;
		i.F.F = lower_bound(all(ally), i.F.F) - ally.bg + 1;
		i.S.F = lower_bound(all(allx), i.S.F) - allx.bg + 1;
		i.S.S = lower_bound(all(allx), i.S.S) - allx.bg + 1;
		op[i.S.F].pb({i.F.F, i.F.S});
		cl[i.S.S].pb({i.F.F, i.F.S});
	}
	W = sz(allx);
	H = sz(ally);
	for (int i = 1; i <= W; i++) {
		for (auto j : op[i])
			upd(j.F, j.S, 1);
		for (auto j : qr[i]) {
			int L = j.F.F, R = j.F.S, type = j.S;
			for (int k = 1; k <= 2; k++) {
				int cnt = get(R, k) - get(L - 1, k);
				ans[k] -= cnt;
				ans[type] -= cnt;
				ans[k + type] += cnt;
			}
		}
		for (auto j : cl[i])
			upd(j.F, j.S, -1);
	}
	ans[0] = (w + 1ll) * (h + 1ll) - n - ans[1] - ans[2] - ans[3] - ans[4];
	for (int i = 0; i <= 4; i++)
		printf("%lld ", ans[i]);
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
