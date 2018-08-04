//============================================================================
//Name：最大连续子序列和
//状态转移方程：sum[i] = max{sum[i-1]+a[i],a[i]}.
//============================================================================
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t, n;
	while (t--) {
		cin >> n;
		int a, sum = 0;
		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum = max(sum + a, a);
			ans = max(ans, sum);
		}

		cout << ans << endl;

	}

	return 0;
}

