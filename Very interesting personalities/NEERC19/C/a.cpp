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
const int N = 2e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, d[M], s[M], m;
vector < pii > ans; 
vector < pii > vertices;

bool cmp(pii x, pii y) {
	return s[x.f] < s[y.f];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		m += d[i];
	}

	if (m & 1){
		cout << -1;
		return;
	}

	m /= 2;
	if (m < n - 1) {
		cout << -1;
		return;
	}

	if (m == n - 1) {
		set < pii > q;
		for (int i = 1; i <= n; ++i)
			q.insert(mp(d[i], i));

		while (sz(q)) {
			int v = q.begin()->s;
			q.erase(q.begin());

			int u = (*q.rbegin()).s;
			q.erase(mp(d[u], u));

			if (d[u] == 1 && sz(q) > 1) {
				cout << -1;
				return;
			}

			d[v]--;
			d[u]--;

			ans.pb({v, u});

			if (d[u])
				q.insert(mp(d[u], u));			
		}

		cout << sz(ans) << endl;
		for (auto x:  ans) 
			cout << 2 << ' ' << x.f << ' ' << x.s << endl;

		return;
	}

	vi odd, leaves, even;
	for (int i = 1; i <= n; ++i)
		if (d[i] == 1)
			leaves.pb(i);
		else if (d[i] & 1)
			odd.pb(i);
		else
			even.pb(i);

	while (sz(leaves)) {
		int v = leaves.back();
		leaves.ppb();

		if (sz(odd)) {
			int u = odd.back();
			odd.ppb();
			even.pb(u);

			ans.pb({v, u});
			d[u]--;
			continue;
		}
		
		for (int i = 0; i < sz(even); ++i)
			if (d[even[i]] >= 4) {
				swap(even[i], even.back());
				break;
			}

		if (!sz(even) || d[even.back()] < 4) {
			cout << -1;
			return;
		}

		int u = even.back();
		ans.pb({v, u});
		ans.pb({u, leaves.back()});

		leaves.ppb();
		d[u] -= 2;
		s[u] = d[u];
	}

	while (sz(odd)) {
		int v = odd.back();
		odd.ppb();

		if (sz(odd)) {
			int u = odd.back();
			odd.ppb();
			ans.pb({v, u});
			d[v]--;
			d[u]--;
			s[v] = d[v] + d[u];
			vertices.pb({v, u});
			continue;
		}

		for (int i = 0; i < sz(even); ++i) 
			if (d[even[i]] >= 4) {
				swap(even[i], even.back());
				break;
			}		

		if (!sz(even) || d[even.back()] < 4) {
			cout << -1;
			return;
		}

		int u = even.back();
		even.ppb();

		ans.pb({v, u});
		vertices.pb({v, u});
		d[v]--;
		d[u]--;
		s[v] = d[v] + d[u];
	}
	            
	while (sz(even) > 0){
		vertices.pb({even.back(), -1});
		s[even.back()] = d[even.back()];
		even.ppb();
	}
		
	while (1) {
		sort(all(vertices), cmp);
		reverse(all(vertices));
		while (sz(vertices) && !s[vertices.back().f])
			vertices.ppb();
		reverse(all(vertices));

		if (!sz(vertices))
			break;

		if (sz(vertices) <= 2 || s[vertices[0].f] > 2 || s[vertices[1].f] > 2){
			cout << -1;
			return;
		}
		
		if (s[vertices.back().f] == 2) {
			for (int i = 0; i < sz(vertices); ++i) {
				int j = (i + 1) % sz(vertices);
				int v = !d[vertices[i].f] ? vertices[i].s : vertices[i].f;
				int u = !d[vertices[j].f] ? vertices[j].s : vertices[j].f;
				ans.pb({v, u});
			}

			break;
		}
		
		int v = !d[vertices[0].f] ? vertices[0].s : vertices[0].f;
		int u = !d[vertices[1].f] ? vertices[1].s : vertices[1].f;
		int w = !d[vertices.back().f] ? vertices.back().s : vertices.back().f;
		
		ans.pb({v, u});
		ans.pb({v, w});
		ans.pb({u, w});

		d[v] -= 2;
		d[u] -= 2;
		d[w] -= 2;

		s[vertices[0].f] -= 2;
		s[vertices[1].f] -= 2;
		s[vertices.back().f] -= 2;
	}

	cout << sz(ans) << endl;
	for (auto x : ans) 
		cout << 2 << ' ' << x.f << ' ' << x.s << endl;	
}   	

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
