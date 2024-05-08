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
   
   
const int N = 4e5 + 43, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants


int t, n, a[N], b[N], ans, was[N*2], timer;
vi g[N*2];

void dfs (int v) {
	was[v] = timer;
	for (auto to : g[v])
		if (was[to] != timer)
			dfs(to);
}

main () {
	scanf("%d", &t);
	while (t--) {
		++timer;

		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);       
			g[i].clear();
		}

		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);       
			g[a[i]].pb(b[i]);
			g[b[i]].pb(a[i]);
		}

		int ans = 1;
		for (int i = 1; i <= n; ++i)
			if (was[i] != timer) {
				dfs(i);           
				ans += ans;
				if (ans >= mod)
					ans -= mod;
			}

		cout << ans << endl;
	}
} 