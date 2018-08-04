//============================================================================
//Name：牛客多校第二场 A Run DP
//https://www.nowcoder.com/acm/contest/140/A
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MOD = 1000000007;

int main() {
    int k, q;
    int sum[100005], dp[100005][2];

    cin >> q >> k;

    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i = 1; i <= 100003; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
        if (i >= k) {
            dp[i][1] = dp[i - k][0];
        }
        sum[i] = (sum[i - 1] + dp[i][1] + dp[i][0]) % mod;
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << (sum[r] - sum[l - 1] + mod) % mod << endl;
    }
    return 0;
}