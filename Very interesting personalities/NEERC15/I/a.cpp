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
const int N = 1e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vector < vi > v;
int n, p[M], res[M][M]; 

inline int ask(int i, int j) {
	i /= 2;
	j = (j + 1) / 2;
	if (res[i][j] != -1)
		return res[i][j];

	cout << "? " << i << ' ' << j << endl;
	char c;
	cin >> c;
	return res[i][j] = (c == '<');
}

void solve() {
	cin >> n;
	vi cur;
	for (int i = 1; i <= n; i += 2)
		cur.pb(i);

	v.pb(cur);

	vi even;
	for (int i = 2; i <= n; i += 2)
		even.pb(i);
	random_shuffle(all(even));

	for (auto i : even) {
		int l = 0, r = sz(v) - 1, j = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (!ask(i, v[mid].back())) {
				j = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}

		if (j == -1)
			j = 0;
		
		vi a, b;
		for (auto x : v[j])
			if (!ask(i, x))
				a.pb(x);
			else
				b.pb(x);

		if (j + 1 < sz(v) && !sz(b)) {
			a.clear();
			j++;
			for (auto x : v[j])
				if (!ask(i, x))
					a.pb(x);
				else
					b.pb(x);
		}

		if (!sz(b)) {
			p[i] = n;
			continue;
		}
			
		vector < vi > vv;

		for (int x = 0; x < j; ++x)
			vv.pb(v[x]);
		
		vv.pb(a);
		vv.pb(b);

		for (int x = j + 1; x < sz(v); ++x)
			vv.pb(v[x]);


		for (int x = 0; x <= j; ++x)
			p[i] += sz(vv[x]);
		p[i] += p[i];
		
		swap(v, vv);
	}

	for (int i = 0; i < sz(v); ++i) {
		assert(sz(v[i]) == 1);
		p[v[i][0]] = i*2 + 1;
	}

	cout << "! ";
	for (int i = 2; i <= n; i += 2)
		cout << p[i] << ' ';
	for (int i = 1; i <= n; i += 2)
		cout << p[i] << ' ';


}

main () {
	memset(res, -1, sizeof(res));
	fastio
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

