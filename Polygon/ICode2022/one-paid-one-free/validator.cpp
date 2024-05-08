#include "testlib.h"
#include <bits/stdc++.h>
 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
using namespace std;
 
typedef long long ll;
 
const int N = (int)100;
const int M = (int)2000;
 
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	string g = validator.group();
	int n = inf.readInt(1, N, "n");
	inf.readEoln();
	
	for (int i = 1; i <= n; i++) {
		inf.readInt(1, M, "ci");
		if (i < n)
			inf.readSpace();
	}
	inf.readEoln();
    inf.readEof();
 
	return 0;
}