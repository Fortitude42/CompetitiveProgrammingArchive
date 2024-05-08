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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, cnt[M][2];
ll sum[M][2];
vi pos[2];
char s[M];


int getcnt(int l, int r, int i) {
	return cnt[r][i] - cnt[l - 1][i];
}

ll getsum(int l, int r, int i) {
	return sum[r][i] - sum[l - 1][i];
}

void solve() {
	pos[0].clear(), pos[1].clear();

	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%c", &s[i]);


	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			sum[i][j] = sum[i - 1][j];
			cnt[i][j] = cnt[i - 1][j];
		}


		if (s[i] == '>') {
			pos[0].pb(i);
			cnt[i][0]++;
			sum[i][0] += i;
		}else {
			pos[1].pb(i);
			cnt[i][1]++;
			sum[i][1] += i;		
		}
	}

	int i0 = 0, i1 = 0;
	for (int i = 1; i <= n; ++i) {
		ll res = 0;
		if (s[i] == '>') {
			i0++;
			int l = getcnt(1, i - 1, 0);
			int r = getcnt(i, n, 1);
			int x = min(l, r);
			if (x > 0) {
				int tmp = pos[1][i1 + x - 1];
				res += 2*getsum(i, tmp, 1);
				tmp = pos[0][i0 - x - 1];
				res -= 2*getsum(tmp, i - 1, 0);
			}


			if (r == x)
				res += (n +  1 - i);
			else 
				res += 2*pos[1][i1 + x] - i;			
		} else {
			i1++;
			int l = getcnt(1, i, 0);
			int r = getcnt(i + 1, n, 1);
			int x = min(l, r);
			if (x > 0) {
				int tmp = pos[0][i0 - x];
				res -= 2*getsum(tmp, i, 0);
				tmp = pos[1][i1 + x - 1];
				res += 2*getsum(i + 1, tmp, 1);
			}


			if (l == x)
				res += i;
			else 
				res += n + 1 + i - 2*pos[0][i0 - 1 - x];			
		}

		printf("%lld ", res);

	}
	printf("\n");

}

main () {
  int TT;
  TT = 1;
  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}