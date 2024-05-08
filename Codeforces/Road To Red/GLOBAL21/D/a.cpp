//template by paradox & gege & parasat
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
const int N = 2e5 + 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, a[M], l1[M], r1[M], l2[M], r2[M], d[M];
stack < int > st;
queue < int > q;
pii t[M << 2][4];

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v][0] = mp(l1[tl], tl);
		t[v][1] = mp(l2[tl], tl);
		t[v][2] = mp(r1[tl], tl);
		t[v][3] = mp(r2[tl], tl);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	for (int i = 0; i < 4; ++i) {
		if (i < 2)
			t[v][i] = min(t[v << 1][i], t[v << 1 | 1][i]);
		else
			t[v][i] = max(t[v << 1][i], t[v << 1 | 1][i]);
	}
}

void del(int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v][0] = t[v][1] = mp(inf, inf);
		t[v][2] = t[v][3] = mp(-inf, -inf);
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		del(pos, v << 1, tl, tm);
	else
		del(pos, v << 1 | 1, tm + 1, tr);

	for (int i = 0; i < 4; ++i) {
		if (i < 2)
			t[v][i] = min(t[v << 1][i], t[v << 1 | 1][i]);
		else
			t[v][i] = max(t[v << 1][i], t[v << 1 | 1][i]);
	}	
}

pii get(int l, int r, int lvl, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return lvl < 2 ? mp(inf, inf) : mp(-inf, -inf);

	if (l <= tl && tr <= r)
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	
	pii a = get(l, r, lvl, v << 1, tl, tm);
	pii b = get(l, r, lvl, v << 1 | 1, tm + 1, tr);

	if (lvl < 2)
		return min(a, b);
	return max(a, b);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		while (sz(st) && a[st.top()] > a[i])
			st.pop();

		l1[i] = !sz(st) ? 1 : (st.top() + 1);
		st.push(i);
	}

	while (sz(st)) 
		st.pop();

	for (int i = 1; i <= n; ++i) {
		while (sz(st) && a[st.top()] < a[i])
			st.pop();

		l2[i] = !sz(st) ? 1 : (st.top() + 1);
		st.push(i);
	}

	while (sz(st)) 
		st.pop();

	for (int i = n; i > 0; --i) {
		while (sz(st) && a[st.top()] > a[i])
			st.pop();

		r1[i] = !sz(st) ? n : (st.top() - 1);
		st.push(i);
	}

	while (sz(st)) 
		st.pop();

	for (int i = n; i > 0; --i) {
		while (sz(st) && a[st.top()] < a[i])
			st.pop();

		r2[i] = !sz(st) ? n : (st.top() - 1);
		st.push(i);
	}

	while (sz(st)) 
		st.pop();

	build();
	for (int i = 1; i <= n; ++i)
		d[i] = -1;

	d[1] = 0;
	q.push(1);
	del(1);

	while (sz(q)) {
		int i = q.front();
		q.pop();

		while (1) {
			int j = get(l1[i], i, 3).s;
			if (j < 0 || r2[j] < i)
				break;

			del(j);
			q.push(j);
			d[j] = d[i] + 1;
		}

		while (1) {
			int j = get(i, r1[i], 1).s;
			if (j > n || l2[j] > i)
				break;

			del(j);
			q.push(j);
			d[j] = d[i] + 1;
		}

		while (1) {
			int j = get(l2[i], i, 2).s;
			if (j < 0 || r1[j] < i)
				break;

			del(j);
			q.push(j);
			d[j] = d[i] + 1;
		}

		while (1) {
			int j = get(i, r2[i], 0).s;
			if (j > n || l1[j] > i)
				break;

			del(j);
			q.push(j);
			d[j] = d[i] + 1;
		}
	}

	cout << d[n] << endl;
}

main () {
	int TT;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}