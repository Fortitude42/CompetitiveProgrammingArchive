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
   
   
const int N = 2e5 + 143, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants


int n, m, Q, ans;
set < int > q[N];
bool bad[N];

void upd(int v) {
	if (bad[v] && (!sz(q[v]) || *q[v].rbegin() < v)) {
		bad[v] = 0;
		ans++; 
		return;
	}

	if (!bad[v] && sz(q[v]) && *q[v].rbegin() > v) {
		bad[v] = 1;
		ans--;
		return;
	}
		
}

main () {
	scanf("%d%d", &n, &m);
	while (m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		q[v].insert(u);
		q[u].insert(v);
	}

	memset(bad, 1, sizeof(bad));
	for (int i = 1; i <= n; ++i)
		upd(i);
	

	scanf("%d", &Q);
	while (Q--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int v, u;
			scanf("%d%d", &v, &u);
			q[v].insert(u);
			q[u].insert(v);
			upd(v);
			upd(u);
		} else if (tp == 2) {
			int v, u;
			scanf("%d%d", &v, &u);
			q[v].erase(u);
			q[u].erase(v);
			upd(v);
			upd(u);
		} else {
			printf("%d\n", ans);
		}
	}
} 