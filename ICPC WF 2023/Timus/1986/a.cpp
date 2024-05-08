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

bool isletter(char c) {
	return c >= 'a' &&  c <= 'z';
}

map < string, int > id;
vector < string > names;
vector < pii > r[M];
vector < pair < int, double > > res[M];

void calc(int i) {
	if (sz(res[i]))
		return;

	map < int, double > m;
	for (auto x : r[i]) {
		int to = x.f, w = x.s;
		if (!sz(r[to])) {
			m[to] += w/100.0;
			continue;
		}

		calc(to);
		for (auto y : res[to]) 
			m[y.f] += y.s*w/100.0;
	}

	for (auto x : m)
		res[i].pb(x);
}

void solve() {
	string s;
	while (getline(cin, s)) {
		int i = 0;
		string v;
		while (i < sz(s) && isletter(s[i]))
			v += s[i++];

		if (!id.count(v)) {
			id[v] = sz(names);
			names.pb(v);
		}

		while (i < sz(s)) {
			while (i < sz(s) && !isletter(s[i]))
				++i;

			if (i == sz(s))
				break;

			string to;
			while (i < sz(s) && isletter(s[i]))
				to += s[i++];

			int w = 0;
			while (!isdigit(s[i]))
				++i;
			while (isdigit(s[i])) {
				w = w*10 + s[i] - '0';
				++i;
			}

			if (!id.count(to)) {
				id[to] = sz(names);
				names.pb(to);
			}

			r[id[v]].pb(mp(id[to], w));
//			cerr << id[v] << ' '<< id[to] << endl;
		}
		
	}

	cout << fixed << setprecision(5);
	for (int i = 0; i < sz(names); ++i)
		if (sz(r[i])) {
			calc(i);
			cout << names[i] << " : " << ' ';
			vector < pair < string, double > > curres;
			for (auto j : res[i])
				curres.pb(mp(names[j.f], j.s));
			sort(all(curres));
			for (auto x : curres)
				cout << x.f << ' ' << x.s << ' ';
			cout << endl;					
		}
}

main () {
	fastio
  	int TT;
  	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}