//============================================================================
//Name：01背包
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000;

int n, m, w[N], v[N];

int f1() {
	//状态压缩
	int dp[N];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[m];
}

int f2() {
	//原始dp
	int dp[N][N];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= w[i]; j--) {
			dp[i - 1][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	return dp[n][m];
}

int main() {

	while (cin >> n >> m) {

		memset(w, 0, sizeof(w));
		memset(v, 0, sizeof(v));

		for (int i = 1; i <= n; i++) {
			cin >> w[i] >> v[i];
		}

		cout<<f2()<<" "<<f1()<<endl;

	}

	return 0;
}

