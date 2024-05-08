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
   
   
const int block = 333, inf = 1e9, mod = 1e9 + 7, N = 1e5 + 11;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int n, k;
bool was[N];

int ask (int x) {
	cout << "? " << x + 1 << endl;
	int y;
	cin >> y;
	return y;
}

void solve () {
	for (int i = 0, j = 0; j < min(n, block); ++j, i = (i + block) % n) {
		while (was[i])
			i = (i + 1) % n;

		was[i] = 1;				

		if (ask(i) == k)
			continue;

		int ii = i, add = 0;

		if (ask(i) > k)
			add = -1;
		else
			add = 1;
			

		while (ask(ii) != k) 
			ii = (ii + n + add) % n;
		cout << "! " << ii + 1 << endl;
		exit(0);
	}
		
}

main () {
	cin >> n >> k;
	solve();
	memset(was, 0, sizeof(was));
	solve();
} 