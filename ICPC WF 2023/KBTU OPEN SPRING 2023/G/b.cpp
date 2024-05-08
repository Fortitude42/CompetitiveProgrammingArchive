#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, x[M], y[M];
 
pii norm(pii a) {
	if (!a.s)
		return mp(0, 0);

	if (!a.f)
		return mp(0, 1);

	bool neg = 0;
	if (a.f < 0) {
		a.f = -a.f;
		neg ^= 1;
	}

	if (a.s < 0) {
		a.s = -a.s;
		neg ^= 1;
	}

	int g = __gcd(a.f, a.s);
	a.f /= g;
	a.s /= g;
	return mp(neg ? -a.f : a.f, a.s);
}


bool cmp(pii a, pii b) {
	// a.f / a.s < b.f / b.s
	// a.f * b.s < b.f * a.s
	return a.f * b.s < b.f * a.s;
}


vector < pii > vals;
int id[M][M];
pii k[M][M], b[M][M];
vector < pii > g[M*M];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			k[i][j] = norm(mp(x[i] - x[j], y[i] - y[j]));/*
			if (k[i][j] == mp(0, 0))
				b[i][j] = mp(x[i], 1);
			else if (k[i][j].f == 0)
				b[i][j] = mp(y[i], 1);
			else 
				b[i][j] = norm(y[i]*k[i][j].f - x[i]*k[i][j].s, k[i][j].f);*/

			vals.pb(k[i][j]);
		}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	set < vi > q;
	vi tmp;
	for (int i = 0; i < n; ++i)
		tmp.pb(1);
	q.insert(tmp);

	for (int i = 0; i < sz(vals); ++i) {
		pii k = vals[i];
		vector < pii > bs;

		for (int j = 1; j <= n; ++j) {
			pii b;			
			if (k == mp(0ll, 0ll))
				b = mp(y[j], 1);
			else if (k.f == 0)
				b = mp(x[j], 1);
			else 
				b = norm(mp(y[j]*k.f - x[j]*k.s, k.f));
			bs.pb(b);	
		}

		sort(all(bs), cmp);/*
		cout << k.f << ' ' << k.s << endl;
		for (auto x : bs)
			cout << x.f << ' ' << x.s << endl;
		cout << endl << endl;*/

		vi cur;
		for (int i = 0; i < sz(bs); ++i) {
			int cnt = 1;
			while (i + 1 < sz(bs) && bs[i + 1] == bs[i]) {
				++i;
				++cnt;
			}
			cur.pb(cnt);
		}

		q.insert(cur);
		reverse(all(cur));
		q.insert(cur);
	}

	cout << sz(q) << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}