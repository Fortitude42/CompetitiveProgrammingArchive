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

vector < int > ord = {1, 0, 3, 2};
vector < int > check = {7, 8, 9, 12, 13, 16, 17, 18};
vector < vector < int > > moves = {{1, 3, 7, 12, 16, 21, 23}, {2, 4, 9, 13, 18, 22, 24}, {11, 10, 9, 8, 7, 6, 5}, {20, 19, 18, 17, 16, 15, 14}};

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;

	for (auto &i : check) i--;
	for (auto &i : moves) for (auto &j : i) j--;

	while (1) {
		string s;
		for (int i = 1; i <= 24; i++) {
			int x;
			scanf("%d", &x);
			if (!x) exit(0);
			s.pb(char(x + '0'));
		}
		map < string, string > path;
		path[s] = "";
		queue < pair < string, string > > q;
		q.push({s, ""});
		int tp;
		string best;
		while (!q.empty()) {
			string v = q.front().F;
			string curpath = q.front().S;
			q.pop();
			if (!best.empty() && sz(best) < sz(curpath))
				continue;
			int val = v[check[0]], ok = 1;
			for (auto i : check)
				ok &= (v[i] == val);
			if (ok && (best.empty() || curpath < best)) {
				tp = val;
				best = curpath;
			}
			for (int i = 0; i < 4; i++) {
				char c = 'A' + i;
				string t = v;
				for (int j = 0; j < 6; j++)
					swap(t[moves[i][j]], t[moves[i][j + 1]]);
				string newpath = curpath;
				newpath.pb(c);
				if (!path.count(t)) {
					path[t] = newpath;
					q.push({t, newpath});
				}
			}
			for (auto i : ord) {
				char c = 'A' + i;
				if (c == 'A') c = 'F';
				if (c == 'B') c = 'E';
				if (c == 'C') c = 'H';
				if (c == 'D') c = 'G';
				string t = v;
				for (int j = 6; j > 0; j--)
					swap(t[moves[i][j]], t[moves[i][j - 1]]);
				string newpath = curpath;
				newpath.pb(c);
				if (!path.count(t)) {
					path[t] = newpath;
					q.push({t, newpath});
				}
			}
		}
		if (best.empty()) puts("No moves needed");
		else { for (auto i : best) printf("%c", i); puts(""); }
		printf("%d\n", tp - '0');
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
