#include <bits/stdc++.h>
using namespace std;    
#define int long long

#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define se second
#define fi first
#define s second
#define f first

typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;   

const int N = ll(2e5) + 12, mod = ll(1e9) + 7, inf = 1e9; 

int C, P, S;

string pr[N], name[N];
map < string, int > id;
vector < pii > skills[N], roles[N];

int sz[N], d[N], s[N], b[N], r[N], order[N];
map < int, int > mxSkill;

int t[N], used[N], timer;
bool was[N];
vector < pii > g[N];

vector < pair < int, vector < pii > > > ans;


bool cmp(int i, int j) {
  return b[i] > b[j];
}

void solve(){
    cin >> C >> P;
    int MxS = 0, MxR = 0;
    for(int i = 1; i <= C; i++){
        cin >> name[i];
        cin >> sz[i];
        MxS = max(MxS, sz[i]);
        for(int j = 0; j < sz[i]; j++){
            string sk;
            int lvl;
            cin >> sk >> lvl;
      if (!id.count(sk))
        id[sk] = ++S;
            skills[i].pb({id[sk], lvl});
        }
    }
    for(int i = 1; i <= P; i++){
      order[i] = i;
        cin >> pr[i];
        cin >> d[i]  >> s[i] >> b[i] >> r[i];
        MxR = max(MxR, r[i]);
        for(int j = 0; j < r[i]; j++){
            string sk;               
            int lvl;
            cin >> sk >> lvl;
            assert(id.count(sk));
            roles[i].pb({id[sk], lvl});      
        }
    }

  for (int i = 1; i <= C; ++i)
    for (auto s : skills[i])
        g[s.f].pb({i, s.s});    
  

    ll score = 0;
  while (1) {
    bool found = 0;
    for (int i = 1; i <= P; ++i) {
      int j = order[i];
      if (was[j])
        continue;
      
      vector < pii > team;
      bool ok = 1;
      int mn = inf;
      int mxT = 0;
      mxSkill.clear();

      ++timer;
      for (auto r : roles[j]) {
        int sk = r.f, needL = r.s;
        pii mx = {-inf, -inf};
        for (auto c : g[sk]) {
          int ind = c.f, l = c.s;
          if (l < needL - 1 || used[ind] == timer || (l == needL - 1 && (!mxSkill.count(sk) || mxSkill[sk] < needL)))
            continue;
          mx = max(mx, {s[j] - max(0ll, t[ind] + d[j] - b[j]), ind});
        }

        if (mx.f <= 0) {
          ok = 0;
          break;
        }

        mn = min(mn, mx.f);

        team.pb({mx.s, sk});
        mxT = max(mxT, t[mx.s] + d[j]);
        used[mx.s] = timer;
		for (auto sk : skills[mx.s])
			mxSkill[sk.f] = max(mxSkill[sk.f], sk.s);
      }

      if (ok) {
        score += mn;
        found = 1;
        ans.pb(mp(j, team));
        for (int x = 0; x < sz(team); ++x) {
          int ind = team[x].f, sk = team[x].s;
          t[ind] = mxT;
          for (int z = 0; z < sz(g[sk]); ++z)
            if (g[sk][z].f == ind && g[sk][z].s <= roles[j][x].s) 
              ++g[sk][z].s;
        }
        was[j] = 1;
      }
    }

    if (!found)
      break;
  }

  cerr << score << endl;
  
  cout << sz(ans) << endl;
  for (auto p : ans) {
    cout << pr[p.f] << endl;
    set < int > q;
    for (auto x : p.s) 
      cout << name[x.f] << ' ';     
    cout << endl;
  }

}

main () {
    int T = 1;

    while(T--){
        solve();
    }

return 0;
}