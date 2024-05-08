//by paradox & gege & parasat
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
const int N = (1 << 20), inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int st[M];
pii arr[M];
vi bits[M], cnt[10000001];


void solve() {
	int n;
	cin >> n;
	int m = (1 << n);
	for (int i = 0; i < m; i++){
		cin >> arr[i].f;
	    st[i] = arr[i].f;
		arr[i].s = i;
		cnt[st[i]].pb(i);
	}

	m = 0;
	for(int i = 0; i <= (int)1e7; i++){
		random_shuffle(all(cnt[i]));2
		for(auto x : cnt[i]){
			arr[m++] = {i, x};
		}
	}
    
    int k = 175;

    for(int i = 0; i < min(m, k); i++){
    	for(int j = i + 1; j < m; j++){
    		int x = arr[i].s, y = arr[j].s;
    		if(st[x] + st[y] < st[x & y] + st[x | y]){
    			printf("%d %d\n", x, y);
    			return;
    		}
    	}
    }
    for(int i = max(0, m - k); i < m; i++){
    	for(int j = i + 1; j < m; j++){
    		int x = arr[i].s, y = arr[j].s;
    		if(st[x] + st[y] < st[x & y] + st[x | y]){
    			printf("%d %d\n", x, y);
    			return;
    		}
    	}
    }


	for (int i = 0; i < m; i++)
    	for (int j = 0; j < n; j++)
	      if ((i >> j) & 1)
    	    bits[i].pb(j);
  
    for (int i = 0; i < m; i++) {
      if (sz(bits[i]) < 2)
        continue;

    for (int j1 = 0; j1 < sz(bits[i]); j1++) {
      for (int j2 = j1 + 1; j2 < sz(bits[i]); j2++) {
        for (int k1 = 0; k1 <= 1; k1++) {
          for (int k2 = 0; k2 <= 1; k2++) {
            int a = (k1 * i) ^ (1 << j1);
            int b = (k2 * i) ^ (1 << j2);
            int c = a & b;
            if ((a | b) == i && st[a] + st[b] < st[i] + st[c]) {
              printf("%d %d\n", a, b);
              return;
            }
          }
        }
      }
    }
    }


    puts("-1");
}

main () {
	fastio
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
