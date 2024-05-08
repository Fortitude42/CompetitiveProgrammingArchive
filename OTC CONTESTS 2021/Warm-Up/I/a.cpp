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
 
const int inf = 1e9, maxn = 1e6 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, m, a[N], d[maxn];
set < int > q;
ll t[N];

void inc(int pos, int x) {
	while (pos <= n) {
		t[pos] += x;
		pos |= pos + 1;
	}
}

ll get(int r) {
	ll res = 0;
	while (r > 0) {
		res += t[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

ll get(int l, int r) {
	return get(r) - get(l - 1);
}


void precalc() {
	for (int i = 1; i < maxn; ++i) {
		for (int j = i; j < maxn; j += i) {
			++d[j];
		}
	}
}

 
main () {
	precalc();

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > 2) {
			q.insert(i);
		}
		
		inc(i, a[i]);				
	}

	while (m--) {
		int tp, l, r;
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1) {
			while (1) {
				auto it = q.lower_bound(l);
				if (it == q.end() || *it > r)
					break;

				int cur = *it;
				inc(cur, -a[cur]);
				a[cur] = d[a[cur]];
				inc(cur, a[cur]);

				if (a[cur] <= 2)
					q.erase(cur);
				l = cur + 1;				
			}
		} else {
			printf("%lld\n", get(l, r));
		}
	}
}