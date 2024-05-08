#include <bits/stdc++.h>

using namespace std;

int find_second_smallest(int n, int* arr) {
	int first = 0, second;
	for (int i = 1;	i < n; ++i)
		if (arr[i] < arr[first]) {
			second = first;
			first = i;
		} else if (arr[i] < arr[second])
			second = i;

	return arr[second];
}

int main() {
	int n = 6;
	int arr[] = {195, 180, 175, 163, 193, 190};
	cout << "second smallest element: " << find_second_smallest(n, arr) << '\n';
	return 0;
}