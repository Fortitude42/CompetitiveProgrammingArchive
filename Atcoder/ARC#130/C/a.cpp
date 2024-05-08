//template by paradox & gege & parasat
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

bool sw;
int cnta[12], cntb[12];
string a, b, aa, bb;


inline int find(int x) {
	for (int i = x; i < 10; ++i)
		if (cntb[i]) {
		    --cntb[i];
			return i;
		}

	return -1;
}

int solve(int d) {
	for (int i = 0; i < 10; ++i)
		cnta[i] = cntb[i] = 0;

	for (auto c : a)
		++cnta[c - '0'];

	for (auto c : b)
		++cntb[c - '0'];

	int dd = find(10 - d);
	if (!cnta[d] || dd == -1)
		return -1;

	--cnta[d];

	aa = "", bb = "";
	aa += char(d + '0');
	bb += char(dd + '0');


	int res = 1;
	string adda = "";

	while (1) {
		int x = -1;
		for (int i = 0; i < 10; ++i)
			if (cnta[i]) {
				x = i; 
				break;
			}

		if (x == -1)
			break;

		--cnta[x];

		int y = find(9 - x);
		if (y == -1) {
			adda += char(x + '0');
			continue;
		}

		aa += char(x + '0');
		bb += char(y + '0');
		res++;	
	}

	while (cntb[9]) {
		--cntb[9];
		++res;
		bb += '9';
	}

	aa += adda;

	for (int x = 0; x < 10; ++x)
		for (int y = 0; y < cntb[x]; ++y)
			bb += char(x + '0');

	reverse(all(aa));
	reverse(all(bb));

	return res;
}

void solve() {
	fastio
	cin >> a >> b;
	if (sz(a) > sz(b)) {
	    sw = 1;
		swap(a, b);      
	}

	aa = a, bb = b;

	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		int cur = solve(i);
		if (cur > ans) {
			ans = cur;
			a = aa;
			b = bb;
		}
	}

	if (sw)
		swap(a, b);


	cout << a << endl << b << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}