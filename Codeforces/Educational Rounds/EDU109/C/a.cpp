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
   
   
const int N = 3e5 + 43, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants
                                                              
int t, n, x[N], res[N], m;
char c[N];


void solve (vi a) {
	for (auto i : a)
		res[i] = -1;

	vector < pii > b;
	for (auto i : a)
		b.pb({x[i], i});

	sort(all(b));

	stack < int > st;
	for (auto j : b) {
		int i = j.s;
		if (c[i] == 'L') {
			if (!sz(st))
				continue;
			int t = st.top();
			st.pop();
			res[t] = res[i] = (x[i] - x[t]) / 2;
		} else 
			st.push(i);
	}



	while (sz(st))
		st.pop();

	for (auto j : b) {
		int i = j.s;
		if (c[i] == 'R' || res[i] != -1)
			continue;
		if (!sz(st))
			st.push(i);
		else {
			int t = st.top();
			st.pop();
			res[t] = res[i] = (x[t] + x[i]) / 2;			
		}	
	}

	while (sz(st))
		st.pop();

	reverse(all(b));
	for (auto j : b) {
		int i = j.s;
		if (c[i] == 'L' || res[i] != -1)
			continue;
		if (!sz(st))	
			st.push(i);
		else {
			int t = st.top();
			st.pop();
			res[t] = res[i] = (2*m - x[t] - x[i]) / 2;
		}	
	}

	while (sz(st))
		st.pop();

	reverse(all(b));
	for (auto j : b) {
		int i = j.s;
		if (res[i] != -1)
			continue;
		if (!sz(st))
			st.push(i);
		else {
			int t = st.top();
			st.pop();
			assert(c[t] == 'L' && c[i] == 'R');
			res[t] = res[i] = (2*m + x[t] - x[i]) / 2;
		}
	}

}

main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &x[i]);
		scanf("\n");
		for (int i = 1; i <= n; ++i)  
			scanf(" %c", &c[i]);


		vi a, b;
		for (int i = 1; i <= n; ++i) {
			if (x[i] & 1)
				a.pb(i);
			else
				b.pb(i);	
		}

		solve(a);
		solve(b);
		
		for (int i = 1; i <= n; ++i)
			printf("%d ", res[i]);

		printf("\n");				
	}
} 