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
   
   
const int N = 1043, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int n, x, pos, f[N], rf[N];
int down, up;


void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;

	if (x < 0)
		x += mod;
}

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n % 2 == 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n /= 2;
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
	return f[n] * 1ll * rf[n - k] % mod * rf[k] % mod;
}


main () {
	precalc();
	cin >> n >> x >> pos;
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (pos >= mid) {
			if (pos != mid)
				++down;
			l = mid + 1;
		} else {
			++up;
			r = mid;
		}
	}	


	cout << cnk(x - 1, down) * 1ll * cnk(n - x, up) % mod * f[n - down - up - 1] % mod * f[down] % mod * f[up] % mod << endl;
} 