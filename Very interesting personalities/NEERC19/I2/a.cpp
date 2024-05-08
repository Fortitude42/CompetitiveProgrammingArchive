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
const int N = 2e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int K = 1e4;

int n, timer;
vi g[M];
int sz[M];

bool ask(int i, int j) {
	assert(++timer <= 4 * n * n);
	cout << "? " << i << ' ' << j << "\n";
	fflush(stdout);
	char res;
	cin >> res;
	return res == '<';
}

bool check(const vector<vi> &num, int n) {
	int cur = 0;
	for (int i = 0; i < sz(num); i++) {
		cur += sz(num[i]);
		if (cur == n)
			return false;
		else if (cur > n)
			return true;
	}
	return true;
}

int get(vi &vec) {
	int pos = rand() % sz(vec);
	int x = vec[pos];
	vec.erase(vec.begin() + pos);
	return x;
}
 
void solve() {
	timer = 0;
	cin >> n;
    
    vi roots[2];
    for (int i = 1; i <= n + n; i++) {
    	sz[i] = 1;
    	roots[0].pb(i);
    	g[i].clear();
    }

	for (int i = 1; i <= n; i++) {
//		cerr << "i: " << i << "\n";
		while (sz(roots[1]) > 1 || !roots[0].empty()) {
//			cerr << "sz: " << sz(roots[0]) << ' ' << sz(roots[1]) << "\n";
			vi nxt[2];
			for (int j = 0; j < 2; j++) {
				while (sz(roots[j]) >= 2) {
					int x = get(roots[j]);
					int y = get(roots[j]);
					bool xisless = ask(x, y);
					if (xisless) {
						sz[x] += sz[y];
						g[x].pb(y);                    
						nxt[1].pb(x);
					} else {
						sz[y] += sz[x];
						g[y].pb(x);
						nxt[1].pb(y);
					}
				}
			}
			if (sz(roots[0]) && sz(roots[1])) {
				int x = get(roots[0]);
				int y = get(roots[1]);
				bool xisless = ask(x, y);
				if (xisless) {
					sz[x] += sz[y];
					g[x].pb(y);
					nxt[1].pb(x);
				} else {
					sz[y] += sz[x];
					g[y].pb(x);
					nxt[1].pb(y);
				}
			} else if (sz(roots[0])) {
				nxt[0].pb(get(roots[0]));
			} else if (sz(roots[1])) {
				nxt[1].pb(get(roots[1]));
			}

			swap(roots[0], nxt[0]);
			swap(roots[1], nxt[1]);
		}

		int v = get(roots[1]);
		for (int to : g[v])
			roots[sz[to] > 1].pb(to);
	}	

	cout << "!\n";
	fflush(stdout);
}

main () {
	srand(time(0));
	int TT;
	TT = 1;
	cin >> TT;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

