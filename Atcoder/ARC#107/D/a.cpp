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
   
   
const int N = 3043, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

void add (int &x, int y) {
	x += y;

	if (x >= mod)
		x -= mod;
}

int n, k, dp[N][N];

int calc (int sum, int cnt) {
//	cerr << sum << ' ' << cnt << endl;
	if (sum > cnt)
		return 0;
	int &res = dp[sum][cnt];
	if (res != -1)
		return res;

	if (cnt == sum)
		return res = 1;
	res = 0;

	if (sum)
		add(res, calc(sum - 1, cnt - 1));
	add(res, calc(2*sum, cnt));
	

	return res;
}



main () {
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	cout << calc(k, n) << endl;
} 