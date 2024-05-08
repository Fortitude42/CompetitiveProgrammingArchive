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
const int N = 520, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int na, ma;
bool a[M*3][M*3], tmpa[M*3][M*3];
pii p[M*3][M*3], tmpp[M*3][M*3];

int nb, mb;
vector < pii > pos;


void rotate() {
	for (int i = 0; i <= 3*N; ++i)
		for (int j = 0; j <= 3*N; ++j) {
			tmpa[i][j] = a[j][3*N - i];
			tmpp[i][j] = p[j][3*N - i];
		}

	for (int i = 0; i <= 3*N; ++i)
		for (int j = 0; j <= 3*N; ++j) {
			a[i][j] = tmpa[i][j];
			p[i][j] = tmpp[i][j];
		}
}

void check(int xf, int yf) {
	vector < pii > e1, e2;
	memset(tmpa, 0, sizeof tmpa);

	for (int i = 0; i < sz(pos); ++i) {
		int x = xf + pos[i].f, y = yf + pos[i].s;
		assert(x >= 0 && y >= 0 && x <= 3*N && y <= 3*N);
		tmpa[x][y] = 1;
	}

	for (int i = 0; i <= 3*N; ++i)
		for (int j = 0; j <= 3*N; ++j) {
			if (a[i][j] && !tmpa[i][j])
				e1.pb(mp(i, j));
			if (!a[i][j] && tmpa[i][j])
				e2.pb(mp(i, j));
		}

/*	if (!sz(e1) || !sz(e2)) {
		assert(!sz(e1) && !sz(e2));
		cout << p[xf][yf].f << ' ' << p[xf][yf].s << endl;
		cout << p[xf][yf].f << ' ' << p[xf][yf].s << endl;
		exit(0);
	}
*/
	assert(sz(e1) > 0 && sz(e2) > 0);

	if (sz(e1) == 1 && sz(e2) == 1) {
		cout << p[e1[0].f][e1[0].s].f << ' ' << p[e1[0].f][e1[0].s].s << '\n';
		cout << p[e2[0].f][e2[0].s].f << ' ' << p[e2[0].f][e2[0].s].s << '\n';
		exit(0);
	}

}
 
void solve() {
	for (int i = -N; i <= N+N; ++i)
		for (int j = -N; j <= N+N; ++j)
			p[i+N][j+N] = mp(i, j);


	cin >> na >> ma;
	for (int i = 0; i < na; ++i)
		for (int j = 0; j < ma; ++j) {
			char c;
			cin >> c;
			a[j+N][i+N] = (c == 'o');
//			cerr << i + N << ' ' << j + N << endl;
		}


	cin >> nb >> mb;
	for (int i = 0; i < nb; ++i)
		for (int j = 0; j < mb; ++j) {
			char c;
			cin >> c;
			if (c == 'o')
				pos.pb(mp(j, i));
		}

	sort(all(pos));

	assert(sz(pos) > 0);
	assert(sz(pos) > 1);

	for (int i = sz(pos) - 1; i >= 0; --i) {
		pos[i].f -= pos[0].f;
		pos[i].s -= pos[0].s;
	}

	for (int r = 0; r < 4; ++r) {
		vector < pii > cands;
		for (int i = 0; i <= 3*N && sz(cands) < 2; ++i)
			for (int j = 0; j <= 3*N && sz(cands) < 2; ++j)
				if (a[i][j])
					cands.pb(mp(i, j));
			
				

		for (int i = 0; i < 2; ++i) { 
			int xf = cands[i].f, yf = cands[i].s;
			assert(xf >= N && yf >= N);
			assert(xf <= 2*N && yf <= 2*N);
			check(xf, yf);
			check(xf - pos[1].f, yf - pos[1].s);
		}

		rotate();
	}
			
//	assert(0);
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