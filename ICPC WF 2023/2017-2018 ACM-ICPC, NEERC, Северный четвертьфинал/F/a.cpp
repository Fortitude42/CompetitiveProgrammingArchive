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

 
int m;
vector < string > v;

struct Fraction {
	int p, q;
	Fraction(): p(0), q(1) {}
	Fraction(int p, int q): p(p), q(q) {}

	void normalize() {
		int g = __gcd(p, q);
		p /= g;
		q /= g;
	}

	Fraction operator + (const Fraction &f) const {
		Fraction res = Fraction(p*f.q + q*f.p, q*f.q);
		res.normalize();
		return res;
	}

	Fraction operator / (const int &x) const {
		Fraction res = Fraction(p, q*x);
		res.normalize();
		return res;
	}
};

struct SinglePolynom {
	Fraction coeff;
	vi degrees;
	SinglePolynom() {
		coeff = Fraction(1, 1);
		degrees.resize(26, 0);
	}

	SinglePolynom(int x) {
		coeff = Fraction(x, 1);
		degrees.resize(26, 0);
	}

	void integral(char c) {
		degrees[c - 'a']++;
		coeff = coeff / degrees[c - 'a'];
	}

	void replace(char a, char b) {
		degrees[b - 'a'] += degrees[a - 'a'];
		degrees[a - 'a'] = 0;
	}

	void write() {
		cout << "(" << coeff.p << '/' << coeff.q << ")";
		for (char c = 'a'; c <= 'z'; ++c)
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
		map < vi, Fraction > dmap;
		for (auto sp : sps) {
			if (!dmap.count(sp.degrees))
				dmap[sp.degrees] = Fraction();

			dmap[sp.degrees] = dmap[sp.degrees] + sp.coeff;
		}

		vector < SinglePolynom > nsps;
		for (auto d : dmap) {
			SinglePolynom sp;
			sp.coeff = d.s;
			sp.degrees = d.f;
			if (sp.coeff.p > 0)
				nsps.pb(sp);
		}

		if (!sz(nsps))
			nsps.pb(SinglePolynom(0));
		sps = nsps;
	}

	void integral(char c, char l, char r) {
		vector < SinglePolynom > nsps;
		for (auto sp : sps) {
			sp.integral(c);
			sp.replace(c, r);
			nsps.pb(sp);	
		}

		for (auto sp : sps)
			if (l != '1') {
				sp.integral(c);
				sp.replace(c, l);
				sp.coeff.p *= -1;
				nsps.pb(sp);
			}		
		
		sps = nsps;


		normalize();
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


void solve() {
//	file("fygon20");
	cin >> m;
	string s;
	getline(cin, s);
	for (int i = 0; i < m - 1; ++i) {
		getline(cin, s);
		char cur = s[i*4 + 4];
		char from = s[i*4 + 15];
		char to = s[i*4 + 18];
		string t;
		t += cur;
		t += from;
		t += to;
		v.pb(t);
//		cerr << s << endl;
	}

	Polynom p;
	for (int i = m - 2; i >= 0; --i) {
		string t = v[i];

		p.integral(t[0], t[1], t[2]);
//		p.write();
	}
	cout << p.sps[0].degrees['n' - 'a'] << ' ' << p.sps[0].coeff.p << '/' << p.sps[0].coeff.q;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}