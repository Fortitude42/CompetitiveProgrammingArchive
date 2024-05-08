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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


vi gg[M];
bool can[M];
int n, m, prv[M], lst[M], t[M << 2];


void update(int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);

	t[v] = max(t[v << 1], t[v << 1 | 1]);
}


int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return -inf;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}


 
void solve() {
	cin >> n >> m;

	set < int > used;
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int c;
			cin >> c;
			used.insert(c);
			gg[i].pb(c);
		}
	}

	can[0] = 1;
	int lste = -1;

	for (int i = 1; i <= n; ++i) {
		int mx = 0;
		int mn = inf;

		for (auto c : gg[i]) {
			int j = prv[c];
			mx = max(mx, j);
			mn = min(mn, j);
			
			prv[c] = i;
			if (!j)
				continue;
			
			int j1 = lst[j - 1];
			if (!can[i] && get(j1 + 1, i - 1) <= j1)
				can[i] = 1;			
		}

		if (!sz(gg[i])) {
			can[i] = 1;
			lste = i;
		} else {
			if (lste >= mn && !can[i]) {
				int j1 = lst[lste - 1];
				if (get(j1 + 1, i - 1) <= j1)
					can[i] = 1;
			}
		}
			
		lst[i] = !can[i] ? lst[i - 1] : i;
		update(i, mx);
	}

		
	int ans = 0;

	set < int > q;
	for (int i = n; i > 0; --i) {
		bool bad = 0;
		for (auto c : gg[i]) {
			if (q.count(c)) {
				bad = 1;
				break;
			}
			q.insert(c);
		}
		if (bad)
			break;
		if (can[i - 1])	{
			if (i <= lste)
				ans = m;
			else
				ans = max(ans, sz(q));
		}			
	}

	cout << ans << endl;


	for (auto i : used)
		prv[i] = 0;	
	

	for (int i = 1; i <= n; ++i){
		can[i] = 0;
		gg[i].clear();	
	}
}

main () {
	fastio
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}