//template by paradox & gege & parasat
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
vi bits[M];
vector < pii > epref[M], esuff[M];
int n, a[M], b[33], p[33], aa[M], pref[M][33], suff[M][33];
pii mn[33];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);
	p[u] = v;
}


int getAns(int j, int x) {	
	int res = 0;
	for (int i = 1; i <= n; ++i)
		aa[i] = a[i]; 

	if (j > 0) {
		if (aa[j] <= (1 << x) - 1)
			return inf;		

		for (int xx = 0; xx < x; ++xx)
			if (aa[j] & (1 << xx)) {
				aa[j] -= (1 << xx);
				res += (1 << xx);
			}

		res++;
		aa[j]--;
	}

	for (int i = 0; i < 30; ++i) {
		p[i] = i; 
		if (j > 0 && pref[j - 1][i] != -1)
			b[i] = pref[j - 1][i];
		else if (suff[j + 1][i] != -1)
			b[i] = suff[j + 1][i];
		else
			b[i] = -1;
	}

	if (j > 0) {
		for (int i = j; i <= j; ++i) {
			vi bits;
			for (int j = 0; j < 30; ++j)
				if (aa[i] & (1 << j)) {
					bits.pb(j); 
					b[j] = i;
				}
		
			for (int j = 1; j < sz(bits); ++j)
				merge(bits[0], bits[j]);
		}  		

		for (auto x : epref[j - 1])
			merge(x.f, x.s); 			
	}



	for (auto x : esuff[j + 1])
		merge(x.f, x.s);

	int fst = -1;
	for (int j = 0; j < 30; ++j)
		if (b[j] != -1) {
			if (fst == -1) {
				fst = j;
				continue;
			}

			if (get(fst) != get(j)) {
				if (fst > 0) {
					++res;
					++aa[b[fst]];
					fst = 0;
				}

				++aa[b[j]];
				++res;
				merge(fst, j);
			}
		}

	return res;
}


void solve() {
	memset(b, -1, sizeof(b));

	cin >> n;

	int add = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];

		if (!a[i]) {
			++a[i];
			++add;
		}


		bits[i].clear();
		for (int j = 0; j < 30; ++j)
			if (a[i] & (1 << j))
				bits[i].pb(j);
	}
	for (int j = 0; j < 30; ++j) {
		pref[0][j] = -1; 
		suff[n + 1][j] = -1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 30; ++j)
			pref[i][j] = pref[i - 1][j];

		epref[i] = epref[i - 1];
		for (auto x : bits[i]) {
			for (auto y : bits[i])
				if (x < y)
					epref[i].pb({x, y}); 

			pref[i][x] = i;
		}

		sort(all(epref[i]));
		epref[i].resize(unique(all(epref[i])) - epref[i].begin());
	}

	esuff[n + 1].clear();
	for (int i = n; i > 0; --i) {
		for (int j = 0; j < 30; ++j)
			suff[i][j] = suff[i + 1][j];


		esuff[i] = esuff[i + 1];
		for (auto x : bits[i]) {
			for (auto y : bits[i])
				if (x < y)
					esuff[i].pb({x, y}); 
			suff[i][x] = i;
		}

		sort(all(esuff[i]));
		esuff[i].resize(unique(all(esuff[i])) - esuff[i].begin());		
	}


	pair < int, pii > ans = mp(inf, mp(inf, inf));
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j < 30; ++j)
			ans = min(ans, mp(getAns(i, j), mp(i, j)));

	getAns(ans.s.f, ans.s.s);
	cout << ans.f + add << endl;
	for (int i = 1; i <= n; ++i)
		cout << aa[i] << ' ';
	cout << endl;
}

main () {
	int TT;
	TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}