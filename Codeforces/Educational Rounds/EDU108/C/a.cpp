/*
Confine me let me be the lesser of a beautiful man
Without the blood on his hands
Come and make me a martyr come and break my feeling
With your violence with the gun on my head
 
Ready to take
Ready to take
Ready to take
Ready to take out anyone, anywhere
Anyone, anywhere
Anyone, anywhere
Anyone, anywhere
Anyone, anywhere
 
Black holes living in the side of your face
Razor wire spinning around your
Around your
Around your
Around your (blistering sky)
Around your (blistering sky)
Around your (blistering sky)
 
Bullets are the beauty of the blistering sky
Bullets are the beauty and I don’t know why
Bullets are the beauty of the blistering sky
Bullets are the beauty and I don’t know why
 
Personal responsibility
Personal responsibility
Personal responsibility (Insanity)
Personal responsibility (Insanity)
*/
#include <bits/stdc++.h>                                           
 
 
//#define int long long	
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define ll long long
#define vi vector < int >
#define pii pair < int, int > 
#define sz(s) (int)s.size()
#define all(x) x.begin(), x.end()                                                                    
#define pb push_back   
#define ppb pop_back
#define mp make_pair
#define s second
#define f first                                               
	
   
using namespace std;                  
   
   
const int N = 2e5 + 43, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants
                                                              

int t, n, k, u[N], s[N];
vector < ll > g[N];

main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &u[i]);       
			g[i].clear();
		}

		ll sum = 0;

		for (int i = 1; i <= n; ++i) {
			scanf("%d", &s[i]);
			g[u[i]].pb(s[i]);
			sum += s[i];
		}

		set < pii > q;
		for (int i = 1; i <= n; ++i) {
			sort(all(g[i]));
			for (int j = 1; j < sz(g[i]); ++j)
				g[i][j] += g[i][j - 1];			
			q.insert(mp(sz(g[i]), i));
		}

		for (int k = 1; k <= n; ++k) {
			ll res = 0;

			while (sz(q)) {
				int u = q.begin()->s;
				if (sz(g[u]) >= k)
					break;
				q.erase(q.begin());
				sum -= sz(g[u]) ? g[u].back() : 0;
			}


			for (auto x : q) {
				int y = x.f % k;
				res += !y ? 0 : g[x.s][y - 1];
			}
//			cerr << sum << ' ' << res << endl;
			printf("%lld ", sum - res);
		}

		printf("\n");		
	}
} 