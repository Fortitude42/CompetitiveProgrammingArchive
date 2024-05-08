#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 4e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int maxn = 1e6 + 12;


pii ans;
ll res;
int nxt[M][4];
int x[M], y[M];
int r, c, n, m, cur[maxn], cur1[maxn], t[maxn << 2], cnt[maxn];
set < int > q;
vi valx, valy;
bool used[2][M][4];
vector < pii > path[2];
vector < pii > xx[maxn], yy[maxn];


void update(int pos, int x, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);			

	t[v] = t[v << 1] + t[v << 1 | 1];
}

int get(int l, int r, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
}

void add(int pos) {
	++cnt[pos];
//	cerr << "add " << pos << endl;
	if (cnt[pos] == 1) {
		q.insert(pos);
		update(pos, 1);
	}
}

void del(int pos) {
	--cnt[pos];
//	cerr << "del " << pos << endl;
	if (cnt[pos] == 0) {
		q.erase(pos);
		update(pos, 0);
	}
}

void mark(pii v, int lvl) {
	assert(!used[lvl][v.f][v.s]);
	path[lvl].pb(v);
	used[lvl][v.f][v.s] = 1;
	int j = nxt[v.f][v.s], d;
	if (j == -1)
		return;
	if (j <= n)
		d = (v.s + (v.s & 1 ? -1 : 1)) % 4;
	else
		d = (3 - v.s);

	mark(mp(j, d), lvl);
}

void clear() {
	for (auto x : valx)
		xx[x].clear();
	valx.clear();

	for (auto y : valy) 
		yy[y].clear();
	valy.clear();

	for (int lvl = 0; lvl < 2; ++lvl) {
		path[lvl].clear();
		for (int i = 0; i <= n + m + 1; ++i)
			for (int d = 0; d < 4; ++d)
				used[lvl][i][d] = 0;
	}
	
}


void checkx(int x, int l, int r) {
	res += get(l, r);
	auto it = q.lower_bound(l);
	if (it != q.end() && *it <= r) {
		ans = min(ans, mp(x, *it));
	}
}

void checky(int y, int l, int r) {
	res += get(l, r);
	auto it = q.lower_bound(l);
	if (it != q.end() && *it <= r) {
		ans = min(ans, mp(*it, y));
	}
}
 
void solve(int tt) {
	cout << "Case " << tt << ": ";
	cin >> c >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	

	for (int j = n + 1; j <= n + m; ++j)
		cin >> x[j] >> y[j];
	if (r == 1 && n + m == 0) {
		cout << "0\n";
		clear();
		return;
	}

	x[0] = 1, y[0] = 0;
	x[n + m + 1] = r;
	y[n + m + 1] = c + 1;

	valx = {1, r};
	valy = {1, c};

	for (int i = 1; i <= n + m; ++i) {
		xx[x[i]].pb(mp(y[i], i));
		yy[y[i]].pb(mp(x[i], i));
		valx.pb(x[i]);
		valy.pb(y[i]);
	}


	sort(all(valx));
	valx.resize(unique(all(valx)) - valx.begin());

	sort(all(valy));
	valy.resize(unique(all(valy)) - valy.begin());

	for (auto x : valx)
		sort(all(xx[x]));
	
	for (auto y : valy) 
		sort(all(yy[y]));
		

	for (int i = 0; i <= n + m + 1; ++i) {
		memset(nxt[i], -1, sizeof nxt[i]);
		//right
		int j = upper_bound(all(xx[x[i]]), mp(y[i], i)) - xx[x[i]].begin();
		if (j < sz(xx[x[i]])) 
			nxt[i][0] = xx[x[i]][j].s;

		//left
		j = lower_bound(all(xx[x[i]]), mp(y[i], i)) - xx[x[i]].begin() - 1;
		if (j >= 0) 
			nxt[i][2] = xx[x[i]][j].s;

		//down
		j = upper_bound(all(yy[y[i]]), mp(x[i], i)) - yy[y[i]].begin();
		if (j < sz(yy[y[i]]))
			nxt[i][3] = yy[y[i]][j].s;

		//up
		j = lower_bound(all(yy[y[i]]), mp(x[i], i)) - yy[y[i]].begin() - 1;
		if (j >= 0)                                          
			nxt[i][1] = yy[y[i]][j].s;		
	}


	mark(mp(0, 0), 0);
	mark(mp(n + m + 1, 2), 1);

	if (sz(path[0]) > 1) {
		pii x = path[0][1];
		if (used[1][x.f][2]) {
			cout << 0 << "\n";
			assert(sz(path[0]) == sz(path[1]));
			clear();
			return;
		}		
	}



	vector < pair < int, pii > > hor;
	vector < pair < int, pii > > ver;
	for (int i = 0; i < sz(path[0]); ++i) {
		if (!(path[0][i].s & 1)) {//horizontal
			int curx = x[path[0][i].f];
			int l = y[path[0][i].f];
			int r = (i + 1 < sz(path[0])) ? y[path[0][i + 1].f] : (path[0][i].s == 0 ? (c + 1) : 0);
			if (l > r)
				swap(l, r);

			l++;
			r--;

			if (l <= r) 
				hor.pb(mp(curx, mp(l, r)));
		} else {//vertical
			int cury = y[path[0][i].f];			
			int lf = x[path[0][i].f];
			int rg = (i + 1 < sz(path[0])) ? x[path[0][i + 1].f] : (path[0][i].s == 3 ? (r + 1) : 0);

			if (lf > rg)
				swap(lf, rg);

			lf++;
			rg--;
//			cerr << cury << ' ' << lf << ' ' << rg << endl;

			if (lf <= rg) 
				ver.pb(mp(cury, mp(lf, rg)));
		}
	}   	


	for (auto y : valy) {
		cur[y] = 0;

		if (cur[y] < sz(yy[y])) {
			int ind1 = yy[y][cur[y]].s;
			if (used[1][ind1][1])
				add(y);			
		}		

		cur1[y] = 0;
	}

	sort(all(hor));
	int j = 0;
	ans = mp(inf, inf);
	res = 0;

	for (int ix = 0; ix < sz(valx); ++ix) {
		int x = valx[ix];
		for (auto tmp : xx[x]) {
			int y = tmp.f, ind = tmp.s;
			if (used[1][ind][1])
				del(y);

			++cur[y];
			if (cur[y] < sz(yy[y])) {
				int ind1 = yy[y][cur[y]].s;
				if (used[1][ind1][1])
					add(y);
			}
		}

		if (ix > 0) {
			for (auto tmp : xx[valx[ix - 1]]) {		
				int y = tmp.f, ind = tmp.s;
				if (cur1[y]) {
					del(y);
					cur1[y] = 0;
				}

				if (used[1][ind][3]) {
					add(y);
					cur1[y] = 1;
				}
			}
		}

		while (j < sz(hor) && hor[j].f == x) {
			checkx(x, hor[j].s.f, hor[j].s.s);
			j++;
		}
	}

	for (auto y : valy)
		while (cnt[y] > 0)
			del(y);

	for (auto x : valx) {
		cur[x] = 0;

		if (cur[x] < sz(xx[x])) {
			int ind1 = xx[x][cur[x]].s;
			if (used[1][ind1][2])
				add(x);
		}
		cur1[x] = 0;
	}

	sort(all(ver));
	j = 0;
	for (int iy = 0; iy < sz(valy); ++iy) {
		int y = valy[iy];
		for (auto tmp : yy[y]) {
			int x = tmp.f, ind = tmp.s;
			if (used[1][ind][2])
				del(x);

			++cur[x];
			if (cur[x] < sz(xx[x])) {
				int ind1 = xx[x][cur[x]].s;
				if (used[1][ind1][2])
					add(x);
			}
		}

		if (iy > 0) {
			for (auto tmp : yy[valy[iy - 1]]) {		
				int x = tmp.f, ind = tmp.s;
				if (cur1[x]) {
					del(x);
					cur1[x] = 0;
				}

				if (used[1][ind][0]) {
					add(x);
					cur1[x] = 1;
				}
			}
		}

		while (j < sz(ver) && ver[j].f == y) {
			checky(y, ver[j].s.f, ver[j].s.s);
			if (ver[j].s.s == r && cur[r] == sz(xx[r])) {
				++res;
				ans = min(ans, mp(r, y));
			}
			j++;
		}
	}

	for (auto x : valx)
		while (cnt[x] > 0)
			del(x);

	clear();
	if (!res) {
		cout << "impossible\n";
		return;
	}
	cout << res << ' ' << ans.f << ' ' << ans.s << "\n";


}

main () {
	int tt = 0;
	while (cin >> r) {
		solve(++tt);
	}
}