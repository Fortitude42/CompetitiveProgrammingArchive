#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map = tree<T1, T2, std::less<T1>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;


#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

#ifdef SOL
double starttime;
#endif

void initialization() {
#ifdef SOL
    starttime = 1000. * clock() / CLOCKS_PER_SEC;
    if (useinout().fs.fs)
        freopen("input.txt", "r", stdin);
    if (useinout().fs.sc)
        freopen("output.txt", "w", stdout);
#else
    srand(__rdtsc());
    const string file = useinout().sc.fs;
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    } else
    if(useinout().sc.sc) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#endif
}

int solution();

void finish(int exitval) {
    fflush(stdout);
#ifdef SOL
    fprintf(stderr, "\n-----------------\nexit value: %d\ntime: %.3lf ms\n-----------------\n", exitval, 1000. * clock() / CLOCKS_PER_SEC - starttime);
#endif
}

int main() {
    initialization();
    finish(solution());
    return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1001000;

pair<pair<int, int>, int> pp[maxn];
int n;
int n2;

long double gk;
long double gb;

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    return a.fs.sc - gk * a.fs.fs < b.fs.sc - gk * b.fs.fs;
}

int check(long double k) {
    gk = k;
    sort(&pp[0], &pp[2 * n2], cmp);
    int bal = 0;
    for(int i = 0; i < n2; i++) {
        bal += pp[i].sc;
    }
    // cerr << bal << endl;
    gb = (pp[n2 - 1].fs.sc - gk * pp[n2 - 1].fs.fs + pp[n2].fs.sc - gk * pp[n2].fs.fs) / 2;
    // cerr << pp[n2 - 1].fs.sc - gk * pp[n2 - 1].fs.fs << endl;
    // cerr << pp[n2].fs.sc - gk * pp[n2].fs.fs << endl;
    // for(int i = 0; i < 2 * n2; i++) {
    //     cerr << pp[i].fs.fs << " " << pp[i].fs.sc << endl;
    // }
    // cerr << gb << endl;
    return bal;
}

void get_ans(long double k) {
    int ans = check(k);
    // fprintf(stderr, "%d\n", ans);
    // fprintf(stderr, "%.10lf\n", (double) gk);
    // fprintf(stderr, "%.10lf\n", (double) gb);
    long double x1 = 1e9, x2 = 0;
    long double y1 = gk * x1 + gb, y2 = gk * x2 + gb;
    long double A = y1 - y2;
    long double B = x2 - x1;
    long double C = x1 * y2 - x2 * y1;
    printf("Yes\n%10f\n%10f\n%10f\n", (double) A, (double) B, (double) C);
    exit(0);
}

int solution() {

    scanf("%d", &n);
    n2 = 2 * n;

    for (int i = 0; i < n2; i++) {
        scanf("%d%d", &pp[i].fs.fs, &pp[i].fs.sc);
        pp[i].sc = 1;
    }
    for (int i = n2; i < 2 * n2; i++) {
        scanf("%d%d", &pp[i].fs.fs, &pp[i].fs.sc);
        pp[i].sc = -1;
    }
    long double lk = -1e18, rk = 1e18;
    int mn = 1;
    int res = check(lk);
    // if (res == 0) get_ans(lk);
    if (res < 0) mn = -1;
    for (int i = 0; i < 100; i++) {
        long double mk = (lk + rk) / 2.0;
        if(check(mk) * mn >= 0) {
            lk = mk;
        } else {
            rk = mk;
        }
    }
    get_ans(lk);
    return 0;
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
    return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim