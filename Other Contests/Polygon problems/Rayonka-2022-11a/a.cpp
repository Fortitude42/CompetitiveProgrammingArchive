#include <bits/stdc++.h>                                           
 
using namespace std;

int a1, b1, c1, a2, b2, c2;
 

int main () {
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	cout << min({max(a1, b2), max(a1, c2), max(b1, a2), max(b1, c2), max(c1, a2), max(c1, b2)});
	return 0;
}