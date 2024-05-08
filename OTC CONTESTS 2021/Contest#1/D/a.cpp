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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, k;
string s[N];
pii p[N];
vpii h[N];
map < pair < pii, pii >, int > cnt[N];
 
void precalc() {
	p[0] = {1, 1};
	for (int i = 1; i < N; ++i)
		p[i] = {p[i - 1].f * 1ll * base.f % Mod.f, p[i - 1].s * 1ll * base.s % Mod.s};
}

inline int norm(int x, int m) {
	while (x < 0)
		x += m;
	while (x >= m)
		x -= m;

	return x;
}

inline pii get(int i, int l, int r) {
	if (!l)
		return h[i][r];
	return {norm(h[i][r].f - h[i][l - 1].f * 1ll * p[r - l + 1].f % Mod.f, Mod.f), norm(h[i][r].s - h[i][l - 1].s * 1ll * p[r - l + 1].s % Mod.s, Mod.s)};
}

main() {
	precalc();

	fastio
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		h[i].resize(k);
		h[i][0] = {s[i][0], s[i][0]};
		for (int j = 1; j < k; ++j)
			h[i][j] = {(h[i][j - 1].f * 1ll * base.f + s[i][j]) % Mod.f, (h[i][j - 1].s * 1ll * base.s + s[i][j]) % Mod.s};
		
		for (int j = 0; j < k; ++j) 
			if (!j)
				++cnt[j][mp(mp(0, 0), get(i, j + 1, k - 1))];
			else if (j == k - 1)
				++cnt[j][mp(get(i, 0, j - 1), mp(0, 0))];
			else
				++cnt[j][mp(get(i, 0, j - 1), get(i, j + 1, k - 1))];
		
		++cnt[k][mp(mp(0, 0), h[i][k - 1])];
	}

	int mx = -1, j = -1, cnt1 = 0;

	for (int i = 1; i <= n; ++i) {
		int cur = 0;
		for (int j = 0; j < k; ++j) {
			if (!j)
				cur += cnt[j][mp(mp(0, 0), get(i, j + 1, k - 1))];
			else if (j == k - 1)
				cur += cnt[j][mp(get(i, 0, j - 1), mp(0, 0))];
			else
				cur += cnt[j][mp(get(i, 0, j - 1), get(i, j + 1, k - 1))];
		}

		cur -= cnt[k][mp(mp(0, 0), h[i][k - 1])] * (k - 1);
		if (cur > mx || (cur == mx && s[j] > s[i])) 
			j = i;

		if (cur > mx) {
			mx = cur;
			cnt1 = 1;
		} else if(cur == mx)
			++cnt1;
	}
	cout << s[j] << endl;
	cout << cnt1 << endl;
}