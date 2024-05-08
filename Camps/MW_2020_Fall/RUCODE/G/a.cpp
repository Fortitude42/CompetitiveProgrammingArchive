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

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

const ld eps = (db)1e-10;
const ld pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 100500;

inline ld getang(ll a, ll b, ll c) {
	return acos((sqr(a) + sqr(b) - sqr(c)) / (2.0 * a * b));
}

inline pii calc(int a, int b, int c, int d) {
	//cerr << a << " " << b << " " << c << " " << d << "\n";
	pii res = {inf, inf};
	for (int x = 1; x < min(a + b, c + d); x++) {
		if (a >= x + b) continue;
		if (b >= x + a) continue;
		if (d >= c + x) continue;
		if (c >= d + x) continue;
		ld ab = getang(a, b, x);
		ld ax = getang(a, x, b);
		ld bx = getang(x, b, a);
		ld cd = getang(c, d, x);
		ld xd = getang(d, x, c);
		ld xc = getang(c, x, d);
		ld ad = ax + xd;
		ld bc = bx + xc;
		if (!(ad < pi) || !(bc < pi)) continue;
		if (!(fabs(ab + bc + cd + ad - pi - pi) < eps)) continue;
		ld y1 = sqr(a) + sqr(d) - 2.0 * a * d * cos(ad);
		ld y2 = sqr(b) + sqr(c) - 2.0 * b * c * cos(bc);
		if (!(fabs(y1 - y2) < eps)) continue;
		if (!(y1 > 0.0)) continue;
		y1 = sqrt(y1);
		int y = round(y1);
		if (!(fabs(y - y1) < eps)) continue;
		if (y >= a + d) continue;
		if (y >= b + c) continue;
		if (a >= d + y) continue;
		if (b >= c + y) continue;
		if (c >= b + y) continue;
		if (d >= a + y) continue;
		pii cur = (x <= y ? mp(x, y) : mp(y, x));
		res = min(res, cur);
		//cerr << cur.F << " " << cur.S << "\n";
	}
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
	
	int a[5];
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	sort(a + 1, a + 5);
	if (a[4] >= a[1] + a[2] + a[3]) {
		cout << -1;
		return 0;
	}
	pii ans = {inf, inf};
	do {
		ans = min(ans, calc(a[1], a[2], a[3], a[4]));
	} while (next_permutation(a + 1, a + 5));
	if (ans.F == inf)
		cout << -1;
	else
		cout << ans.F << " " << ans.S;
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}