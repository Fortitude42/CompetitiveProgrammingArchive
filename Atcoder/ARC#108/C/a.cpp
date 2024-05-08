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
 
 
#define int long long	
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
   
   
const int N = 2e5 + 43, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int n, m, v, u, w, c[N], t[N], timer, p[N];
vector < pii > g[N];

void dfs (int v, int p = 0) {
	for (auto to : g[v])
		if (to.f != p) {
			if (to.s != c[v])
				c[to.f] = to.s;
			dfs(to.f, v);
		}	
}

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}

main () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	while (m--) {
		cin >> v >> u >> w;
		if (get(v) != get(u)) {
			g[v].pb({u, w});
			g[u].pb({v, w});
			merge(v, u);
		}
	}

	dfs(1);
	for (int i = 1; i <= n; ++i) {
		if (c[i])
			continue;
		
		++timer;
		for (auto j : g[i])
			t[j.s] = timer;
		
		c[i] = 1;
		while (t[c[i]] == timer)
			++c[i];
	}

	for (int i = 1; i <= n; ++i)
		cout << c[i] << endl;
} 