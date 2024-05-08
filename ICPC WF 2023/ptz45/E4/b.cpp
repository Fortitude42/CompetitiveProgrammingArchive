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

bool used[10];
int p[10], cnt[10];
vector < vi > v;
bool was[1003];
int d[1003][1003];
string tst;

void rec(int i = 0) {
	if (!i) {
		for (int x = 0; x < 8; x += 2)
			for (int y = 1; y < 8; y += 2) {
				used[x] = 1;
				used[y] = 1;
				p[0] = x;
				p[1] = y;
				rec(i + 2);
				used[x] = 0;
				used[y] = 0;
			}

		return;
	}

	vi pos;
	for (int i = 0; i < 8; ++i)
		if (!used[i])
			pos.pb(i);

	if (i == 2) {
		for (int p1 = 0; p1 < sz(pos); ++p1)
			for (int p2 = p1 + 1; p2 < sz(pos); ++p2)
				for (int p3 = p2 + 1; p3 < sz(pos); ++p3) {
					used[pos[p1]] = 1;
					used[pos[p2]] = 1;
					used[pos[p3]] = 1;
					p[2] = pos[p1];
					p[3] = pos[p2];
					p[4] = pos[p3];
					rec(i + 3);
					used[pos[p1]] = 0;
					used[pos[p2]] = 0;
					used[pos[p3]] = 0;
				}					
		return;
	}

	if (i == 5) {
		for (auto x : pos) {
			used[x] = 1;
			p[5] = x;
			rec(i + 1);
			used[x] = 0;
		}

		return;
	}

	p[6] = pos[0];
	p[7] = pos[1];

	vi pp;
	for (int i = 0; i < 8; ++i)
		pp.pb(p[i]);
	v.pb(pp);
}


string get(const vi &p) {
	string q = "########";
	q[p[0]] = q[p[1]] = 'B';
	q[p[2]] = q[p[4]] = 'R';
	q[p[3]] = 'K';
	q[p[5]] = 'Q';
	q[p[6]] = q[p[7]] = 'N';
	return q;
}


int dist(const string &aa, const string &bb) {
    int d = 0;
	for (int i = 0; i < 8; ++i)
		d += (aa[i] == bb[i]);
	return d;
}
int dist(const vi &a, const vi &b) {
	string aa = get(a), bb = get(b);
	return dist(aa, bb);
}


int ask(const vi &p) {
	string q = get(p);
	cout << q << endl;
	if (sz(tst)) {
		int x = dist(tst, q);
		cout << x << endl;
		return x;
	}
	int x;
	cin >> x;
	return x;
}

string s;
 
void solve() {
//	tst = "QRKNRBBN";
//	cout << "!! " << tst << endl;
	if (!sz(tst)) {
		cin >> s;
		if (s == "END")
			exit(0);
		cin >> s;
	}
		
	memset(was, 0, sizeof was);

	int timer = 0;
	while (1) {
		vi ind;              
		for (int i = 0; i < sz(v); ++i)
			if (!was[i])
				ind.pb(i);		

		if (sz(ind) == 1) {
			assert(++timer <= 6);	
			ask(v[ind[0]]);
			return;
		}

		assert(sz(ind) > 0);

		int mn = inf, j = -1;
		for (int x = 0; x < 960; ++x) {
			memset(cnt, 0, sizeof cnt);
			int mx = 0;

			for (auto y : ind)
				mx = max(mx, ++cnt[d[x][y]]);
			if (mx < mn) {
				mn = mx;
				j = x;
			}
		}

//		cerr << j << ' ' << mn << endl;
			

		assert(++timer <= 6);
		int dist = ask(v[j]);

		if (dist == 8) {
		    assert(timer <= 6);
			return;
		}

		for (auto y : ind)
			if (d[j][y] != dist){ 
				was[y] = 1;
			}
	}
}

main () {
	rec();
	for (int i = 0; i < sz(v); ++i)
		for (int j = 0; j < sz(v); ++j)
			d[i][j] = dist(v[i], v[j]);
  int TT;
  TT = 1000;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}