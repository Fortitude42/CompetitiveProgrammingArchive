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
 
//#define int long long	
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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


int t, n, a[N], mn[N][20], pref[N], suff[N], d[N];


void build () {
	for (int i = 1; i <= n; ++i) {
		mn[i][0] = a[i];
		if (i > 1)
			d[i] = d[i >> 1] + 1;
	}

	for (int j = 1; j < 20; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
}

int get (int l, int r) {
	if (l > r)
		return inf + 2;
	int D = d[r - l + 1];
	return min(mn[l][D], mn[r - (1 << D) + 1][D]);
}


main () {
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; ++i) 
			cin >> a[i];              

		build();
		pref[0] = -1;
		suff[n + 1] = -1;

		for (int i = 1; i <= n; ++i)
			pref[i] = max(pref[i - 1], a[i]);

		for (int i = n; i > 0; --i)
			suff[i] = max(suff[i + 1], a[i]);		
		
		int x = -1, y = -1, z = -1;

		for (int i = 1; i <= n - 2; ++i) {
			int l = i + 1, r = n, l1 = -1, r1 = -1, l2 = -1, r2 = -1;

			while (l <= r) {
				int mid = (l + r) >> 1;
				if (get(i + 1, mid) <= pref[i]) {
					r = mid - 1;
					l1 = mid;
				} else
					l = mid + 1;
			}


			if (l1 == -1 || get(i + 1, l1) != pref[i])
				continue;

			l = i + 1, r = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (get(i + 1, mid) >= pref[i]) {
					l = mid + 1;
					r1 = mid;
				} else
					r = mid - 1;
			}


			
			l = i + 1, r = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (suff[mid] >= pref[i]) {
					l = mid + 1;
					r2 = mid;
				} else
					r = mid - 1;
			}

			if (r2 == -1 || suff[r2] != pref[i])
				continue;

			l = i + 1, r = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (suff[mid] <= pref[i]) {
					r = mid - 1;
					l2 = mid;
				} else
					l = mid + 1;
			}

			l2--;
			r2--;

			if (max(l1, l2) > min(r1, r2))
				continue;

			x = i;
			z = n - max(l1, l2);
			y = n - x - z;
			break;
		}
		if (x != -1) {
			cout << "YES\n";
			cout << x << ' ' << y << ' ' << z << endl;
		} else
			cout << "NO\n";
	}
}