#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, k, p[N];
bitset < 14 > B;
 
unordered_map<int, ll> mt[1 << 12][12];            

ll f(int i, int s){
	if(s > k)
		return 0;
	if(B.count())
		return 1;
	if(mt[mask][i].count(s))
		return mt[mask][i][s];
	ll res = 0;
	for(int j = B._Find_first(); j < n; j = B.Find_next(j))
		res += f(mask | (1 << j), j, s + max(0, p[i] - p[j] + 1) * (n - __builtin_popcount(mask)));
	return mt[mask][i][s] = res;
}
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	ll ans = 0;
	for(int i = 0; i + 1 < n; i++)
		ans += f((1 << i), i, n * (p[n - 1] - p[i] + 1));		
	cout << ans;
}