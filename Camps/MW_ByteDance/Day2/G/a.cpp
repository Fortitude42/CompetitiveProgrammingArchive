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

vector < int > dg;

/*void rec(int l = 0, r = sz(dg) - 1, ll res = 1) {
	if (l == r) {

	}
	if (l > r)
		return;
	rec(l + 1, r - 1, res * )
}*/

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;

	for (int i = 1; i <= 1000; i++) {
		int x = i, y = 0;
		while (x) {
			y = y * 10 + x % 10;
			x /= 10;
		}
		cout << i << " " << y << " : " << i + y << "\n";
	}
	
	/*int T;
	cin >> T;
	while (T--) {
		ll n;
		cin >> n;
		dg.clear();
		while (n) {
			dg.pb(n % 10);
			n /= 10;
		}
		rev(all(dg));
		int m = sz(dg);

	}*/
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
