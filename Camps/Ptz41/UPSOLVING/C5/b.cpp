#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 123, mod = 998244353;

int n, a[N];
long long ANS, al[N], del[N];
vector <int> d[N];
vector <long long> dp[N];

long long bp(long long x, long long y){
	long long z = 1;
	while(y){
		if(y & 1)
			z = z * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return z;
}

int main(){
	al[0] = 1;
	for(int i = 1; i <= 100000; ++i)
		al[i] = al[i - 1] * 26 % mod, del[i] = bp(i, mod - 2);
	for(int i = 1; i <= 100000; ++i){
		for(int j = 1; j * j <= i; ++j){
			if(i % j == 0){
				d[i].push_back(j);
				if(j * j != i)
					d[i].push_back(i / j);
			}
		}
		sort(d[i].begin(), d[i].end());
		dp[i].resize(d[i].size());   		
		for(int j = 0; j < (int)d[i].size(); ++j){
			dp[i][j] = al[d[i][j]];
			for(int k = 0; k < j; ++k)
				if(d[i][j] % d[i][k] == 0)
					dp[i][j] = (dp[i][j] - dp[i][k] + mod) % mod;	
		}
		for(int j = 0; j < (int)d[i].size(); ++j)
			dp[i][j] = dp[i][j] * del[d[i][j]] % mod;
	}	
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i){
	    long long A = bp(26, a[i] + a[(i + 1) % n]);
	    long long B = 0;
		
		for(int j = 0; j < (int)d[a[i]].size(); ++j)
		for(int k = 0; k < (int)d[a[(i + 1) % n]].size(); ++k)
			B = (B + dp[a[i]][j] * dp[a[(i + 1) % n]][k] % mod * min(d[a[i]][j], d[a[(i + 1) % n]][k])) % mod;

		ANS += B * bp(A, mod - 2) % mod;
		ANS %= mod;
	}
	cout << ANS;
	return 0;
}