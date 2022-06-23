#include<bits/stdc++.h>
using namespace std;

double f(double x) {
	return 0.05 * pow(x, 5) - 0.4 * pow(x, 4) + 0.3 * pow(x, 3) + 2 * pow(x, 2) + 2;
}

double minPoint(double left, double right) {
	for (int i = 0; i < 200; i++) {
		double m1 = left + (right - left) / 3;
		double m2 = right - (right - left) / 3;
		double f1 = f(m1);
		double f2 = f(m2);

		if (f1 > f2)
			left = m1;
		else
			right = m2;
	}
	return f(left);
}

int findMax(vector<int> &arr) {
	int n = arr.size();
	int left = 0;
	int right = n - 1;

	// for (right-left)>=2
	// mid1 & mid2 pints end points of boundry
	// and loop will become infinite

	while (right - left >= 3) {
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		int f1 = arr[mid1];
		int f2 = arr[mid2];

		if (f1 < f2)
			left = mid1;
		else
			right = mid2;
	}

	int mx = INT_MIN;
	for (int i = left; i <= right; i++) {
		mx = max(mx, arr[i]);
	}
	return mx;
}

int main() {
	// cout<<minPoint(-1,2);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << findMax(arr);

	return 0;
}