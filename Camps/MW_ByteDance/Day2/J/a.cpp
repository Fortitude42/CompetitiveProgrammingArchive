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

bool check;

char rec(int n, int m, bool hori, int x, int y, int xx, int yy) {
	if (n == 1 && m == 2) return 'N';
	if (n == 2 && m == 1) return 'N';
	//if (check) {
		//cerr << n << " " << m << " " << hori << " : " << x << " " << y << " " << xx << " " << yy << " ------ ";
	//}
	if (hori) {
		int col1;
		if (y <= (m >> 2))
			col1 = 1;
		else if (y <= m - (m >> 2))
			col1 = 2 + (x > (n >> 1));
		else
			col1 = 4;
		int col2;
		if (yy <= (m >> 2))
			col2 = 1;
		else if (yy <= m - (m >> 2))
			col2 = 2 + (xx > (n >> 1));
		else
			col2 = 4;
		//if (check) cerr << col1 << " " << col2 << "\n";
		if (col1 != col2)
			return 'Y';
		if (col1 == 1)
			return rec(n, m >> 2, 0, x, y, xx, yy);
		else if (col1 == 2)
			return rec(n >> 1, m >> 1, 1, x, y - (m >> 2), xx, yy - (m >> 2));
		else if (col1 == 3)
			return rec(n >> 1, m >> 1, 1, x - (n >> 1), y - (m >> 2), xx - (n >> 1), yy - (m >> 2));
		else
			return rec(n, m >> 2, 0, x, y - (m - (m >> 2)), xx, yy - (m - (m >> 2)));
	}
	else {
		int col1;
		if (x <= (n >> 2))
			col1 = 1;
		else if (x <= n - (n >> 2))
			col1 = 2 + (y > (m >> 1));
		else
			col1 = 4;
		int col2;
		if (xx <= (n >> 2))
			col2 = 1;
		else if (xx <= n - (n >> 2))
			col2 = 2 + (yy > (m >> 1));
		else
			col2 = 4;
		//if (check) cerr << col1 << " " << col2 << "\n";
		if (col1 != col2) return 'Y';
		if (col1 == 1)
			return rec(n >> 2, m, 1, x, y, xx, yy);
		else if (col1 == 2)
			return rec(n >> 1, m >> 1, 0, x - (n >> 2), y, xx - (n >> 2), yy);
		else if (col1 == 3)
			return rec(n >> 1, m >> 1, 0, x - (n >> 2), y - (m >> 1), xx - (n >> 2), yy - (m >> 1));
		else
			return rec(n >> 2, m, 1, x - (n - (n >> 2)), y, xx - (n - (n >> 2)), yy);
	}
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
	
	int n, r, c;
	string s;
	cin >> n >> r >> c >> s;
	//cerr << s << "\n";
	for (auto i : s) {
		int rr = r, cc = c;
		if (i == 'U' || i == 'D') rr += (i == 'U' ? -1 : 1);
		if (i == 'R' || i == 'L') cc += (i == 'R' ? 1 : -1);
		check = (r == 3 && c == 8 && rr == 2 && cc == 8);
		//char res = rec((1 << n), (1 << (n + 1)), 1, r, c, rr, cc);
		cout << rec((1 << n), (1 << (n + 1)), 1, r, c, rr, cc);
		//cerr << r << " " << c << ", " << rr << " " << cc << " : " << res << "\n";
		r = rr, c = cc;
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
