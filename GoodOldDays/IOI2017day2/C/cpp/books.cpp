#include "books.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e6 + 11;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


ll res;
int n, p[N];
bool was[N];
set < int > q;

int get (int l, int r) {
	if (l > r)
		swap(l, r);

	auto it = q.upper_bound(l);
	if (it == q.end() || *it >= r)
		return -1;

	return *it;
}

void solve (int i) {
	was[i] = 1;
	q.erase(i);

	if (!was[p[i]]) 
		solve(p[i]);			
	
	
	while (1) {
		int j = get(i, p[i]);
		if (j == -1)
			break;
		solve(j);
	}
}


ll minimum_walk(vi P, int s) {
	n = sz(P);
	
	for (int i = 0; i < n; ++i)
		p[i] = P[i];
	
	for (int i = 0; i < n; ++i)
		res += abs(i - p[i]);
	
	for (int i = 0; i < n; ++i)
		q.insert(i);	
	
	int j = n - 1;
	while (j >= 0 && p[j] == j)
		--j;

	for (int i = 0; i <= j; ++i)
		if (!was[i]) {
			if (i)
				res += 2;
			solve(i);
		}
		
	return res;		
}
