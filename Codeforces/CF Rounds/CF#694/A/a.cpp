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
   
   
const int N = 3e5 + 143, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants
int t, n, m, k[N], c[N];


main () {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &k[i]);

		for (int i = 1; i <= m; ++i)
			scanf("%lld", &c[i]);

		sort(k + 1, k + 1 + n);
		int i = n, ans = 0;
		for (int j = 1; j <= m; ++j) {
			if (!i || j >= k[i])
				break;
			ans += c[j];
			--i;
		}

		for (int ii = 1; ii <= i; ++ii)
			ans += c[k[ii]];

		printf("%lld\n", ans);
	}
} 