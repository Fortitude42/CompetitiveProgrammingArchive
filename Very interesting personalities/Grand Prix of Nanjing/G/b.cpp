#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const ll INF= 1LL<<52;
const int MAXN = 152;

vector<int> adj[MAXN];
int w[MAXN];
int dist[MAXN][MAXN];//distance
int nf[MAXN][MAXN];//num free, middle nodes not included :o
int sts[MAXN];//subtree size
int fh[MAXN][MAXN];//first hop
ll dp[MAXN][MAXN][MAXN][4];//index, left, right, whether left/right ends are taken 

void dfs(int o, int x,int p){
    sts[x]=1;
    for(int i:adj[x]){
        if(i==p)continue;
        dist[o][i]=dist[o][x]+1;
        fh[i][o]=x;
        dfs(o,i,x);
        sts[x]+=sts[i];
    }
}

void dfs2(int o, int x,int p){
    for(int i:adj[x]){
        if(i==p)continue;
        if(x==o){
            nf[o][i]=0;
        }
        else{
            nf[o][i]=nf[o][x]+sts[x]-sts[i]-1;
        }
        dfs2(o,i,x);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cin >> w[i];
        }
        if(n==1){
            int a,b;
            cin >> a >> b;
            cout << w[0] << '\n';
            continue;
        }
        for(int i=0;i<n;i++){
            int a,b;cin >> a>>b;
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<=n;i++){
            dfs(i,i,-1);
            dfs2(i,i,-1);
        }
        /*for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout << fh[i][j] << ' ';
            }cout << endl;
        }*/
        for(int a=0;a<n;a++)
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int l=0;l<4;l++){
                    dp[a][i][j][l]=-INF;
                }
            }
        }
        for(int i=0;i<=n;i++){
            for(int j:adj[i]){
                for(int k:adj[i]){
                    if(j==k)continue;
                    if(nf[j][k])dp[0][j][k][0]=0;
                    dp[0][j][k][1]=w[0];
                    dp[0][j][k][2]=w[0];
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int b=3;b>=0;b--){
                for(int j=0;j<=n;j++){
                    for(int k=0;k<=n;k++){
                        if(dist[j][k]<2)continue;
                        int np = dist[j][k];//number picked
                        if(!(b&1))np--;
                        if(!(b&2))np--;
                        dp[i][j][k][b]=-INF;
                        if(nf[j][k] + np >= i+1){
                            dp[i][j][k][b]=dp[i-1][j][k][b];//throw away edge i
                        }
                        if(b&1){								
                            dp[i][j][k][b] = max(dp[i][j][k][b], dp[i-1][j][k][b^1] + w[i]);//use w[i] on path
                        }
                        else{
                            dp[i][j][k][b] = max(dp[i][j][k][b], dp[i][fh[j][k]][k][b^1]);//go back to previous node?
                        }
                        if(b&2){
                            dp[i][j][k][b] = max(dp[i][j][k][b], dp[i-1][j][k][b^2] + w[i]);//use w[i] on path
                        }
                        else{

                            dp[i][j][k][b] = max(dp[i][j][k][b], dp[i][j][fh[k][j]][b^2]);//go back to previous node?
                        }

                    }
                }
            }
        }
        ll ans = 0;
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                ans= max(ans,dp[n-1][j][k][3]);
            }
        }


        cout << ans << '\n';
        for(int i=0;i<=n;i++)adj[i].clear();
    }
}