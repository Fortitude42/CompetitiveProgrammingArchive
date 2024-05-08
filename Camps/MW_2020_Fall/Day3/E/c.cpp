#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

map < string, int > id;
string s[105], t;

void f (int a, string t) {
	id[t] = a;
	s[a] = t;
}

void precalc () {        
	f(0, "zero");
	f(1, "one");
	f(2, "two");
	f(3, "three");
	f(4, "four");
	f(5, "five");
	f(6, "six");
	f(7, "seven");
	f(8, "eight");
	f(9, "nine");
	f(10, "ten");
	f(11, "eleven");
	f(12, "twelve");
	f(13, "thirteen");
	f(14, "fourteen");
	f(15, "fifteen");
	f(16, "sixteen");
	f(17, "seventeen");
	f(18, "eighteen");
	f(19, "nineteen");
	f(20, "twenty");
	f(30, "thirty");
	f(40, "forty");
	f(50, "fifty");
	f(60, "sixty");
	f(70, "seventy");
	f(80, "eighty");
	f(90, "ninety");

	for (int x = 20; x < 100; x += 10)
		for (int y = 1; y < 10; ++y)
			f(x + y, s[x] + " " + s[y]);
}

string toString (int x) {
	if (!x) 
		return "0";
	string res = "";
	while (x) {
		res += (char)(x % 10 + '0');
		x /= 10;
	}

	reverse(all(res));
	return res;
}

int l, k;
bool flag, stop;
string cur;

void End () {
	for (int i = 0; i < l; ++i){
		cout << cur;
		if (i < l - 1)
			cout << endl;
	}
	exit(0);
}

void read () {
	if (!(cin >> t)) 
	    stop = 1;	

	if (t.back() == '.')
		t.ppb();

	assert(sz(t) < 5 || t.substr(0, 5) != "space");
}

int getNumber () {
	string tt = t;

	read();
	int x = id[tt];

	if (id.count(tt + " " + t)) {
		x = id[tt + " " + t];
		read();
	}

	return x;
}

string getString () {
	if (t[0] == t.back())
		return t.substr(1, sz(t) - 2);
		             	
	char c = t[0];

	string res = t.substr(1, sz(t) - 1);
	while (1) {
		read();
		res += t;

		if (t.back() == c) {
			res.ppb();
			break;
		}
	}

	return res;
}

void add (string s) {
	if (sz(cur) && isdigit(cur.back()))
		cur += " ";
	cur += s;		
}

main () {
	precalc();
	cin >> t;
	while (1) {
		if (stop)
			End();

//		cerr << t << endl;
		if (t == "contain" || t == "contains") {
		    read();
			continue;                           
		}

		if (t == "followed") {
			cin >> t;
			assert(t == "by");
			read();
			continue;
		}

		if (t == "The") {
			read();
		    if (flag) {
		    	for (int i = 1; i <= l; ++i)
		    		cout << cur << endl;
		    }

			l = k = 0;
			cur = "";
			
			continue;    
		}

		flag = 1;

		if (t == "first") {
			l = 1;
			read();
			read();
			continue;
		}

		if (t == "next") {
			read();
			if (t == "line") {
				l = 1;
			} else 
				l = getNumber();
			read();
			continue;
		}
		
		if (t == "is" || t == "are") {
			read();
			assert(t == "empty");
			read();
			continue;
		}
		
		if (t == "number")  {
			read();
			int x = getNumber();
			add(toString(x));
			continue;
		}

		if (t == "string") {
			read();
			string tt = getString();
			add(tt);
			read();
			continue;
		}

		if (id.count(t)) {			
			k = getNumber();
			assert(t == "numbers" || t == "strings");
			if (t == "numbers") {
				read();
				int x = getNumber();
//				cerr << t << ' ' << x << endl;
				while (k--) 
					add(toString(x));
			} else {
				read();
				string tt = getString();
				while (k--) 
					add(tt);				
				read();
			}
			continue;
		} 

		assert(0);
	}

}