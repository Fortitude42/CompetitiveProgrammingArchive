#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, q, a, b, x, y;
char s[N], t[6];
set < int > pos;


struct ST {
	int tl, tr, sum;
	ST *l, *r;

	ST () {
		l = r = NULL;
	}
	
	ST (int lf, int rg) {
		tl = lf, tr = rg;
		sum = 0;
		l = r = NULL;
	}


	void update (int pos, int x) {
	   	sum += x;

		if (tl == tr)
			return;

		int tm = (tl + tr) >> 1;			
		if (pos <= tm) {
			if (!l)
				l = new ST(tl, tm);
			l->update(pos, x);
			return;
		}

		if (!r)
			r = new ST(tm + 1, tr);
		r->update(pos, x);
	}

	int get (int lf, int rg) {
		if (lf > rg || tl > rg || lf > tr)
			return 0;
		if (lf <= tl && tr <= rg)
			return sum;
	
		return (!l ? 0 : l->get(lf, rg)) + (!r ? 0 : r->get(lf, rg));
	}
} *T[N << 2];

void upd (int l, int r, int x, int y, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;
	
	if (l <= tl && tr <= r) {
		if (!T[v]) {
			T[v] = new ST(1, n); 
			cerr << v << endl;
		}
		T[v]->update(x, y);
		return;
	}

	int tm = (tl + tr) >> 1;
	upd(l, r, x, y, v << 1, tl, tm);
	upd(l, r, x, y, v << 1 | 1, tm + 1, tr);
}

int get (int x, int y, int v = 1, int tl = 1, int tr = n) {
	int res = 0;
	
	if (T[v])
		res += T[v]->get(1, y);
	
	if (tl == tr)
		return res;
	
	int tm = (tl + tr) >> 1;
	if (x <= tm)
		res += get(x, y, v << 1, tl, tm);
	else
		res += get(x, y, v << 1 | 1, tm + 1, tr);
	return res;
}


 
void update (int xa, int ya, int xb, int yb, int z) {
	upd(xa, xb, ya, z);
	if (yb < n)
		upd(xa, xb, yb + 1, -z);
}


main () {
	scanf("%d%d\n%s", &n, &q, s + 1);

	
	for (int i = 1; i <= n; ++i)
		if (s[i] == '0') 
			pos.insert(i);

	pos.insert(0);
	pos.insert(n + 1);
	
	
	for (int i = 1; i <= q; ++i) {
		scanf("\n%s%d", t, &a);
		if (t[0] == 't') {
			if (s[a] == '1') {
				auto it = pos.lower_bound(a);
				y = *it;
				--it;
				x = *it;

				++x, --y;

				update(x, a, a, y, i);
				pos.insert(a);
			} else {
				pos.erase(a);

				auto it = pos.lower_bound(a);
				y = *it;
				--it;
				x = *it;


				++x, --y;
				update(x, a, a, y, -i);
			}

			s[a] = '0' + '1' - s[a];
		} else {
			scanf("%d", &b);

			--b;

			int res = get(a, b);
			if (*pos.lower_bound(a) > b) 
				res += i; 			 
			printf("%d\n", res);
		}
	}

}