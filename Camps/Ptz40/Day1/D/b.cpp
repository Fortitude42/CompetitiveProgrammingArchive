#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
const int inf = 1e9, maxn = 1e6 + 48, mod = 1e9 + 7, N = 1e5;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, timer, tt, qq, T;
bool ok;

int ask (int i, int j, int w) {	
	if (i == j)
		return 0;
	++timer;
	if (timer == tt + 1)
		assert(0);

	assert(i >= 0 && i < n && j >= 0 && j < n && w > 0 && w <= N);
	cout << "? " << i << " " << j << " " << w << endl;
	cout << flush;
	string s;
	cin >> s;
	if (s == "EQUAL")
		return 0;

	if (s == "FIRST")
		return -1;
	assert(s == "SECOND");
	return 1;
}


int t[maxn];

void update (int id, int v = 1, int tl = 1, int tr = N) {
	assert(v < maxn);
	if (id == -1)
		return;
	if (t[v] == -1 || tl == tr) {
		if (t[v] == -1 || ask(id, t[v], tl) < 0) 
			t[v] = id;
		return;
	}

	int tm = (tl + tr) >> 1;
	int xa = ask(id, t[v], tl);
	int xb = ask(id, t[v], tm + 1);
	
	
	if ((xa <= 0 && xb > 0) || (xa >= 0 && xb < 0)) {
	    if (xb < 0)
	    	swap(id, t[v]);
		update(id, v << 1, tl, tm);
	} else {
	    if (xa < 0)
	    	swap(id, t[v]);
		update(id, v << 1 | 1, tm + 1, tr);
	}
}

int get (int pos, int v = 1, int tl = 1, int tr = N) {
	assert(v < maxn);
	if (t[v] == -1 || tl == tr)
		return t[v];

	int tm = (tl + tr) >> 1, x;

	if (pos <= tm)
		x = get(pos, v << 1, tl, tm);
	else
		x = get(pos, v << 1 | 1, tm + 1, tr);

	if (x != -1 && ask(x, t[v], pos) < 0)
		return x;			

	return t[v];
}

string s;
int x;

 
main () {
	memset(t, -1, sizeof(t));
	cin >> n;
//	assert(n > 0 && n <= 500);
	tt = 20000;
	timer = 0;
	for (int i = 0; i < n; ++i)
		update(i);

	ok = 1;
	cout << '!' << endl << endl;
	cout << flush;
	while (1) {
		++qq;
		s = "";
		cin >> s;
		if (s == "FINISH")
			break;
		if (s != "QUESTION") 
			assert(0);
		
		cin >> x;                      	
		tt = 20;
		timer = 0;
		assert(x > 0 && x <= N);
		int res = get(x);
		assert(res >= 0 && res < n);
		cout << "! " << res << endl;
		cout << flush;
	}
}   	