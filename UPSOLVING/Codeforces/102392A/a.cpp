#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define f first
#define s second

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef long long ll;


const int N = 2e5, MOD = 1e9 + 7, inf = 1e9;
const int M = N + 11;

int was[M], good[M][2];
int n, m, tt[M][2];
vi g[M];

void inc(int pos, int lvl, int x) {	
	while (pos <= n) {
		tt[pos][lvl] += x;
		pos |= pos + 1;
	}
}

int getPrv(int x) {
	return x == 1 ? n : x - 1;
}

int getNxt(int x) {
	return x == n ? 1 : x + 1;
}


void check(int x) {
	int prv = getPrv(x);
	int nxt = getNxt(x);

	bool cur = (was[prv] != was[x] && was[nxt] != was[x]);
	if (was[x] && good[x][0]) {
		inc(x, 0, -1);
		good[x][0] = 0;
	}

	if (!was[x] && good[x][1]) {
		inc(x, 1, -1);
		good[x][1] = 0;
	}

	if (good[x][was[x]] != cur) {
		if (!good[x][was[x]]) {
			inc(x, was[x], 1);
			good[x][was[x]] = 1;
		} else {
			inc(x, was[x], -1);
			good[x][was[x]] = 0;	
		}
	}
}

void col(int x) {
	was[x] = 1;
	int prv = getPrv(x);
	int nxt = getNxt(x);
	check(x);
	check(prv);
	check(nxt);
}

 
int get(int r, int  lvl) {
	int res = 0;
	while (r > 0) {
		res += tt[r][lvl];
		r = (r & (r + 1)) - 1;
	}
 
	return res;
}
 
int get1(int l, int r, int lvl) {
	if (l > r)
		return 0;

	return get(r) - get(l - 1);
}

struct node{
	int cnt;
	int fst;
	int lst;
} t[M << 2], E;


void build(int v = 1, int tl = 1, int tr = n) {
	t[v].cnt = 1;
	t[v].lst = t[v].fst = 0;

	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}


node merge(const node &l, const node &r) {
	if (l.cnt == -1)
		return r;

	if (r.cnt == -1)
		return l;

	node res;
	res.fst = l.fst;
	res.lst = r.lst;
	res.cnt = l.cnt + r.cnt - (l.lst == r.fst);
	return res;
}

void update(int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v].cnt = 1;
		t[v].lst = t[v].fst = 1;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, v << 1, tl, tm);
	else
		update(pos, v << 1 | 1, tm + 1, tr);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

node get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return E;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return merge(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}



void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		g[x].pb(i);
	}

	build();

	for (int i = 1; i <= m; ++i) {
		if (!sz(g[i])) {
			printf("-1 ");
			continue;
		}

		int ans = n - sz(g[i]);
		for (int j = 0; j < sz(g[i]); ++j) {
			int cur = g[i][j];
			int nxt = g[i][(j + 1) % sz(g[i])];

			if (cur < nxt) {
				if (cur + 1 <= nxt - 1) {
					node nd = get(cur + 1, nxt - 1).cnt;
					ans += get(cur + 1, nxt - 1).cnt - 1; 					
					ans -= get1(cur + 2, nxt - 2);
				}
			} else {
				if (cur == n && nxt == 1)
					continue;

				if (cur == n) {
					ans += get(1, nxt - 1).cnt - 1; 
					ans -= (get1(2, nxt - 2) + 1) / 2; 
				}
				else if (nxt == 1)	 {
					ans += get(cur + 1, n).cnt - 1;
					ans -= (get1(cur + 2, n - 1) + 1) / 2;
				}
				else {
					if (i == 3) {
						cerr << merge(get(cur + 1, n), get(1, nxt - 1)).cnt - 1 << endl; 
						cerr << get1(1, nxt - 2) + get1(cur + 2, n) << endl;
					}

					ans += merge(get(cur + 1, n), get(1, nxt - 1)).cnt - 1;
					ans -= (get1(1, nxt - 2) + get1(cur + 2, n) + 1) / 2;
				}
			}
		}

		for (auto x : g[i]) {
			update(x);			
			col(x);
		}
		printf("%d ", ans);
	}
}

main() {
	E.cnt = -1;

	int TT = 1;
	//scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}