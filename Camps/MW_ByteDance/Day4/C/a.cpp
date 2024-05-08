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

pii res[N];
int w, h, n, A, B, yl[N], yr[N], xu[N], xd[N];

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
	inline ll area(pt p1, pt p2) {
		pt cur = {x, y};
		return ((p1 - cur) % (p2 - cur));
	}
} hole[N];

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
		hole[i] = {x, y};
	}
	scanf("%d", &A);
	for (int i = 1; i <= A; i++)
		scanf("%d %d", &yl[i], &yr[i]);
	scanf("%d", &B);
	for (int i = 1; i <= B; i++)
		scanf("%d %d", &xu[i], &xd[i]);
	yl[0] = yr[0] = 0;
	sort(yl, yl + A + 1);
	sort(yr, yr + A + 1);
	xu[0] = xd[0] = 0;
	sort(xu, xu + B + 1);
	sort(xd, xd + B + 1);

	for (int i = 1; i <= n; i++) {
		int l = 1, r = A, row = A + 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			pt pl1 = {0, yl[mid - 1]}, pl2 = {0, yl[mid]}, pr1 = {w, yr[mid - 1]}, pr2 = {w, yr[mid]};
			if (hole[i].area(pl2, pr2) > 0/*(hole[i] - pl2) * (pl1 - pl2) < 0 || (hole[i] - pr2) * (pr1 - pr2) < 0*/)
				l = mid + 1;
			else {
				row = mid;
				r = mid - 1;
			}
		}
		l = 1, r = B;
		int col = B + 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			pt pl1 = {xd[mid - 1], 0}, pl2 = {xd[mid], 0}, pr1 = {xu[mid - 1], h}, pr2 = {xu[mid], h};
			if (hole[i].area(pl2, pr2) < 0/*(hole[i] - pl2) * (pl1 - pl2) < 0 || (hole[i] - pr2) * (pr1 - pr2) < 0*/)
				l = mid + 1;
			else {
				col = mid;
				r = mid - 1;
			}
		}
		res[i] = {row, col};
	}
	int ans = 0;
	sort(res + 1, res + 1 + n);
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j < n && res[j + 1] == res[i])
			j++;
		ans = max(ans, j - i + 1);
		i = j;
	}
	printf("%d", ans);
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
