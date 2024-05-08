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
 
const int inf = 1e9, maxn = (1 << 20) + 100, mod = 1e9 + 7, N = 66;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 

int n, m, a[N][N], b[N], c[N];
int val1[N], val2[N];

void solve1(){
  int h1 = (m / 2), h2 = m - h1;
  ll S = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(j < h1 && a[i][j])
          val1[i] += (1 << j);
        else if(a[i][j]) 
          val2[i] += (1 << (j - h1));
     }
     if(b[i]) S += (1 << i);
  }    


  unordered_map<ll, pair<ll, int> > f;
  int L, R;

  for(int msk = 0; msk < (1 << h1); msk++){
    long long res = 0, sum = 0;
    
    for(int i = 0; i < n; i++){
      int cnt = (__builtin_popcount(msk & val1[i]) & 1);
      if(cnt) res += (1ll << i);
    }

    for(int i = 0; i < h1; i++)
      if((msk >> i) & 1)
        sum += c[i];
    
    if(!f.count(res)) f[res] = {sum, msk};
    else f[res] = max(f[res], {sum, msk});

  } 
              
  ll ans = -INF;

  for(int msk = 0; msk < (1 << h2); msk++){
    long long res = 0, sum = 0;
    
    for(int i = 0; i < n; i++){
      int cnt = (__builtin_popcount(msk & val2[i]) & 1);
      if(cnt) res += (1ll << i); 
    }

    for(int i = 0; i < h2; i++)
      if((msk >> i) & 1)
        sum += c[h1 + i];

    if(f.count(S ^ res)){
      pair<long long, int> now = f[S ^ res];
      long long cur = sum + now.f;
      if(ans < cur){
        ans = cur;
        R = msk;
        L = now.s;
      }                                
    }
  }

  if(ans == -INF) cout << "-1\n";
  else{
    cout << ans << "\n";
    for(int i = 0; i < n; i++){
      if(i < h1) cout << (L >> i & 1);
      else cout << (R >> (i - h1) & 1);
      cout << " ";
    }
    cout << "\n";
  }
}

int e[N];
ll p[2][maxn];
ll dp[2][maxn];
 
void solve2() {  
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i)
      if (a[i][j])
        e[j] |= (1 << i);
  }


  for (int mask = 0; mask < (1 << n); ++mask)
    dp[0][mask] = -inf;

  dp[0][0] = 0;
  dp[0][e[0]] = c[0];
  p[0][e[0]] = 1;

  for (int j = 1; j < m; ++j) 
    for (int mask = 0; mask < (1 << n); ++mask) {
      dp[j & 1][mask] = dp[(j - 1) & 1][mask];
      p[j & 1][mask] = p[(j - 1) & 1][mask];
      if (dp[(j - 1) & 1][mask ^ e[j]] > -inf && dp[j & 1][mask] < dp[(j - 1) & 1][mask ^ e[j]] + c[j]) {
        dp[j & 1][mask] = dp[(j - 1) & 1][mask ^ e[j]] + c[j];
	      p[j & 1][mask] = p[(j - 1) & 1][mask ^ e[j]] ^ (1ll << j);
      }
    }    

  int mask = 0;
  for (int i = 0; i < n; ++i)
    if (b[i])
      mask |= (1 << i);

  if (dp[(m - 1) & 1][mask] == -inf) {
    cout << -1 << endl;
    return;
  }
  
  cout << dp[(m - 1) & 1][mask] << endl;
	for (int j = 0; j < m; ++j)
		if (p[(m - 1) & 1][mask] & (1ll << j))
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
}

main () {
  fastio;
  cin >> m >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      cin >> a[i][j];
    cin >> b[i];
  }
  for(int i = 0; i < m; i++)
    cin >> c[i];
  if(m <= 40)
    solve1();
  else
    solve2();
}
