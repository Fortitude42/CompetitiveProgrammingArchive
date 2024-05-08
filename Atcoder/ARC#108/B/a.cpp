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

int n;
string s;
set < int > q, qq, Q;

bool in (int x) {
	return x >= 0 && x < n;
}

int getPrv (int x) {
	if (*q.begin() == x)
		return -1;
	auto it = q.lower_bound(x);
	--it;
	return *it;
}

int getNxt (int x) {
	if (*q.rbegin() == x)
		return -1;

	return *q.upper_bound(x);
}

int _getPrv (int x) {
	if (*Q.begin() == x)
		return -1;

	auto it = Q.lower_bound(x);
	--it;

	return *it;
}


main () {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		q.insert(i);             
		if (s[i] == 'f') {
			qq.insert(i); 
			Q.insert(i);
		}
	}

	while (sz(qq)) {
		int v = *qq.begin();
		qq.erase(qq.begin());

		int u = -1, uu = -1;
		u = getNxt(v);

		if (u == -1)
			continue;

		uu = getNxt(u);
		if (uu == -1 || s[u] != 'o' || s[uu] != 'x')
			continue;

		q.erase(v);
		q.erase(u);
		q.erase(uu);

		int t = _getPrv(v);
		Q.erase(v);

		if (t != -1)
			qq.insert(t);
	}
	cout << sz(q) << endl;
} 