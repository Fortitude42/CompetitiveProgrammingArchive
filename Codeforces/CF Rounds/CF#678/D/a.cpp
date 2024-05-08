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
const double pi = acos(-1);
const ll INF = 1e18;
//fucking constants


int n, p, a[N], mx[N], sum[N], cnt[N];
vi g[N];

void dfs (int v) {
	if (!sz(g[v])) {
		cnt[v] = 1;
		sum[v] = mx[v] = a[v];
		return;
	}

	for (auto to : g[v]) {
		dfs(to);
		cnt[v] += cnt[to];
		mx[v] = max(mx[v], mx[to]);
		sum[v] += sum[to];
	}

	int cur = mx[v] * cnt[v] - sum[v];
	sum[v] += a[v];

	a[v] = max(0ll, a[v] - cur);
	mx[v] += (a[v] + cnt[v] - 1) / cnt[v];	
}

main () {
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> p;
		g[p].pb(i);
	}

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
		
	dfs(1);
	cout << mx[1] << endl;
	return 0;
} 