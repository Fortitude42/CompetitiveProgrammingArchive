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

const int N = 2000500;

int n, a[N], ps[N];

inline int readint() {
	char c = getchar();
	while (!('0' <= c && c <= '9'))
		c = getchar();
	int n = 0;
	while ('0' <= c && c <= '9') {
		n = (n << 3) + (n << 1) + c - '0';
		c = getchar();
	}
	return n;
}

struct node {
	int mx, pos;
	int cnt, tot;
} t[N << 2];

inline node operator + (const node &L, const node &R) {
	if (L.mx >= R.mx) return {L.mx, L.pos, L.cnt, L.tot + R.tot};
	return {R.mx, R.pos, L.tot + R.cnt, L.tot + R.tot};
}

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = {a[r], r, 0, 1};
		ps[r] = v;
		return;
	}
	int mid = (l + r) >> 1;
	build(v << 1, l, mid);
	build(v << 1 | 1, mid + 1, r);
	t[v] = t[v << 1] + t[v << 1 | 1];
}

inline void upd(int pos) {
	int v = ps[pos];
	t[v] = {0, 0, 0, 0};
	while (v != 1) {
		v >>= 1;
		t[v] = t[v << 1] + t[v << 1 | 1];
	}
}

node get(int v, int l, int r, int lx, int rx) {
	if (rx < l || r < lx) return {0, 0, 0, 0};
	if (lx <= l && r <= rx) return t[v];
	int mid = (l + r) >> 1;
	return get(v << 1, l, mid, lx, rx) + get(v << 1 | 1, mid + 1, r, lx, rx);
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
	
	n = readint();
	for (int i = 1; i <= n; i++) {
		a[i] = readint();
		a[i + n] = a[i];
	}
	build(1, 1, n + n);
	int l = 1, r = n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		node cur = get(1, 1, n + n, l, r);
		ans += cur.cnt;
		//cerr << i << " --- " << l << " " << r << " : " << cur.mx << " " << cur.pos << "\n";
		upd(cur.pos);
		if (cur.pos - n >= 1) upd(cur.pos - n);
		else upd(cur.pos + n);
		int shift = cur.pos - l + 1;
		r += shift, l += shift;
		if (r > n + n) l -= n, r -= n;
	}
	printf("%lld", ans);
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
