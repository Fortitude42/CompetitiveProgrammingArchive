#include<bits/stdc++.h>
using namespace std;
const int N=110, mod=998244353;
int n, x[N], y[N];
long long dp[N];
bool vis[N], del[N];
vector<int> g[N], tmp;
int dis(int i, int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int dfs(int x){
	vis[x]=1;
	tmp.push_back(x);
	int sum=g[x].size();
	for (int i=0; i<g[x].size(); i++){
		int y=g[x][i];
		if (!vis[y]){
			sum+=dfs(y);
		}
	}
	return sum;
}
void solve(){
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x[i]>>y[i];
	}
	for (int i=1; i<=n; i++){
		int minDis=1e9;
		for (int j=1; j<=n; j++){
			if (i==j) continue;
			minDis=min(minDis, dis(i,j));
		}
		for (int j=1; j<=n; j++){
			if (minDis==dis(i,j)){
				g[i].push_back(j);
			}
		}
	}
	dp[0]=1;
	for (int i=1; i<=n; i++){
		if (!del[i]){
			tmp.clear();
			memset(vis, 0, sizeof(vis));
			int s=dfs(i), m=tmp.size();
			if ((m-1)*m==s){
				for (int j=n; j>=m-1; j--) dp[j]=(dp[j]+dp[j-(m-1)])%mod;
				for (int j=0; j<m; j++) del[tmp[j]]=1;
			}
		}
	}
	long long ans=0, fac=1;
	for (int i=n; i>=0; i--){
		ans=(ans+fac*dp[i]%mod)%mod;
		fac=fac*i%mod;
	}
	cout<<ans<<endl;
}
int main(){
	solve();
}