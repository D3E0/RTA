//============================================================================
//Name：最大上升子序列 LIS 动态规划 二分 nlogn poj3903
//============================================================================
#include<iostream>
#include<cstring>
using namespace std;
int a[100000], d[100000];

int BinSearch(int x, int low, int high) {
	int mid;
	while (low < high) {
		mid = (low + high) >> 1;
		if (d[mid] < x) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return high;
}

int main() {
	int n;
	while (cin >> n) {
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int len = 1;
		d[1] = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] > d[len]) {
				d[++len] = a[i];
			} else {
				d[BinSearch(a[i], 1, len)] = a[i];
			}
		}
		cout << len << endl;
	}
}
