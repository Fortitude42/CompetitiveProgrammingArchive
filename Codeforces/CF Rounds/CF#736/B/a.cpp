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
   
   
const int N = 2e5 + 143, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants


ll a[N], g[N][18];
int n, t, d[N], ans;

ll get (int l, int r) {
	int D = d[r - l + 1];
	return __gcd(g[l][D], g[r - (1 << D) + 1][D]);
}

main () {
	for (int i = 2; i < N; ++i)
		d[i] = d[i >> 1] + 1;

	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i) 
			scanf("%lld", &a[i]);
		

		for (int i = 1; i < n; ++i) 
			g[i][0] = abs(a[i + 1] - a[i]); 
		


		for (int j = 1; j < 18; ++j)
			for (int i = 1; i + (1 << j) - 1 < n; ++i)
				g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);

		ans = 1;
		for (int i = 1; i < n; ++i) {
			int l = i, r = n - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (get(i, mid) != 1)
					l = mid + 1;
				else
					r = mid - 1;
			}

			ans = max(ans, l - i + 1);
		}


		printf("%lld\n", ans);
	}
} 