/*
I am not somebody you can put inside a box
And I am not somebody who will let you take my spot
It's written on my face I'm somebody who never stop
I do it because I gotta I don't do it for you props
Nah, you can keep those
I'm aiming way higher than planes in Heathrow
And I'm sorry to say but my game can't be sold
And look to be honest either you got it or don't
But if you got a dream and a vision
Put it in your mind that you gotta go out and get it
People try to stop you it's so hard in the beginning
But you said that you a winner so keep going ain't no quiting
I'm giving you the words that out me in this posotion
Some people hear and some people listen
Wanna be the best then you gotta learn the difference
*/
#include <bits/stdc++.h>                                           
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
	
   
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;   
   
const int N = 2e5 + 13, inf = 1e9, mod = 1e9 + 7, block = 444;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const ll INF = 1e18;
//fucking constants


int n, m, l[N], r[N], t[N];

void inc (int pos, int x) {
	while (pos < N) {
		t[pos] += x;
		pos |= pos + 1;
	}
}

void upd (int l, int r, int x) {
	inc(l, x);
	inc(r + 1, -x);
}


int get (int r) {
	int res = 0;
	while (r >= 0) {
		res += t[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

main () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> l[i] >> r[i];
	

	int add = 0, pos = 1, lst = 0, ans = 0;

	for (int i = 1; i <= n; ++i) {
		upd(l[i], r[i], 1);
		if (!(l[i] <= pos && pos <= r[i])) {
		} else {
			if (r[i] == m) {
				for (int j = i; j <= n; ++j)
					cout << -1 << endl;
				return 0;
			}	

			if (get(r[i]) == 1) 
				ans++;
			else
				ans += r[i] - pos + 1;

			pos = r[i] + 1;
			for (int j = lst + 1; j <= i; ++j)
				upd(l[j], r[j], -1);
			lst = i;
		}
		cerr << pos << endl;
		cout << ans + i << endl;
	}
}