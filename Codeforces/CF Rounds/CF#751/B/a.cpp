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
   
   
const int N = 3e5 + 43, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int n, a[N], b[N], d[N][2];
deque < pii > q;
pii p[N][2];


main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);

	memset(d, -1, sizeof(d));

	d[n][1] = 0;
	q.pb({n, 1});
	while (sz(q)) {
		int v = q.front().f, i = q.front().s;
//		cerr << v << ' ' << i << ' ' << d[v][i] << endl;
		q.pop_front();

		if (!i) {
			if (v < n && (d[v + 1][i] == -1 || d[v + 1][i] > d[v][i])) {
				d[v + 1][i] = d[v][i];
				p[v + 1][i] = {v, i};
				q.push_front({v + 1, i});
			}

			if (d[v + b[v]][1] == -1 || d[v + 1 + b[v]][1] > d[v][i]) {
//				cerr << v << ' ' << v + b[v] << ' ' << d[v][i] << endl;
				d[v + b[v]][1] = d[v][i];
				p[v + b[v]][1] = {v, i};
				q.push_front({v + b[v], 1});
			}
		} else {
			if (d[v - a[v]][0] == -1) {
				d[v - a[v]][0] = d[v][i] + 1;
				p[v - a[v]][0] = {v, i};
				q.pb({v - a[v], 0});
			}
		}
	}

	printf("%d\n", d[0][1]);
	if (d[0][1] != -1) {
		int i = 0, j = 1;
		vi ans;

		while (i < n) {
			int ii = p[i][j].f, jj = p[i][j].s;
			if (!jj && j)
				ans.pb(ii);
//			cerr << i << ' ' << j << endl;
			i = ii, j = jj;
		}

		reverse(all(ans));
		for (auto x : ans)
			printf("%d ", x);
	}
} 