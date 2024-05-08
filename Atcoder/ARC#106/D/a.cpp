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
   
 	  
const int N = 2e5 + 43, inf = 1e9, mod = 998244353;
const ll INF = 1e18;                    
const double pi = acos(-1);    
//fucking constants

int f[N], rf[N], n, k, a[N], b[N], s[N], res[N], ss[N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n % 2 == 1)
			res = res * 1ll * a % mod;
		n >>= 1;
		a = a * 1ll * a % mod;
	}

	return res;
}

void precalc () {
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;


	rf[N - 1] = binpow(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}

int cnk (int n, int k) {
	if (n < k)
		return 0;
	return f[n] * 1ll * rf[k] % mod * rf[n - k] % mod;
}

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;

	if (x < 0)
		x += mod;
}

main () {
	precalc();

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];              
		b[i] = 1;
	}
	
	for (int x = 0; x <= k; ++x) {
		for (int i = 1; i <= n; ++i) {
			add(s[x], b[i]);
			b[i] = b[i] * 1ll * a[i] % mod;
		}

		s[x] = s[x] * 1ll * rf[x] % mod;
	}

	for (int x = 0; x <= k; ++x)
		for (int y = 0; y <= k; ++y)
			add(ss[x + y], s[x] * 1ll * s[y] % mod);


	for (int x = 0; x <= k; ++x) {
		res[x] = ss[x] * 1ll * f[x] % mod;		
	}

	for (int i = 1; i <= n; ++i)
		b[i] = 1;

	for (int x = 0; x <= k; ++x) {
//		cerr << res[x]<< endl;

		for (int i = 1; i <= n; ++i) {
			add(res[x], -b[i]);
			b[i] = b[i] * 2ll * a[i] % mod;
		}

		res[x] = res[x] * 1ll * binpow(2, mod - 2) % mod;
		if (x > 0)
			cout << res[x] << endl;
	}


} 