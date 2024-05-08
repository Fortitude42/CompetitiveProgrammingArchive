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
   
   
const int N = 2e5 + 43, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int r, n, t[N], x[N], y[N], dp[N], dp1[N];


main () {
	cin >> r >> n;
	for (int i = 1; i <= n; ++i)
		cin >> t[i] >> x[i] >> y[i];

	x[0] = 1;
	y[0] = 1;

	for (int i = 1; i <= n; ++i) {
		dp[i] = -inf;
		for (int j = i - 1; i - j < 1000 && j >= 0; --j)
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) { 
				dp[i] = max(dp[i], dp[j] + 1);                      
//				cerr << i << ' ' << j << endl;
			}

		if (i >= 1000)
			dp[i] = max(dp[i], dp1[i - 1000] + 1);

		dp1[i] = max(dp[i], dp1[i - 1]);
	}
			
	cout << dp1[n] << endl;
} 