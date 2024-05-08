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

int n, m, p[30][M], s[30][M]; 

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		a = a * 1ll * a % MOD;
		n >>= 1;
	}

	return res;
}


struct SinglePolynom {
	int coeff;
	vi degrees;
	SinglePolynom() {
		coeff = 1;
		degrees.resize(27, 0);
	}

	SinglePolynom(int x) {
		coeff = x;
		degrees.resize(27, 0);
	}

	SinglePolynom(char c, int x) {
		coeff = x;
		degrees.resize(27, 0);
		degrees[c - 'a']++;
	}

	SinglePolynom operator *(const SinglePolynom &sp) const {
		SinglePolynom res = SinglePolynom(coeff * 1ll * sp.coeff % MOD);
		for (int i = 0; i < 27; ++i)
			res.degrees[i] = (sp.degrees[i] + degrees[i]) % MOD;
		return res;
	}

	void write() {
		cout << "(" << coeff << ")";
		for (char c = 'a'; c <= 'z' + 1; ++c)
			if (degrees[c - 'a'] > 0)
				cout << "(" << c << "^" << degrees[c - 'a'] << ")";
	}
};

struct Polynom {
	vector < SinglePolynom > sps;

	Polynom() {
		sps.pb(SinglePolynom());
	}

	void normalize() {
		map < vi, int > dmap;
		for (auto sp : sps) {
			if (!dmap.count(sp.degrees))
				dmap[sp.degrees] = 0;

			dmap[sp.degrees] = (dmap[sp.degrees] + sp.coeff) % MOD;
		}

		vector < SinglePolynom > nsps;
		for (auto d : dmap) {
			SinglePolynom sp;
			sp.coeff = d.s;
			sp.degrees = d.f;
			if (sp.coeff > 0)
				nsps.pb(sp);
		}

		if (!sz(nsps))
			nsps.pb(SinglePolynom(0));
		sps = nsps;
	}

	Polynom operator *(const Polynom &p) const {
		Polynom res;
		res.sps.clear();

		for (auto sp1 : sps)
			for (auto sp2 : p.sps)
				res.sps.pb(sp1 * sp2);
		res.normalize();
		return res;
	}


	void write() {
		for (int i = 0; i < sz(sps); ++i) {
			sps[i].write();
			if (i + 1 < sz(sps))
				cout << " + ";
		}

		cout << endl;
	}
};

vector < string > v;


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i){
		p[0][i] = 1; 
		s[0][i] = i;
	}

	for (int j = 1; j <= n; ++j) 
		for (int i = 1; i <= m; ++i) {
			p[j][i] = p[j - 1][i] * 1ll * i % MOD;
			s[j][i] = s[j][i - 1] + p[j][i];
			if (s[j][i] >= MOD)
				s[j][i] -= MOD;
		}
	

	for (int i = 1; i <= n; ++i) {
		char cur, from, to;
		cin >> cur >> from >> to;
		if (to == 'M')
			to = 'z' + 1;
		string t;
		t += cur;
		t += from;
		t += to;
		v.pb(t);
	}

	Polynom p;
	for (int i = n - 1; i > 0; --i) {
		string t = v[i];
		char from = t[1], to = t[2];
		if (from == '1') {
			Polynom cur;
			cur.sps.clear();
			cur.sps.pb(SinglePolynom(to, 1));
			p = p * cur;
			continue;
		}

		Polynom cur;
		cur.sps.clear();
		cur.sps.pb(SinglePolynom(to, 1));
		cur.sps.pb(SinglePolynom(from, MOD - 1));
		cur.sps.pb(SinglePolynom());
		p = p * cur;
	}

//	p.write();
	int ans = 0;
	for (auto sp : p.sps) {
		int cur = binpow(m, sp.degrees[26]) * 1ll * sp.coeff % MOD;		

		int cnt = 0;
		for (int i = 0; i < 26; ++i)
			if (sp.degrees[i] > 0) {
				++cnt;
				cur = cur * 1ll * s[sp.degrees[i]][m] % MOD;
//				cerr << "----> " << sp.degrees[i] << ' ' << s[sp.degrees[i]][m] % MOD << endl;
			}

		assert(cnt <= 1);
		if (!cnt) {
			cur = cur * 1ll * m % MOD;
		}

		ans = (ans + cur) % MOD;
//		cerr << cur << endl;
	}

	cout << ans << endl;

}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}