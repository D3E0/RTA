//============================================================================
//Name：归并排序  求逆序对 逆序数
//给定一个序列a[],每次只允许交换相邻两个数,最少要交换多少次才能把它变成非递降序列.
//在一个排列中，若前面的数大于后面的数，那么它们就称为一个逆序，一个排列中逆序的总数即为逆序数
//============================================================================
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1005;

int a[N], tmp[N];
int ans;

void Merge(int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;
	while (i <= m && j <= r) {
		if (a[i] > a[j]) {
			tmp[k++] = a[j++];
			ans += m - i + 1;
		} else {
			tmp[k++] = a[i++];
		}
	}
	while (i <= m)
		tmp[k++] = a[i++];
	while (j <= r)
		tmp[k++] = a[j++];
	for (int i = l; i <= r; i++)
		a[i] = tmp[i];
}

void Merge_sort(int l, int r) {
	if (l < r) {
		int m = (l + r) >> 1;
		Merge_sort(l, m);
		Merge_sort(m + 1, r);
		Merge(l, m, r);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ans = 0;
	Merge_sort(0, n - 1);
	cout << "Scenario: " << ans << endl;
	return 0;
}
