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

int n, a[N], p[N], fw[N];

inline void upd(int i, int add) {
	//cerr << "upd " << i << " " << add << "\n";
	for (; i <= n + n; i += i & -i)
		fw[i] += add;
}
inline int get(int i) {
	int res = 0;
	for (; i >= 1; i -= i & -i)
		res += fw[i];
	return res;
}

inline bool cmp(int i, int j) {
	if (a[i] == a[j]) return i < j;
	return a[i] > a[j];
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
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[i] = i;
	}
	for (int i = 1; i <= n + n; i++)
		upd(i, 1);
	sort(p + 1, p + 1 + n, &cmp);
	int l = 1, r = n;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int pos = (l <= p[i] && p[i] <= r ? p[i] : p[i] + n);
		int val = get(pos - 1) - get(l - 1);
		ans += val;
		cerr << l << " " << r << " " << pos << " " << (pos <= n ? pos + n : pos - n) << " : " << a[p[i]] << " " << val << "\n";
		upd(pos, -1);
		upd((pos <= n ? pos + n : pos - n), -1);
		int shift = pos - l + 1;
		r += shift, l += shift;
		if (r > n + n) l -= n, r -= n;
	}
	printf("%lld", ans);
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
