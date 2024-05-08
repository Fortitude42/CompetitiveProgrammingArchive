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

const int N = 200500;

map < string, int > val;

inline void solve() {
	string s;
	int n;
	cin >> s >> n;
	int day = val[s];
	int ans = N;
	for (int i = 1; i <= n; i++) {
		int d;
		cin >> d;
		bool ok = 0;
		int createDay = (day - d % 7 + 7) % 7;
		while (d >= 91 && createDay != 0) {
			ok = 1;
			if (createDay <= 2) {
				d -= 30;
				createDay += 2;
			} else if (createDay == 3) {
				createDay = 0;
				d -= 32;
			} else {
				assert(createDay == 4);
				createDay = 0;
				d -= 31;
			}
		}

		if (d >= 91)
			ok = 1;
		d %= 91;
		while (!ok || d > 0) {
			ok = 1;
			if (createDay <= 2) {
				d -= 30;
				createDay += 2;
			} else if (createDay == 3) {
				createDay = 0;
				d -= 32;
			} else {
				assert(createDay == 4);
				createDay = 0;
				d -= 31;
			}
		}

		ans = min(ans, -d);
	}
	cout << ans << "\n";
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;

	val["Mon"] = 0;
	val["Tue"] = 1;
	val["Wed"] = 2;
	val["Thu"] = 3;
	val["Fri"] = 4;
	val["Sat"] = 5;
	val["Sun"] = 6;
	
	int T = 1;
	//cin >> T;
	while (T--)
		solve();
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
