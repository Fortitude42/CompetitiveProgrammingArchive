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
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants


int t, n, k;
string s;
vi pos;

main () {
	cin >> t;
	while (t--) {
		pos.clear();

		cin >> n >> k >> s;
		for (int i = 0; i < n; ++i)
			if (s[i] == 'W')
				pos.pb(i);

		vector < pii > D;
		for (int i = 0; i < sz(pos) - 1; ++i) {
			if (pos[i] + 1 == pos[i + 1])
				continue;
			D.pb(mp(pos[i + 1] - pos[i] - 1, pos[i] + 1));
		}

		sort(all(D));
		for (int i = 0; i < sz(D); ++i) {
			for (int j = 0; j < D[i].f; ++j) {
		        if (!k)
		        	break;
				s[D[i].s + j] = 'W';
				--k;
			}
		}

		for (int i = 1; i < n; ++i)
			if (s[i - 1] == 'W' && s[i] == 'L') {
				if (!k)
					break;
				s[i] = 'W';
				--k;
			}

		for (int i = n - 1; i > 0; --i)
			if (s[i] == 'W' && s[i - 1] == 'L') {
				if (!k)
					break;
				s[i - 1] = 'W';
				--k;
			}

		for (int i = 0; i < n; ++i)
			if (s[i] == 'L') {
				if (!k)
					break;
				s[i] = 'W';
				--k;
			}

		int bal = 0;
		for (int i = 0; i < n; ++i)
			if (s[i] == 'W') {
				++bal;
				if (i && s[i - 1] == 'W')
					++bal;
			}

		cout << bal << endl;
	}
} 