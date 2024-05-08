#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
//#define int long long
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

 
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e3 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 0;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], s[N], cnt[N], ans;
vi g[N], pos[N], vals;
ll cnt1[N];

inline void precalc() {
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i) 
            g[j].pb(i);                 
} 

inline void add(int &x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    precalc();

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (auto y : g[i])
            pos[y].pb(x);
    }        

    for (int x = N - 1; x > 0; --x) {
        if (sz(pos[x]) < block) {
            for (auto y : pos[x])
                for (auto z : pos[x])
                    add(s[x], __gcd(y, z));
        } else {
            for (auto y : pos[x])
                ++cnt[y];

            for (int y = N - 1; y > 0; --y) {
                int cnt2 = 0;
                for (int z = y; z < N; z += y)
                    cnt2 += cnt[z];

                cnt1[y] += cnt2 * 1ll * cnt2;

                add(s[x], y * 1ll * cnt1[y] % mod);
                
                if (cnt1[y]) {
                    for (auto z : g[y])
                        cnt1[z] -= cnt1[y];
                }
            }
            memset(cnt1, 0, sizeof(cnt1));

            for (auto y : pos[x])
                cnt[y] = 0;
        }

        for (int y = x + x; y < N; y += x)
            add(s[x], mod - s[y]);
        add(ans, s[x] * 1ll * x % mod);
    }

    cout << ans << endl;
}