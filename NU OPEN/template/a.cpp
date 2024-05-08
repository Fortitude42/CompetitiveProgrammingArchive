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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, k;
bool test = 0, b[102][102];

int f() {
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		bool good = 1;
		for (int x = 1; x <= i; ++x)
			for (int y = i; y <= n; ++y)
				if (b[x][y])
					good = 0;

		res += good;
	}
	if (res == n)
		exit(0);
	return res;
}


int ask(int i, int j) {
	assert(i <= j);
	if (!test) {
		cout << i << ' ' << j << endl;
		int x;
		cin >> x;
		if (x == n)
			exit(0);
		return x;
	}

	b[i][j] ^= 1;
	return f();
}

int rec(int lf, int l, int r, int out) {
	if (l > r)
		return -1;
	int cur = rec(lf, l + 1, r, out);
	if (cur != -1)
		return cur;

	cur = ask(lf, l);
	if (cur != out)
		return cur;

	return rec(lf, l + 1, r, out);
}

int solve(int l, int r, int out, bool toask) {
	assert(l <= r);
	assert(l >= 1);
	assert(r <= n);
	int k;
	if (toask) 
		k = ask(l, r);
	else {		
		if (test)
			k = f();
		else
			cin >> k;
		if (k == n)
			exit(0);
	}
	
	assert(k >= out);

	if (k == out) {		
		k = rec(l, l, r, out);
	}	
	assert(k > out);
	vector < int > inds;
	for (int i = l; i <= r; ++i) {
		int kk = ask(i, i);
		if (kk != k) {
			inds.pb(i);
			if (kk < k) //we closed 1 position				
				assert(ask(i, i) == k);
			else { //we opened 1 position
				assert(k + 1 == kk);
				k = kk;
			}
		}
	}

	int lst = l - 1;
	for (auto i : inds) {
		if (i - 1 >= lst + 1)
			k = solve(lst + 1, i - 1, k, 1);
		lst = i;
	}
	if (lst + 1 <= r)
		k = solve(lst + 1, r, k, 1);

	return k;
}

int main() {
	srand(time(0));
	if (test) {
		n = 10;
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; ++j) 
				if (rand() & 1) {
					cout << "---> " << i << ' ' << j << endl;
					b[i][j] = 1;
				}
	} else
		cin >> n;	


	assert(solve(1, n, 0, 0) == n);
	assert(0);
}