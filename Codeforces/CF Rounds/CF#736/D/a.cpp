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
   
   
const int N = 6043, inf = 1e9, mod = 998244353;
const double pi = acos(-1);
const ll INF = 1e18;
//fucking constants

int n, cnt[4][4];

int f(int x) {
	return x * (x - 1) / 2;
}

main () {
	cin >> n;
	ll ans = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		x %= 4, y %= 4;
		int cnt0 = cnt[x][y];
		int cnt1 = cnt[(x + 2) % 4][y] + cnt[(x + 2) % 4][(y + 2) % 4] + cnt[x][(y + 2) % 4];
		ans += cnt0 * 1ll * cnt1;
		ans += f(cnt[(x + 2) % 4][y]);
		ans += f(cnt[(x + 2) % 4][(y + 2) % 4]);
		ans += f(cnt[x][(y + 2) % 4]);
		ans += f(cnt0);
		++cnt[x][y];
	}

	cout << ans << endl;
	return 0;
} 