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
   
   
const int N = 1e4 + 43, inf = 1e9, mod = 998244353;
const double pi = acos(-1);
const ll INF = 1e18;
//fucking constants


int t, n, m, k;
bitset < N > dp[103][103];

main () {
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				dp[i][j].reset();

		dp[1][1][0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				dp[i + 1][j] |= (dp[i][j] << j);
				dp[i][j + 1] |= (dp[i][j] << i);
			}

		puts(dp[n][m][k] ? "YES" : "NO");
	}
} 