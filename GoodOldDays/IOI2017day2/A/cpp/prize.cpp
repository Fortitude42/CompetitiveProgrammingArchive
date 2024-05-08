#include "prize.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int t[N << 2], n, T[N];
bool was[N];
pii tt[N];
 
void update (int pos, int x, int v = 1, int tl = 0, int tr = n - 1) {
    t[v] += x;
	if (tl == tr)
		return;
 
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);
}
 
int p[N];
int get2 (int k, int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr)
		return tl;
 
	int tm = (tl + tr) >> 1;
 
	if (t[v << 1] < k)
		return get2(k - t[v << 1], v << 1 | 1, tm + 1, tr);
 
	return get2(k, v << 1, tl, tm);
}
 
pii get (int pos) {
	if (was[pos])
		return tt[pos];
 
	was[pos] = 1;
	vi v = ask(pos);
	return tt[pos] = mp(v[0], v[1]);		
}
 
void inc (int pos) {
	while (pos < n) {
		++T[pos];
		pos |= pos + 1;
	}
}
       
int get1 (int r) {
	int res = 0;
	while (r >= 0) {
		res += T[r];
		r = (r & (r + 1)) - 1;
	}
 
	return res;
}
 
 
 
 
int find_best(int _n) {
	n = _n;
	srand(time(0));
 
	for (int i = 0; i < n; ++i)
		update(i, 1);	
	
	vector < pii > V;
	int timer = 0;          
	for (int i = 0; timer < 480 ; i = (i + block) % n) {
		++timer;
		while (was[i])
			i = (i + 1) % n;

		V.pb({get(i).f + get(i).s, i});
	}
	
	sort(all(V));
 
	if (!V[0].f) 
		return V[0].s;
	cerr << sz(V) << ' ' << V.back().f << endl;	
	int cnt = V.back().f;
	set < int > q;
	for (auto x : V) {
		q.insert(x.s);
		if (x.f != V.back().f)  {
			update(x.s, -1); 
			inc(x.s);
			--cnt;
		}   
	}
 
	int l = 1;		                
 
	                       
	while (cnt) {
		int r = t[1];
		int mxPos = inf, mnPos = -1;
		for (auto x : q)
			if (get(x).f > get1(x - 1)) 
				mxPos = min(mxPos, x); 
			else if (get(x).f == get1(x))
				mnPos = max(mnPos, x);

		while (l <= r) {
			int mid = (l + r) >> 1;
			int pos = get2(mid);

			if (pos > mxPos) { 
			    r = mid - 1;
				continue;      
			}
			if (pos < mnPos) {
				l = mid + 1;
				continue;
			}
			q.insert(pos);
			if (get(pos).f + get(pos).s != V.back().f) {
				cnt--;
				update(pos, -1);
				inc(pos);
				if (get(pos).f + get(pos).s == 0) 
					return pos;				
				break;
			}
 
			if (get(pos).f != get1(pos)) 
				r = mid - 1;
			else
				l = mid + 1;
		}
	}
		
	return 0;
}