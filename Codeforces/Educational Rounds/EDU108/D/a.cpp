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
   
   
const int N = 5043, inf = 1e9, mod = 998244353;
const double pi = acos(-1);
const ll INF = 1e18;
//fucking constants

int n, a[N], b[N], mx;

void f (int l, int r) {
	ll cur = 0;
	while (l >= 1 && r <= n) {
		cur += (a[r] - a[l]) * (b[l] - b[r]);
		mx = max(mx, cur);
		--l;
		++r;
	}
}

main () {
	cin >> n;
	ll sum = 0;

	for (int i = 1; i <= n; ++i) 
		cin >> a[i];              		
	
		
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];              
		sum += a[i] * b[i];
	}

	for (int i = 1; i <= n; ++i) {
		f(i, i);
		if (i < n)
			f(i, i + 1);
	}


	cout << sum + mx << endl;
	return 0;
} 