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

const int N = 305;

int n;
ll lim, ans;

struct pt {
	ll x, y;
	inline pt operator - (pt p) {
		return {x - p.x, y - p.y};
	}
	inline ll operator * (pt p) {
		return x * p.x + y * p.y;
	}
	inline ll operator % (pt p) {
		return x * p.y - y * p.x;
	}
	inline ll area(pt a, pt b) {
		pt cur = {x, y};
		return abs((cur - a) % (b - a));
	}
	inline ld dist(pt p) {
		return sqrt(sqr(x - p.x) + sqr(y - p.y));
	}
} p[N];

inline ld dist(pt a, pt b, pt c) {
	return (a.area(b, c)) / (a.dist(b));
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
	
	cin >> n >> lim;
	lim <<= 1;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		p[i] = {x, y};
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ld dist1 = -1.0, dist2 = -1.0;
			int pos1 = -1, pos2 = -1;
			bool bad = 0;
			vector < ll > v1, v2;
			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) continue;
				ll val = (p[k] - p[i]) % (p[j] - p[i]);
				if (val == 0)
					v1.pb(0);
				if (val > 0)
					v1.pb(p[k].area(p[i], p[j]));
				else
					v2.pb(p[k].area(p[i], p[j]));
			}
			sort(all(v1));
			sort(all(v2));
			int ptr = sz(v2) - 1;
			for (int k = 0; k < sz(v1); k++) {
				while (ptr >= 0 && v1[k] + v2[ptr] > lim)
					ptr--;
				if (ptr >= 0 && v1[k] + v2[ptr] <= lim)
					ans = max(ans, v1[k] + v2[ptr]);
			}
		}
	}
	cout << (ans >> 1) << '.' << (5 * (ans & 1)) << 0;
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
