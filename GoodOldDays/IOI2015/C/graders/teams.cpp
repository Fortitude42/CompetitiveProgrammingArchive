#include "teams.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 5e5 + 12;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 850;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n;
 
 
struct node {
	int val;
	node *lft,*rgt;
 
	node(int _val,node *_l=0,node *_r=0): val(_val),lft(_l),rgt(_r) {}
 
	node* insert(int l,int r,int k) {
		if (k<l||k>=r) return this;
		if (l+1==r) return new node(this->val+1,lft,rgt);
		int m=(l+r)>>1;
		return new node(this->val+1,lft->insert(l,m,k),rgt->insert(m,r,k));
	}
 
	int query(int l,int r,int ll,int rr) {
		if (rr<=l||ll>=r) return 0;
		if (ll<=l&&rr>=r) return this->val;
		int m=(l+r)>>1;
		return lft->query(l,m,ll,rr)+rgt->query(m,r,ll,rr);
	}
}; 

typedef node * pnode;
pnode root[N];
 
vi g[N];
bool was[N];
int cnt[1000], pos[N];
vpii c;
 
      	
              
void init(int _n, int a[], int b[]) {
	n = _n;
	for (int i = 0; i < n; ++i)  {
		g[a[i]].pb(b[i]);          
		was[a[i]] = 1; 
		c.pb(mp(a[i], b[i]));
	}
		
	root[0] = new node(0);
	root[0]->lft = root[0];
	root[0]->rgt = root[0];

	int j = 1;
	sort(all(c));
	for (int i = 0; i < sz(c); ++i) {
		pos[c[i].f] = i + 1;
		root[i + 1] = root[i]->insert(1, n + 1, c[i].s);
	}

	for (int i = 1; i <= n; ++i)
		if (!pos[i])
			pos[i] = pos[i - 1];
}
 
int can(int m, int k[]) {
	int sum = 0;
	
	vpii vv;
	vi vals;
 
	for (int i = 0; i < m; ++i) {
		sum += k[i];
		if (sum > n)
			return 0;
		vals.pb(k[i]);
	}
 
	sort(all(vals));
	for (int i = 0; i < sz(vals); ) {
		int j = i, s = 0;
		while (j < sz(vals) && vals[i] == vals[j]) 
			s += vals[j++];
 
		vv.pb(mp(vals[i], s));		
		i = j;
	}
 
/*		
	if (m > block) {
		priority_queue < int, vi, greater < int > > q;
		int j = 0;
		for (auto x : vv) {
			while (j <= x.f) {
				for (auto b : g[j])
					if (b >= x.f)
						q.push(b);	
				++j;
			}
			
			while (sz(q) && x.s) {
				if (q.top() >= x.f)
					--x.s;
				q.pop();			
			}
 
			if (x.s)
				return 0;
		}
		return 1;
	}*/
 
 
	for (int i = 0; i < sz(vv); ++i)
		cnt[i] = 0;

	for (int i = 0; i < sz(vv); ++i) {
		int rest = vv[i].s;
		for (int j = i; j < sz(vv); ++j) {
			int cur = root[pos[vv[i].f]]-> query(1, n + 1, vv[j].f, (j == sz(vv) - 1 ? n + 1 : vv[j + 1].f)) - cnt[j];
//			cerr << i << ' ' << cur << ' ' << vv[j].f << ' ' << (j == sz(vv) - 1 ? n : vv[j + 1].f - 1) << ' ' << cnt[j] << endl;
			cnt[j] += min(cur, rest);
			rest -= min(cur, rest);
			if (!rest)
				break;
		}
 
		if (rest)
			return 0;
	}
		
 
	return 1;
}