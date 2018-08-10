//============================================================================
//Name：牛客多校第七场 J Sudoku Subrectangles  矩阵扫描
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define mm(arr, val) memset(arr, val, sizeof(arr))
#define pb push_back

using namespace std;
typedef long long LL;

const int N = 1005, M = 130;
char str[N][N];
int gor[N][N], god[N][N], tmp[N];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> str[i];
    }
//go right 向右最远能到达
    rep(i, 0, n) {
        rep(j, 0, M) tmp[j] = m;
        gor[i][m] = m;
        per(j, m - 1, 0) {
            gor[i][j] = min(tmp[str[i][j]], gor[i][j + 1]);
            tmp[str[i][j]] = j;
        }
    }
//go down  向下最远能到达
    rep(j, 0, m) {
        rep(i, 0, M) tmp[i] = n;
        god[n][j] = n;
        per(i, n - 1, 0) {
            god[i][j] = min(tmp[str[i][j]], god[i + 1][j]);
            tmp[str[i][j]] = i;
        }
    }

    LL ans = 0;

    rep(i, 0, n) {
        rep(j, 0, m) {
//          b 下边界   r 右边界
            int b = god[i][j], r = gor[i][j] - 1;;
//          tmp[k] 下边界，在 [j, gor[i][j]-1] 上单调递减
            rep(k, j, gor[i][j]) {
                b = min(b, god[i][k]);
                tmp[k] = b;
            }
            rep(k, i, god[i][j]) {
                r = min(r, gor[k][j] - 1);
                while (tmp[r] <= k) r--;
                ans += r - j + 1;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}