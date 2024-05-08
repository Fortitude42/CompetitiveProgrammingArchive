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
   
   
const int N = 3e5 + 143, inf = 1e9, mod = 998244353, maxn = 1e6 + 11;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int t, n, q, a[N], lp[maxn], mx1, mx2;
map < vi, int > cnt;
ll w;
vi g[N];

void precalc () {
	for (int i = 2; i < maxn; ++i)
		if (!lp[i]) {
			for (int j = i; j < maxn; j += i)
				lp[j] = i;
		}
}

main () {
	precalc();

	scanf("%d", &t);
	while (t--) {
		mx1 = mx2 = 0;
		cnt.clear();

		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);      
			g[i].clear();
			while (a[i] > 1) {
				int x = lp[a[i]], cnt = 0;
				while (!(a[i] % x)) {
					cnt++;
					a[i] /= x;
				}

				if (cnt & 1)
					g[i].pb(x);
			}
			sort(all(g[i]));
			++cnt[g[i]];
		}
		
		for (auto x : cnt) {
			mx1 = max(mx1, x.s);
			if (!(x.s & 1) || !(sz(x.f)))
				mx2 += x.s;
		}

		mx2 = max(mx2, mx1);
		
		
		scanf("%d", &q);
		while (q--) {
			scanf("%lld", &w);
			printf("%d\n", !w ? mx1 : mx2);
		}
	}
} 