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
#define ppb pop_back
 
#define en end()
#define bg begin()
 
#define rev reverse
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
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
 
int n[2];
ll pos[2][N];
bool kick[2][N];
map < ll, ll > t;
vector < ll > D[2];
char tp[2][N], let[2][N];
vector < pair < ll, char > > V[2];


inline void input(int id, int &ptr) {
	char c;
	while (cin >> c) {
		if (c == 'E') break;
		ptr++;
		tp[id][ptr] = c;
		cin >> pos[id][ptr];
		if (c == 'I')
			cin >> let[id][ptr];
	}
}


void inc (ll pos, int x) {
	while (pos <= inf) {
		++t[pos];
		pos |= pos + 1;
	}
}

ll get (ll r) {
	ll res = 0;
	while (r >= 0) {
		if (t.count(r))
			res += t[r];
		r = (r & (r + 1)) - 1;		
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
 
	input(0, n[0]);
	input(1, n[1]);
 
	for (int id = 0; id <= 1; id++) {
		V[id].pb(mp(inf, 'z'));
		t.clear();

		for (int i = 1; i <= n[id]; i++) {
			if (tp[id][i] == 'I') {
				for (int x = 0; x < sz(V[id]); ++x)
					if (V[id][x].f >= pos[id][i])
						++V[id][x].f;

				V[id].pb(mp(pos[id][i], let[id][i]));
			} else {
				ll cnt = 0;

			 	for (int x = 0; x < sz(V[id]); ++x) {
			 		if (V[id][x].f == pos[id][i]) {
						swap(V[id][x], V[id].back());
						V[id].ppb();
						--x;
						cnt = -1;
						continue;
			 		}

					if (V[id][x].f > pos[id][i])
						--V[id][x].f;             
					else if (cnt != -1)
						++cnt;						
			 	}

				if (cnt != -1) {
					ll l = 0, r = inf, x = -1;
					while (l <= r) {
						ll mid = (l + r) / 2;
						if (mid - get(mid) >= pos[id][i] - cnt) {
							r = mid - 1;
							x = mid;
						} else
							l = mid + 1;
					}

					D[id].pb(x);
					inc(x, 1);
				}
			}
		}
	}

	sort(all(V[0]));
	sort(all(V[1]));
	sort(all(D[0]));
	sort(all(D[1]));

/*
	for (auto x : V[0])
		cerr << x.f << ' ' << x.s << endl;
	cerr << endl;
	for (auto x : V[1])
		cerr << x.f << ' ' << x.s << endl;

	cerr << endl;
	for (auto x : D[0])
		cerr << x << ' ';
	cerr << endl;
	for (auto x : D[1])
		cerr << x << ' ';*/

	cout << ((V[0] == V[1] && D[0] == D[1]) ^ 1) << endl; 
	return 0;
}