#include "testlib.h"
#include <bits/stdc++.h>                                           
 
using namespace std;
 
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
 
const int N = 2e5;
const int M = N + 11;
 
int n, m; 

 
int main (int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	n = opt<int>(1);
	m = opt<int>(2);
	cout << n << '\n';
	for (int i = 0; i < n; ++i) {
		cout << rnd.next(1, m);
		if (i < n - 1)
			cout << ' ';
	}
	cout << '\n';
}
    
