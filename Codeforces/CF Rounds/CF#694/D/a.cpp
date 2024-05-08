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
   
   
const int N = 3e5 + 43, inf = 1e9, mod = 998244353;
const double pi = acos(-1);
const ll INF = 1e18;
//fucking constants
                      	
int t, n, m, v, u;
bool was[N], used[N];
vi g[N], ans;

void dfs (int v) {
	was[v] = 1;
	if (!used[v]) {
		ans.pb(v);
		for (auto to : g[v])
			used[to] = 1;
	}

	for (auto to : g[v])
		if (!was[to])
			dfs(to);
		
}

main () {
	scanf("%d", &t);
	while (t--) {
		ans.clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			g[i].clear();             
			was[i] = used[i] = 0;
		}


		while (m--) {
			scanf("%d%d", &v, &u);
			g[v].pb(u);
			g[u].pb(v);
		}

		dfs(1);
		bool ok = 1;
		for (int i = 1; i <= n; ++i)
			if (!was[i])
				ok = 0;

		if (!ok) {
			printf("NO\n");
			continue;
		}

		printf("YES\n");
		sort(all(ans));
		printf("%d\n", sz(ans));
		for (auto x : ans)
			printf("%d ", x);
 		printf("\n");
	}
	return 0;
} 