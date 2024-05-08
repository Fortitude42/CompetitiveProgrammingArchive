#include "scales.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int a[3], b[3];
vi v;

void init(int T) {
	srand(time(0));
	for (int i = 1; i <= 6; ++i)
		v.pb(i);
}

void orderCoins() {
	int w[6];


	int timer = rand() % 5;
	while (timer--)
		random_shuffle(all(v));
	a[2] = getHeaviest(v[0], v[1], v[2]);
	a[0] = getLightest(v[0], v[1], v[2]);
	for (int i = 0; i < 3; ++i)
		if (v[i] != a[0] && v[i] != a[2])
			a[1] = v[i];

	b[2] = getHeaviest(v[3], v[4], v[5]);
	b[0] = getLightest(v[3], v[4], v[5]);
	for (int i = 3; i < 6; ++i)
		if (v[i] != b[0] && v[i] != b[2])
			b[1] = v[i];	
		

	int res1 = getNextLightest(a[0], a[1], a[2], b[0]);
	int res2 = getNextLightest(a[0], a[1], a[2], b[1]);

	if (res1 != a[0] && res2 == a[0]) {
		w[0] = a[0];	
		w[1] = b[0];
		w[2] = a[1];
		w[3] = a[2];
		w[4] = b[1];
		w[5] = b[2];
		if (res1 == a[2])
			swap(w[1], w[2]);		

		answer(w);			
		return;
	}


	int res3 = getNextLightest(a[0], a[1], a[2], b[2]);
	if (res1 == a[0] && res2 == a[0] && res3 == a[0]) {
	    int res4 = getMedian(b[1], b[2], a[0]);
	    if (res4 == b[2]) {
	    } else if (res4 == a[0]) {
			res3 = 7;
		} else {
			res2 = res3 = 7;
			if (getLightest(a[0], a[1], b[0]) == a[0])
				res1 = 7;
			else
				res1 = a[0];
		}
	}

	int j = 0, x = 0;
	while (x < 3 && res1 != a[x])
		w[j++] = a[x++];
	w[j++] = b[0];

	while (x < 3 && res2 != a[x])	
		w[j++] = a[x++];

	w[j++] = b[1];

	while (x < 3 && a[x] != res3)
		w[j++] = a[x++];

	w[j++] = b[2];

	while (x < 3)
		w[j++] = a[x++];

	answer(w);
}