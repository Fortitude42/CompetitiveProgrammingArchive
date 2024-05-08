#include <bits/stdc++.h>                                           
 
using namespace std;

int getRand() {
	int res = 0;
	for (int i = 0; i < 30; ++i)
		if (rand() & 1)
			res += (1 << i);

	return res;
}
const int inf = 1e9;
 

int main () {
	srand(time(0));
	for (int i = 0; i < 6; ++i) {
		if (i == 3)
			cout << endl;
		cout << getRand() % inf + 1;
		if (i % 3 != 2)
			cout << ' ';
	}
	return 0;
}