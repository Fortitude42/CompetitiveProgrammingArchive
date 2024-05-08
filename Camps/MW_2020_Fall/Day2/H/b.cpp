#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 100500, K = 18, mod = 1e9 + 7;
const ll INF = 1e18;
                             
int n, m, a[N], cnt[N], CNT[N];
vector< int > s[N];

bool was[K + 1][N];
int dp[K + 1][N];

void add(ll &a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
}
void sub(ll &a, ll b){
	a -= b;
	if(a < 0)
		a += mod;
}
int f(int i, int j){
	if(i < 0 || i >= n){
		if(i + (int)s[j].size() / 2 < 0)
			return 0;
		if(i - (int)s[j].size() / 2 >= n)
			return 0;
		int shift = (int)s[j].size() / 4 + 1;
		return f(i - shift, j - 1) + f(i + shift, j - 1); 
	}
	if(was[j][i])
		return dp[j][i];
	was[j][i] = 1;
	int res = 0;
	if(j < K)
		res += (a[i] != j);
	else
		res += (a[i] < K);
	if(j == 1)
		return dp[j][i] = res;
	int shift = (int)s[j].size() / 4 + 1;
	res += f(i - shift, j - 1) + f(i + shift, j - 1); 
	return dp[j][i] = res;
}
ll bp(ll x, ll p){
	ll res = 1;
	while(p){
		if(p & 1)
			res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}
int main()
{
	s[1].pb(1);
	for(int i = 2; i <= K; i++){
		for(auto x : s[i - 1])
			s[i].pb(x);
		s[i].pb(i);
		for(auto x : s[i - 1])
			s[i].pb(x);
	}	
	while(~scanf("%d %d", &n, &m)){
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; i++)
			CNT[a[i]]++;
		for(int i = 0; i <= K; i++)
			for(int j = 0; j < n; j++)
				was[i][j] = 0;
		ll ans = 0;
		int mn = 1e9;
		ll kek = 0;
		for(int i = 1; i <= min(m, K); i++){
			add(ans, ans);
			if(i == K){
				int mid = (int)s[i].size() / 2;
				int l = max(0, mid - n + 1);
				int r = min((int)s[i].size() - 1, mid + n - 1) - n + 1;
				for(int q = 0; q < n; q++){
					int cl = l + q;
					int cr = r + q;
					if(cl <= mid && mid <= cr)
						mn = min(mn, f(q, i));
					if(q == 0){
						for(int j = cl; j <= cr; j++)
							cnt[s[i][j]]++;
					}else{
						cnt[s[i][cl - 1]]--;
						cnt[s[i][cr]]++;					
					}
					if(a[q] < K)
						kek += (r - l + 1) - cnt[a[q]];					
					else
						kek += (r - l + 1);					
					if(q == n - 1){
						for(int j = cl; j <= cr; j++)
							cnt[s[i][j]]--;
					}
				}
				kek %= mod;
				
				add(ans, kek);
				sub(ans, CNT[i]);
			}else if(s[i].size() >= n){
				int mid = (int)s[i].size() / 2;
				int l = max(0, mid - n + 1);
				int r = min((int)s[i].size() - 1, mid + n - 1) - n + 1;
				for(int q = 0; q < n; q++){
					int cl = l + q;
					int cr = r + q;
					if(cl <= mid && mid <= cr)
						mn = min(mn, f(q, i));
					if(q == 0){
						for(int j = cl; j <= cr; j++)
							cnt[s[i][j]]++;
					}else{
						cnt[s[i][cl - 1]]--;
						cnt[s[i][cr]]++;					
					}
					ans += (r - l + 1) - cnt[a[q]];					
					if(q == n - 1){
						for(int j = cl; j <= cr; j++)
							cnt[s[i][j]]--;
					}
				}
				ans %= mod;
			}
		}	
		if(m > K){
			ans = ans * bp(2, m - K) % mod;
			ans = (ans + kek * bp(2, m - K)) % mod;
			sub(ans, kek);
			for(int i = 0; i < n; i++)
				if(a[i] > K)
					sub(ans, bp(2, m - a[i]));
		}
		for(int i = 0; i < n; i++)
			CNT[a[i]]--;
				
		printf("%d %lld\n", mn, ans);
		cerr << mn << ' ' << ans << endl;
		exit(0);
	}
}
