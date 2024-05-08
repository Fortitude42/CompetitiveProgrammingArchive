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
   
   
const int N = 2e5 + 43, inf = 1e9, mod = 1e9 + 7;
const double pi = acos(-1);
const ll INF = 1e18;
//fucking constants

int t, n, k, h[N];

bool inter (int l1, int r1, int l2, int r2) {
	return max(l1, l2) + 1 <= min(r1, r2);
}

main () {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			cin >> h[i];

		int l = 0, r = 0;
		for (int i = 2; i <= n; ++i) {
			int lf = 0, rg = k - 1, L = -1, R = -1;
			while (lf <= rg) {
				int mid = (lf + rg) / 2;
				if (inter(h[i - 1] + l, h[i - 1] + r + k, h[i], h[i] + k + mid)) {
					rg = mid - 1;
					L = mid;
				} else
					lf = mid + 1;
			}

			lf = 0, rg = k - 1;
			while (lf <= rg) {
				int mid = (lf + rg) / 2;
				if (inter(h[i - 1] + l, h[i - 1] + r + k, h[i] + mid, h[i] + k - 1 + k)) {
					lf = mid + 1;
					R = mid;
				} else
					rg = mid - 1;
			}

			l = L, r = R;

			if (L == -1)
				break;
		}

		puts((l <= 0 && 0 <= r) ? "YES" : "NO");
	}
} 