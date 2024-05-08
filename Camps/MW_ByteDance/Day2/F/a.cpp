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

pll f(string s) {
	ll a = 0, b = 0;
	for (auto i : s) {
		if (i == '.') {
			b = s.back() - '0';
			return {a, b};
		}
		a = a * 10 + i - '0';
	}
	return {a, b};
}

inline ll row1(pll L, pll R) {
	return R.F - L.F + (L.S == 0) + 1;
}

inline ll row05(pll L, pll R) {
	return R.F - L.F - 1 + (L.S <= 5) + (R.S >= 5) + 1;
}

inline ll hori(string a, string b, string c) {
	pll L = f(a), R = f(b), y = f(c);
	if (y.S == 0) return row1(L, R) + row05(L, R);
	if (y.F & 1) return row05(L, R);
	return row1(L, R); 
}

inline ll vert(string a, string b, string c) {
	pll L = f(a), R = f(b), x = f(c);
	ll l = L.F - (L.S == 0), r = R.F;
	ll even = (r + 2) / 2 - (l + 1) / 2;
	ll odd = r - l + 1 - even;
	if (x.S == 0)
		return even + even + odd;
	if (x.S == 5)
		return even + odd + odd;
	//cerr << a << " " << b << " " << c << " : " << even << " " << odd << "\n";
	return even + odd;
}

inline ll pt(string a, string b) {
	pll x = f(a), y = f(b);
	if (y.S == 0) {
		if (x.S == 0 || x.S == 5)
			return 3;
		return 2;
	}
	else {
		if ((!(y.F & 1) && x.S == 0) || ((y.F & 1) && x.S == 5))
			return 2;
		return 1;
	}
}

inline bool check(string a, string b, string c, string d) {
	pll x1 = f(a), y1 = f(b), x2 = f(c), y2 = f(d);
	ll ly = y1.F, ry = y2.F + (y2.S > 0);
	if (ly + 1 < ry) return 0;
	if (ly & 1) {
		x1.S -= 5;
		if (x1.S < 0) x1.F--;
		x2.S -= 5;
		if (x2.S < 0) x2.F--;
	}
	ll lx = x1.F, rx = x2.F + (x2.S > 0);
	return lx + 1 >= rx;
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

	string x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << hori(x1, x2, y1) + hori(x1, x2, y2) + vert(y1, y2, x1) + vert(y1, y2, x2) - pt(x1, y1) - pt(x1, y2) - pt(x2, y1) - pt(x2, y2) + check(x1, y1, x2, y2);
	//cerr << hori(x1, x2, y1) << " " << hori(x1, x2, y2) << " --- " << vert(y1, y2, x1) << " " << vert(y1, y2, x2) << " --- " << pt(x1, y1) << " " << pt(x1, y2) << " " << pt(x2, y1) << " " << pt(x2, y2);
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
