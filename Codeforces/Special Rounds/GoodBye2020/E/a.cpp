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
   
   
const int N = 5e5 + 43, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int t, n, x[N], cnt[100], s1[N], s2[N], p[100];


void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;

	if (x < 0)
		x += mod;
}

main () {
	p[0] = 1;
	for (int i = 1; i < 60; ++i)
		p[i] = p[i - 1] * 2 % mod;

	scanf("%lld"
	, &t);
	while (t--) {
		scanf("%lld", &n);

		for (int i = 0; i < 60; ++i)
			cnt[i] = 0;

		int ans = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &x[i]);

		for (int i = 1; i <= n; ++i) 
			for (int j = 0; j < 60; ++j) 
				if (x[i] & (1ll << j)) 
					++cnt[j];           

		for (int i = 1; i <= n; ++i) {
			s1[i] = s2[i] = 0;		
			for (int j = 0; j < 60; ++j) {
				if (x[i] & (1ll << j)) {
					add(s1[i], p[j] * cnt[j] % mod);
					add(s2[i], p[j] * n % mod);
				} else
					add(s2[i], p[j] * cnt[j] % mod);
			}		

			add(ans, s1[i] * s2[i] % mod);
//			cerr << "--> " << i << ' ' << s1[i] << ' ' << s2[i] << endl;
		}   	

		cout << ans << endl;
	}
} 