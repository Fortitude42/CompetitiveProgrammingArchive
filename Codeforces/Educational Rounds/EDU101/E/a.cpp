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
   
   
const int N = 1e6 + 1e5 + 43, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants


int q, n, k, pr[N], timer, T[N], Sz, nxt[N*20][2], cnt[N*20];
char s[N];

inline int get (int l, int r) {
	if (!l)
		return pr[r];

	return pr[r] - pr[l - 1];
}

inline void add (int mask, int x) {
	int v = 0;
	for (int i = 0; i < min(20, k); ++i) {
		int bit = (mask >> i) & 1;
		if (nxt[v][bit] == -1)
			nxt[v][bit] = ++Sz;

		v = nxt[v][bit];
		cnt[v] += x;
	}
}


int get () {
	int v = 0, res = 0, len = min(20, k);

	for (int i = 0; i < min(20, k); ++i) {
		--len;
		if (nxt[v][1] == -1)
			break;

		if (cnt[nxt[v][1]] == (1 << len)) {
			res |= (1 << i);
			if (nxt[v][0] == -1)
				break;
			v = nxt[v][0];
		} else 
			v = nxt[v][1];
	}

	return res;
}


main () {
	memset(nxt, -1, sizeof(nxt));

	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &n, &k);
		scanf("\n%s", s);

		for (int i = 0; i < n; ++i) 
			pr[i] = (!i ? 0 : pr[i - 1]) + s[i] - '0';
		
		
		string t = "";
		for (int i = 0; i < k - 20; ++i)
			t += "0";

		vi V;
		++timer;

		for (int i = k - 1; i < n; ++i) {
			if (k <= 20 || get(i - k + 1, i - 20) == (i - 20 - (i - k + 1) + 1)) { 
				int mask = 0;
				for (int x = min(19, k - 1); x >= 0; --x) {
					if (s[i - x] == '1') 
						mask |= (1 << (min(19, k - 1) - x));
				}

				if (T[mask] == timer) 
					continue;
				
				T[mask] = timer;
				V.pb(mask);
				add(mask, 1);
			}
		}

		if (k <= 20 && sz(V) == (1 << k)) {
		for (auto x : V)
			add(x, -1);
			printf("NO\n");
			continue;
		}
		
		int cur = get();
		for (int i = 0; i < min(k, 20); ++i)
			if (cur & (1 << i))
				t += "1";
			else
				t += "0";


		for (auto x : V)
			add(x, -1);
		
		printf("YES\n");
		for (auto c : t)
			printf("%c", c);
		printf("\n");
	}
} 