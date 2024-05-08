#include <bits/stdc++.h>                                           
using namespace std;
 
int x, y, z;
int main () {
	cin >> x >> y >> z;
	int a = sqrt(x * 1ll * z / y);
	int b = x / a;
	int c = y / b;
	cout << a << ' ' << b << ' ' << c;
}