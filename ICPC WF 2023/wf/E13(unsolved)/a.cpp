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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int b, s, r[M], nxt[M], prv[M], n, c[M];
pair < char, int > a[M];


int inside(int l, int r){ 
	if (l > r)
		return 0;

	int i = nxt[l];
	int j = prv[r];
	if (i < j && (a[i].s / s) != (a[j].s / s))
		return 1;

	return 0;
}

int outside(int l, int m, int r) {
	int i = prv[m];
	int j = nxt[m + 1];
	if (i >= l && j <= r && (a[i].s / s) != (a[j].s / s))
		return 1;

	return 0;
}

ll get(int lf, int rg) {
	if (lf > rg)
		return 0;

	if (a[lf].f == 'R') {
		int rg1 = r[lf];
		assert(rg1 <= rg);
		ll res1 = get(lf + 1, rg1 - 1)*a[lf].s + inside(lf + 1, rg1 - 1)*(a[lf].s - 1) + outside(lf, rg1, rg), res2 = get(rg1 + 1, rg);
		cout << "----> " << lf << ' ' << rg << ' ' << res1 << ' ' << res2 << endl;
		return res1 + res2;
	}

	ll res = 1 + outside(lf, lf, rg) + get(lf + 1, rg);
	cout << "-----> " << lf << ' ' << rg << ' ' << res << endl;
	return res;
}

void rec(int i = 0) {
	
}
 
void solve() {
	cin >> b >> s;
	string tmp;
	while (cin >> tmp) {
		++n;
		a[n].f = tmp[0];
		int i = 1;
		while (i < sz(tmp)) {
			a[n].s = a[n].s*10 + tmp[i] - '0';
			++i;
		}
		if (a[n].f == 'V')
			a[n].s--;
	}

	
	stack < int > st;
	for (int i = 1; i <= n; ++i) {
		if (a[i].f == 'R') {
			st.push(i);
		}
		if (a[i].f == 'E') {
			assert(sz(st) > 0);
			r[st.top()] = i;
			st.pop();
		}
		c[i] = a[i].s;
	}
	assert(!sz(st));

	for (int i = 1; i <= n; ++i) {
		prv[i] = prv[i - 1];
		if (a[i].f == 'V' && a[i].s >= s) 
			prv[i] = i;
	}

	nxt[n + 1] = n + 1;
	for (int i = n; i > 0; --i) {
		nxt[i] = nxt[i + 1];
		if (a[i].f == 'V' && a[i].s >= s) 
			nxt[i] = i;
	}


	ll ans = get(1, n);
	for(int i = 1; i <= n; ++i)
		if(nxt[i] == i) {
			++ans;
			break;
		}

	cout << ans << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);                               
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}