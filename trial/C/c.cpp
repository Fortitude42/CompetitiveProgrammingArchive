#include <bits/stdc++.h>

using namespace std;
const int N = 1.2e6 + 11;

struct Person {
	string name, num;
	int bal;
};

bool cmp (Person a, Person b) {	
	return a.bal < b.bal;
}

int n;
Person a[N];



int main () {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].name >> a[i].num >> a[i].bal;

	sort(a, a + n, cmp);
	for (int i = 0; i < min(n, 100); ++i)
		if (a[i].bal < 0)
			cout << a[i].name << ' ' << a[i].num << ' ' << a[i].bal << endl;	
}   	