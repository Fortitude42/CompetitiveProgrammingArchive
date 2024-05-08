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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;



const int M = (1 << 24);

int d[M], p[M];
ll c[M];
queue < ll > q;
int a[30];

unordered_map<int, int> mt;
int k;
 
ll get (int x) {
	ll mask = 0;
	for (int i = 0; i < 24; ++i)
		if (a[i] == x)
			mask |= (1ll << i);

	return mt[mask];
}

vi P = {6, 7, 8, 11, 12, 15, 16, 17};
vi D[4];
string S = "AHGB", T = "FCDE";

ll f(ll x, char c){
	return x * 8 + (c - 'A');
}

main () {
	D[0] = {0, 2, 6, 11, 15, 20, 22};
	D[1] = {4, 5, 6, 7, 8, 9, 10};
	D[2] = {13, 14, 15, 16, 17, 18, 19};
	D[3] = {1, 3, 8, 12, 17, 21, 23};

	ll V = 0;
	for (auto x : P)
		V |= (1ll << x);
	
	mt[V] = k++;
	d[k - 1] = 0;
	q.push(V);
	int timer = 0;
	while (sz(q)) {
		V = q.front();
		int VV = mt[V];
		++timer;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			ll U = V;
			for (auto x : D[i])
				if (V & (1ll << x))
					U ^= (1ll << x);

			for (int j = 0; j < sz(D[i]); ++j)
				if (V & (1ll << D[i][j]))
					U |= (1ll << D[i][(j + 1) % sz(D[i])]);

			if (!mt.count(U)) {
				mt[U] = k++;
				d[k - 1] = d[VV] + 1;
				c[k - 1] = c[VV] + (S[i] - 'A') * (1 << (3 * d[VV]));
				q.push(U);
			}else{
				int UU = mt[U];
				if(d[UU] == d[VV] + 1)
					c[UU] = min(c[UU], c[VV] + (S[i] - 'A') * (1 << (3 * d[VV])));				
			}
		}

		for (int i = 0; i < 4; ++i) {
			ll U = V;
			for (auto x : D[i])
				if (V & (1ll << x))
					U ^= (1ll << x);
			
			for (int j = 0; j < sz(D[i]); ++j) 
				if (V & (1ll << D[i][j]))
					U |= (1ll << D[i][(j + sz(D[i]) - 1) % sz(D[i])]);

			if (!mt.count(U)) {
				mt[U] = k++;
				d[k - 1] = d[VV] + 1;
				c[k - 1] = c[VV] + (T[i] - 'A') * (1 << (3 * d[VV]));
				q.push(U);
			}else{
				int UU = mt[U];
				if(d[UU] == d[VV] + 1)
					c[UU] = min(c[UU], c[VV] + (T[i] - 'A') * (1 << (3 * d[VV])));				
			}
	
		}
	}

	

	while (1) {
		scanf("%d", &a[0]);
		if (!a[0])
			break;

		for (int i = 1; i < 24; ++i)
			scanf("%d", &a[i]);

		int x = 1;
		for (int i = 1; i <= 3; ++i)
			if (d[get(i)] < d[get(x)] || (d[get(i)] == d[get(x)] && c[get(i)] < c[get(x)]))
				x = i;

		ll mask = get(x);

		string ans = "";
		ll y = c[mask];
		for(int i = 0; i < d[mask]; i++){
			ans += (char)('A' + y % 8);
			y /= 8;		
		}

		reverse(all(ans));
		if (!sz(ans))
			ans = "No moves needed";

		cout << ans << endl;
		cout << x << endl;
	}
}