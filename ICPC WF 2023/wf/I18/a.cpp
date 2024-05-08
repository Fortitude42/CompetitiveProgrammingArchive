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
 

const int N = 3005;
const int M = 6005;

ll ans;
int r, c, L[2][M], R[2][M], len[M], t[N+M][N];
vector < pii > del[N];
string a[N*2];


void inc(int lvl, int pos, int x) {
	while (pos < N) {
		t[lvl][pos] += x;
		pos |= (pos + 1);
	}
}


int get(int lvl, int r) {
	int res = 0;
	while (r >= 0) {
		res += t[lvl][r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}


void calc() {
	memset(L, 0, sizeof L);
	memset(R, 0, sizeof R);
	memset(len, 0, sizeof len);
	memset(t, 0, sizeof t);
	set < pair < int, pii > > q;

	for (int i = (2*r - 1); i > 0; --i) {
		if (!(i & 1))
			continue;

		int i1 = (i + 1) / 2;

		while (sz(del[i1 + 1]) > 0) {
			pii cur = del[i1 + 1].back();
			del[i1 + 1].ppb();
			int i2 = cur.f, j2 = cur.s;
			inc(i2+j2, i2, -1);
		}

		for (int j = 2*c - 1; j > 0; --j) {
			if (a[i][j] != 'x')
				continue;
			int j1 = (j + 1) / 2;
			len[j1] = a[i][j + 1] == '-' ? (len[j1 + 2] + 1) : 0;
			L[i1 & 1][j1] = a[i + 1][j - 1] == '/' ? (L[(i1 + 1) & 1][j1 - 1] + 1) : 0;
			R[i1 & 1][j1] = a[i + 1][j + 1] == '\\' ? (R[(i1 + 1) & 1][j1 + 1] + 1) : 0;

			int x = min(L[i1 & 1][j1], R[i1 & 1][j1]);
			if (x > 0) {
				assert(i1 + x <= r);
				ans += get(i1 + j1, i1 + x);
			}

			if (len[j1] > 0) {
				inc(i1 + j1, i1, 1);       				
				if (i1 - len[j1] > 1)
					del[i1 - len[j1]].pb(mp(i1, j1));
			}
		}
	}

}
 
void solve() {
	fastio
	cin >> r >> c;
	for (int i = 0; i <= 2*r-1; ++i) {
		getline(cin, a[i]);
		a[i] = "#" + a[i];
		while (sz(a[i]) <= 2*c)
			a[i] += "#";
	}


	for (int j = 1; j <= 2*c+1; ++j)
		a[2*r] += "#";


	calc();
	for (int i = 1; i < 2*r - i; ++i) {
		swap(a[i], a[2*r - i]);
	}

	for (int i = 1; i <= 2*r - 1; ++i)
		for (int j = 1; j <= 2*c - 1; ++j)
			if (a[i][j] == '/')
				a[i][j] = '\\';
			else if (a[i][j] == '\\')
				a[i][j] = '/';
	calc();

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