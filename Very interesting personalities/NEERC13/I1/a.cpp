//by paradox & gege & parasat
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
const int M = N + 17, maxn = 1e7 + 11;
const ll INF = 1e18;

int p, v, l[M], r[M], timer;
ll s[maxn];

bool ask(int l, int r) {
	cout << "check " << l << ' ' << r << endl;
	string s;
	cin >> s;
	return s[0] == 'Y';
}



void solve() {
	cin >> p >> v;
	for (int i = 0; i <= v; ++i) {
		l[i] = 0; 
		r[i] = p;
	}

	timer = 0;
	int L = 0, R = p;
	while (1) {
		memset(s, 0, sizeof(s));
		ll totArea = 0;
		for (int i = 0; i <= v; ++i)
			if (l[i] <= r[i]) {
				assert(L <= l[i] + i*timer);
				assert(r[i] + i*timer <= R);
				s[l[i] + i*timer]++; 
				s[r[i] + i*timer + 1]--;
				totArea += r[i] - l[i] + 1;
			}

		ll optD = INF, curs = 0;
		int y = -1;
		ll z = 0;

		for (int i = L; i <= R; ++i) {
			s[i] += (!i ? 0 : s[i - 1]); 
			curs += s[i];
			ll curD = abs(totArea - curs*2);
			if (optD > curD) {
				optD = curD;
				y = i;
				z = s[i];
			}
		}

			
		if (optD == totArea) {
			for (int i = 0; i < maxn; ++i) {
				if (s[i] == totArea) {
					cout << "answer " << i;
					return;
				}
					
			}
		}

			
		
		bool x = ask(0, y);
		if (x) {
			R = min(R, y);
			for (int i = 0; i <= v; ++i)
				r[i] = min(r[i], y - i*timer); 			
		} else {
			L = max(L, y + 1);
			for (int i = 0; i <= v; ++i)
				l[i] = max(l[i], y - i*timer + 1); 
		}

		R += v;
		++timer;
	}	
}

main () {
	fastio
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

