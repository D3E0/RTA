//============================================================================
//Name：牛客多校第二场 I Car
//https://www.nowcoder.com/acm/contest/140/I
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

int main() {
    int row[100005], column[100005];
    int n, m, x, y;
    memset(row, 0, sizeof(row));
    memset(column, 0, sizeof(column));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        row[x] = 1;
        column[y] = 1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
//		奇数
        if ((n % 2 != 0) && i == (n / 2 + 1)) {
            continue;
        }

        if (!row[i]) {
            ans++;
        }

        if (!column[i]) {
            ans++;
        }
    }
//		奇数，且为中心点
    if ((n % 2 != 0) && !row[n / 2 + 1] && !column[n / 2 + 1]) {
        ans += 1;
    }

    cout << ans << endl;

    return 0;
}