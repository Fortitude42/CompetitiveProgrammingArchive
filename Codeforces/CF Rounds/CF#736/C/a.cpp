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
   
   
const int N = 3e6 + 43, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int n, q, f[N], rf[N], dp[N][3];

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;	
	}

	return res;
}

void precalc() {
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[N - 1] = binpow(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}

int cnk(int n, int k) {
	return f[n] * 1ll * rf[k] % mod * rf[n - k] % mod;
}

void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;	
}

void sub(int &x, int y) {
	x -= y;
	if (x < 0)
		x += mod;	
}

main () {
	precalc();

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= 3*n; ++i)
		add(dp[1][i % 3], cnk(i, 1));

	int r3 = binpow(3, mod - 2);

	for (int i = 2; i <= 3*n; ++i) {
		int sum = cnk(3*n + 1, i + 1);
		int d1 = dp[i - 1][1];//between 1 and 2
		int d2 = dp[i - 1][2];//between 2 and 0
		
		dp[i][1] = sum;
		sub(dp[i][1], d1);
		sub(dp[i][1], d1);
		sub(dp[i][1], d2);
		dp[i][1] = dp[i][1] * 1ll * r3 % mod;

		dp[i][2] = dp[i][1] + d1;
		if (dp[i][2] >= mod)
			dp[i][2] -= mod;
		
		dp[i][0] = dp[i][2] + d2;
		if (dp[i][0] >= mod)
			dp[i][0] -= mod;
	}

	while (q--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", dp[x][0]);
	}
} 