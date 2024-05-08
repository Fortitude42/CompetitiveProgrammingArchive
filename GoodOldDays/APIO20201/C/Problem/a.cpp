#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1012;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
char c, a[N][N];
deque < pii > q;
bool was[N][N];
int n, P, x, b[N][N];
pii p[N][N][2];

void f (char c, int i, int x, int y) {
	if (c == '-')
		return;

	if (c == '0') {
		if (!y || y == 3) {
			for (int j = 1; j <= n; ++j)
				b[i][j] = 1;
		} else {
			for (int j = 1; j <= n; ++j)
				b[j][i] = 1;
		}
		return;			
	}

	if (y == 2 || y == 3)
		x = n + 1 - x;
	
	if (!y) {
		for (int j = 1; j < x; ++j)
			b[i][j] = 1;
		a[i][x] = c;
		return;
	}

	if (y == 1) {
		for (int j = 1; j < x; ++j)
			b[j][i] = 1;
		a[x][i] = c;
		return;
	}

	if (y == 2) {
		for (int j = n; j > x; --j)
			b[j][i] = 1;
		a[x][i] = c;
		return;
	}

	for (int j = n; j > x; --j)
		b[i][j]= 1;
	a[i][x] = c;	
}


bool in (int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

void F () {
	x = 0;
	while ('0' <= c && c <= '9') {
		x *= 10;
		x += c - '0';
		cin >> c;
	}
}


main () {
	file("pajel_10");	
	cin >> n >> P;

	for (int i = 1; i <= n; ++i)
	    for (int j = 1; +j <= n; ++j)
			a[i][j] = '-';


	for (int i = 1; i <= n; ++i) {
		cin >> c;
		if (c == '0' || c == '-') {
			f(c, i, x, 0); 
			continue;
		}

		
		F();
		f(c, i, x, 0);
	}

	for (int i = 1; i <= n; ++i) {
		cin >> c;
		if (c == '0' || c == '-') 
			f(c, i, x, 1);
		else {
			F();
			f(c, i, x, 1);
		}

		cin >> c;
		if (c == '0' || c == '-')
			f(c, i, x, 2);
		else {
			F();
			f(c, i, x, 2);
		}
	}

	for (int i = 1; i <= n; ++i) {
		cin >> c;
		if (c == '0' || c == '-') {
			f(c, i, x, 3); 
			continue;
		}

		
		F();
		f(c, i, x, 3);
	}

	char c = 'M', cc = 'B';
	vpii V;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j] == c || a[i][j] == cc) 
				V.pb({i, j});

	srand(time(0));
	random_shuffle(all(V));
	vi D;
	for (int i = 0; i < 4; ++i)
		D.pb(i);

	for (auto x : V) {
		int z = (a[x.f][x.s] == c);

		if (!p[x.f][x.s][z].f) {
			q.pb(x);
			was[x.f][x.s] = 1;
			while (sz(q)) {
				int A = q.front().f, B = q.front().s;
				q.pop_front();
				random_shuffle(all(D));
				for (int i = 0; i < 4; ++i) {
					int tox = A + dx[D[i]], toy = B + dy[D[i]];
					if (in(tox, toy) && !b[tox][toy] && (a[tox][toy] == '-' || a[tox][toy] == a[x.f][x.s]) && !p[tox][toy][z].f) {
						q.pb(mp(tox, toy));
						p[tox][toy][z] = mp(A, B);
					}
				}
			}
		} else {
			char c = a[x.f][x.s];
			while (!was[x.f][x.s]) {
				was[x.f][x.s] = 1;
				a[x.f][x.s] = c;
				int xx = p[x.f][x.s][z].f, yy = p[x.f][x.s][z].s;
				x.f = xx, x.s = yy;
			}
		}
	}

	for (int i = 1; i <= n; ++i, cout << endl)
		for (int j = 1; j <= n; ++j)
			cout << a[j][i];

}