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
   
const int N = 1e5 + 13, inf = 1e9, mod = 1e9 + 7, block = 444;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const ll INF = 1e18;
//fucking constants

int a[10], n, b[N], cur[N];
set < pii > q;
vi vals;

main () {
	for (int i = 0; i < 6; ++i)
		cin >> a[i];
	cin >> n;

	sort(a, a + 6);
	reverse(a, a + 6);

	for (int i = 1; i <= n; ++i) {
		cin >> b[i];              
		for (int j = 0; j < 6; ++j)
			vals.pb(b[i] - a[j]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	
	for (int i = 1; i <= n; ++i)
		q.insert(mp(b[i] - a[0], i));

	int ans = 2*inf;
	for (auto x : vals) {
		bool stop = 0;

		while (1) {
			int i = q.begin()->s;
			if (b[i] - a[cur[i]] >= x) 
				break;

			q.erase(q.begin());
			++cur[i];

			if (cur[i] == 6) {
				stop = 1;
				break;
			}

			q.insert(mp(b[i] - a[cur[i]], i));
		}

		if (stop)
			break;

		ans = min(ans, (*q.rbegin()).f - x);
	}

	cout << ans << endl;
}