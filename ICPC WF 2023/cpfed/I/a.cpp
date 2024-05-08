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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;



struct Point{
	int x, y;

	ll cross(const Point &p) {
		return x*1ll*p.y - y*1ll*p.x;
	}
};

ll area2(vector < Point > v) {
	ll res = v.back().cross(v[0]);
	for (int i = 0; i + 1 < sz(v); ++i)
		res += v[i].cross(v[i + 1]);
	return abs(res);
}

int n;
bool used[M];
Point a[M];

int choose() {
	vi cur;
	for (int i = 1; i <= n; ++i)
		if (!used[i])
			cur.pb(i);

	assert(sz(cur) >= 3);

	int j = 0;
	ll mn = area2({a[cur[0]], a[cur[1]], a[cur[2]]});
	for (int i = 1; i < sz(cur); ++i) {
		ll area = area2({a[cur[i]], a[cur[(i + 1) % sz(cur)]], a[cur[(i + 2) % sz(cur)]]});
		if (area < mn) {
			j = i;
			mn = area;
		}
	}

	return cur[(j + 1) % sz(cur)];
}


 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i].x >> a[i].y;
	
	bool turn = 1;
	if (n & 1) {
		cout << "Beatrice\n";
		turn = 0;
	} else
		cout << "Alberto\n";

	for (int i = 0; i < n - 2; ++i) {
		int x;
		if (!turn)
			cin >> x;
		else {
			x = choose(); 
			cout << x << endl;		
		}
		used[x] = 1;
		turn ^= 1;
	}
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}