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
Bullets are the beauty and I don�t know why
Bullets are the beauty of the blistering sky
Bullets are the beauty and I don�t know why
 
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

int t, n;
vector < pii > v;

main () {
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();

		for (int i = 9; i <= n - 1; ++i)
			v.pb({i, n});
		
		if (n > 8) {
			int m = n;
			while (m > 1) {
				v.pb({n, 8});
				m = (m + 7) / 8;
			}
			n = 8;
		}

		for (int i = 2; i < n; ++i)
			if (i != (n + 1) / 2)
				v.pb({i, n});

		v.pb({n, (n + 1) / 2});
		v.pb({(n + 1) / 2, n});
		v.pb({(n + 1) / 2, n});
		cout << sz(v) << endl;
		for (auto x : v)
			cout << x.f << ' ' << x.s << endl;
	}
	return 0;
} 