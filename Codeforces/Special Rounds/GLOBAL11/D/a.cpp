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

vector < vi > ans;
int n, c[55];
bool rev;

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	for (int i = 1; i < n; ++i) {
		int pos = -1;
		for (int j = 1; j <= n; ++j)
			if (c[j] == i)
				pos = j;
		
		vi cur;

		if (i % 2 == 0) {
			for (int j = 1; j < i; ++j)
				cur.pb(1);
			cur.pb(pos - i + 1);
			if (pos != n)
				cur.pb(n - pos);
		} else {
			for (int j = 1; j < i; ++j)
				cur.pb(1);

			cur.pb(n - i - pos + 2);
			if (pos != 1)
				cur.pb(pos - 1);
			reverse(all(cur));
		}

		if (sz(cur) > 1) {
			ans.pb(cur);
			vector < vi > V;
			int j = 1;
			for (int x = 0; x < sz(cur); ++x) {
				vi T;
				for (int y = 0; y < cur[x]; ++y) 
						T.pb(c[j++]);                 			
	
				V.pb(T);
			}

			reverse(all(V));
			j = 1;
			for (auto x : V) {
				for (auto y : x) 
					c[j++] = y;	
			}
		}
	}

	if (n % 2 == 1 && n > 1) {
		vi cur;
		for (int i = 1; i <= n; ++i)
			cur.pb(1);
		ans.pb(cur);
	}

	cout << sz(ans) << endl;
	for (auto x : ans) {
		cout << sz(x) << ' ';
		for (auto y : x)
			cout << y << ' '; 

		cout << endl;
	}

} 