#include <bits/stdc++.h>
  
#define f first
#define s second
#define pb push_back
#define mp make_pair
  
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
  
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
  
int n, q;
ll dp[50][50];
ld DP[50];
map<int, int> was;
ld ans;
ll p[N];
ld f(int x){
    int y = x;
    int cnt = 0;
    while(y != 1 && !was[y])
        y /= 2, cnt++;
    if(was[y]){
        ld res = 1;
        for(int i = 1; i < cnt; i++)
            res *= 0.5;
        return 1 - res;     
    }
    return 1;
}
int main()
{           
    DP[0] = 1;
    dp[1][1] = 2;
    for(int i = 1; i <= 30; i++){
        ll s = 0;
        for(int j = 0; j <= 30; j++)
            s += dp[i][j], dp[i + 1][j + 1] += dp[i][j], DP[i] += (ld)dp[i][j] / (j + 1) ;
        DP[i] /= (1 << i);
        dp[i + 1][1] = s;
    }
    scanf("%d%d", &n, &q);
    while(q--){
        int a, b, x;
        scanf("%d%d", &a, &b);
        a = n - a;
        x = (1 << a) + b - 1;
        ans += f(x);
        was[x] = 1;
    }
    p[1] = 0;   
    for(int i = 2; i < (1 << n); i++){
        if(was[i])
            continue;
        if(was[i / 2])
            p[i] = 0;
        else
            p[i] = p[i / 2] + 1;
    }
    /*
    cerr << ans << endl;
    for(int i = 1; i < (1 << n); i++)
        cerr << p[i] << " ";
    cerr << endl;
    for(int i = 1; i < (1 << n); i++)
        cerr << f(i) << " ";
    cerr << endl;
    */
    for(int i = 1; i < (1 << n); i++)
        ans += DP[p[i]] * f(i);
    printf("%.12f", (double)ans);
}