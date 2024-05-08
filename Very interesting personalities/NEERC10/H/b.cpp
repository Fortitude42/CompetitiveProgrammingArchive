#include <bits/stdc++.h>
using namespace std;

int Point(char c) {
    switch(c) {
        case 'A': return 12;
        case 'T': return 8;
        case 'J': return 9;
        case 'Q': return 10;
        case 'K': return 11;
        default: return c - '2';
    }
}

int Suit(char c) {
    switch(c) {
        case 'S': return 0;
        case 'C': return 13;
        case 'D': return 26;
        case 'H': return 39;
    }
    return 0;
}

#define rep(i, n) for(int i = 0; i < n; ++i)
int gcnt[110];
bool cmp(int a, int b) { return gcnt[a] != gcnt[b] ? gcnt[a] > gcnt[b] : a > b; }
struct Card {
    Card(){};
    int a, b, c, d, e;
    Card(int a,int b, int c, int d, int e) : a(a),b(b),c(c),d(d),e(e) {}
    bool straight() const {
        int ar[6]={0,a,b,c,d,e};
        rep(i,6)ar[i]%=13;
        sort(ar+1,ar+6);ar[0]=ar[5]-13;
        rep(i,2){
            bool ok = true;
            rep(k,5) if(ar[i+k]!=ar[i]+k) { ok = false; break; }
            if(ok) return true;
        }
        return false;
    }
    bool flush() const {
        int ar[5]={a,b,c,d,e};
        rep(i, 5) if(ar[i]/13 != ar[0]/13) return false;
        return true;
    }
    bool four() const {
        int ar[5]={a,b,c,d,e}, cnt[13]={};
        rep(i,5) cnt[ar[i]%13]++;
        rep(i,13) if(cnt[i]==4) return true;
        return false;
    }
    bool full() const {
        int ar[5]={a,b,c,d,e}, cnt[13]={}, k = 0, kk = 0;
        rep(i,5) cnt[ar[i]%13]++;
        int aa = 0, bb = 0;
        rep(i,13) if(cnt[i]==2) aa = 1; else if(cnt[i]==3) bb=1;
        return aa && bb;
    }
    bool three() const {
        int ar[5]={a,b,c,d,e}, cnt[13]={};
        rep(i,5) cnt[ar[i]%13]++;
        rep(i,13) if(cnt[i]==3) return true;
        return false;
    }
    bool two() const {
        int ar[5]={a,b,c,d,e}, k=0, cnt[13]={};
        rep(i,5) cnt[ar[i]%13]++;
        rep(i,13) if(cnt[i]==2) k++;
        return k==2;
    }
    bool one() const {
        int ar[5]={a,b,c,d,e}, cnt[13]={};
        rep(i,5) cnt[ar[i]%13]++;
        rep(i,13) if(cnt[i]==2) return true;
        return false;
    }
    int kind() const {
        if(straight() && flush()) return 0;
        if(four()) return 1;
        if(full()) return 2;
        if(flush()) return 3;
        if(straight()) return 4;
        if(three()) return 5;
        if(two()) return 6;
        if(one()) return 7;
        return 8;
    }
    bool operator<(const Card &r) const {
        int k1 = kind(), k2 = r.kind();
        int ar[]={a,b,c,d,e}, br[]={r.a,r.b,r.c,r.d,r.e};
        // rep(i,5) printf("%d ", ar[i]); puts("");
        if(k1!=k2) return k2<k1;
        rep(i, 5) ar[i]%=13, br[i]%=13;
        if(k1 == 0 || k1 == 4) {
            sort(ar,ar+5); sort(br,br+5);
            if(ar[4]==12&&ar[0]==0)ar[4]=-1;
            if(br[4]==12&&br[0]==0)br[4]=-1;
            sort(ar,ar+5); sort(br,br+5);
            // rep(i,5)printf("%d,%d\n",ar[i],br[i]);
            return ar[4] < br[4];
        }
        rep(i, 13) gcnt[i] = 0; rep(i, 5) gcnt[ar[i]]++; sort(ar, ar+5, cmp);
        rep(i, 13) gcnt[i] = 0; rep(i, 5) gcnt[br[i]]++; sort(br, br+5, cmp);
        // rep(i,5) printf("%d, %d\n", ar[i], br[i]);
        rep(i, 5) if(ar[i] < br[i]) return true; else if(ar[i]>br[i]) return false;
        return false;
    }
    void p() const { printf("{%d,%d,%d,%d,%d},",a,b,c,d,e);}
};
Card all[10010];

int main() {
    int sz = 0;
    
    rep(i,13)rep(j,i+1)rep(k,j+1)rep(l,k+1)rep(m,l+1) {
        if(m==i) continue;
        int a=m,b=l,c=k,d=j,e=i,sb,sc,sd,se;
        sb=sc=sd=se=0;
        sb=b==a?1:0,sc=c==b?1:0,sd=d==c?1:0,se=e==d?1:0;
        sc+=sb;sd+=sc;se+=sd;
        b+=sb*13; c+=sc*13; d+=sd*13; e+=se*13;
        all[sz++]=Card(a,b,c,d,e);
        if(!se)all[sz++]=Card(a,b,c,d,e+13);
    }
    // all[sz-1].p();
    sort(all, all + sz);
    // rep(kase, 50) {
        int a[5]; char tmp[4]; rep(i, 5) {
            scanf("%s", tmp);
            a[i] = Point(tmp[0]) + Suit(tmp[1]);
        }
        Card in = Card(a[0], a[1], a[2], a[3], a[4]);
        int ans = 0;
        while(all[ans] < in) ans++;
        ans++;
        // int real; scanf("%d", &real);
        // printf("%d: ", real);
        printf("%d\n", ans);
        cerr << ans << endl;
        // if(real != ans) break;
    // }
    return 0;
}
