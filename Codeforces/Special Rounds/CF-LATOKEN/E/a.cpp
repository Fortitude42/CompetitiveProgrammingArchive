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
   
   
const int N = 513, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants


int n, k, d[N];
queue < int > q;
pair < int, pii > p[N];


main () {
	cin >> n >> k;
	memset(d, -1, sizeof(d));

	d[0] = 0;
	q.push(0);

	while (sz(q)) {
		int x = q.front(), y = n - q.front();
		q.pop();

		for (int i = 0; i <= k; ++i) {
			int j = k - i;
			if (i > x || j > y || d[x - i + j] != -1)
				continue;
			d[x - i + j] = d[x] + 1;
			q.push(x - i + j);
			p[x - i + j] = mp(x, mp(j, i));
		}
	}

	if (d[n] == -1) {
		cout << -1 << endl;
		return 0;
	}

	vector < pii > ans;
	int x = n;


	while (x) {
		int xx = p[x].f, i = p[x].s.f, j = p[x].s.s;
		ans.pb({i, j});
		x = xx;
	}

	reverse(all(ans));
	set < int > a1, a0;

	for (int i = 1; i <= n; ++i)
		a0.insert(i);

	int res = 0;
	for (auto x : ans) {
		cout << "? ";
		vi b0, b1;
		while (sz(b0) < x.f) {
			b0.pb(*a0.begin());
			a0.erase(a0.begin());
		}

		while (sz(b1) < x.s) {
			b1.pb(*a1.begin());
			a1.erase(a1.begin());
		}

		for (auto x : b0)
			cout << x << ' ';
		for (auto x : b1)
			cout << x << ' ';
		cout << endl;
		int s;
		cin >> s;
		res ^= s;

		for (auto x : b0)
			a1.insert(x);
		for (auto x : b1)
			a0.insert(x);
	}

	cout << "! " << res << endl;
} 