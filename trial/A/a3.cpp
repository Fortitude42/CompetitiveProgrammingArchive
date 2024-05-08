#include <iostream>

using namespace std;


int n;
int main () {
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < n; ++j)
			if (i == j)
				cout << "x ";
			else	
				cout << a[i][j] << ' ';

}


