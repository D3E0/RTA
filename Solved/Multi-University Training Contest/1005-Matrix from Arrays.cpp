//============================================================================
//Name：杭电多校第四场 1005 E. Matrix from Arrays 矩阵前缀和
//============================================================================
#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)

using namespace std;
typedef long long LL;

LL a[15], arr[100][100], sum[100][100];
LL n, len, q, x2, y2, x3, y3;

LL cal(LL x, LL y) {
    LL res = 0;
    res += (x / len) * (y / len) * sum[len - 1][len - 1];
    res += y / len * sum[x % len][len - 1];
    res += x / len * sum[len - 1][y % len];
    res += sum[x % len][y % len];
    return res;
}

int main() {
    IO;
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    LL t;
    cin >> t;
    while (t--) {

        cin >> n;
        len = 2 * n;
        for (LL i = 0; i < n; i++) {
            cin >> a[i];
        }

        LL cursor = 0;

        for (LL i = 0; i < 4 * n; ++i) {
            for (LL j = 0; j <= i; ++j) {
                arr[j][i - j] = a[cursor];
                cursor = (cursor + 1) % n;
            }
        }

        for (LL i = 0; i < 2 * n; i++) {
            for (LL j = 0; j < 2 * n; j++) {
                if (i == 0 && j == 0) sum[i][j] = arr[i][j];
                else if (i == 0) sum[i][j] = sum[i][j - 1] + arr[i][j];
                else if (j == 0) sum[i][j] = sum[i - 1][j] + arr[i][j];
                else sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
            }
        }

        cin >> q;
        for (LL i = 0; i < q; i++) {
            cin >> x2 >> y2 >> x3 >> y3;
            cout << cal(x2-1, y2-1) + cal(x3, y3) - cal(x3, y2-1) - cal(x2-1, y3) << endl;
        }
    }
    return 0;
}

