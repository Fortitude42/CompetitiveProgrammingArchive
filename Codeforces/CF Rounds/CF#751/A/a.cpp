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


int t, n, cnt[30];

main () {
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			for (int j = 0; j < 30; ++j)
				if (x & (1 << j))
					++cnt[j];
		}

		int gcd = 0;
		for (int j = 0; j < 30; ++j)
			gcd = __gcd(gcd, cnt[j]);

		vi ans;
		for (int i = 1; i <= n; ++i)
			if (gcd % i == 0)
				ans.pb(i);

		for (auto x : ans)
			cout << x << ' ';
		cout << endl;
	}
} 