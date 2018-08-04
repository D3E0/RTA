//============================================================================
//Name：牛客多校第三场 A PACM Team DP 背包问题
//https://www.nowcoder.com/acm/contest/141/A
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
struct ss {
    int p, a, c, m, k;
} f[100];
int dp[37][37][37][37];
bool path[37][37][37][37][37];

int getint() {
    int res = 0, p = 1;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') p = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    n = getint();
    for (int i = 1; i <= n; i++) {
        f[i].p = getint();
        f[i].a = getint();
        f[i].c = getint();
        f[i].m = getint();
        f[i].k = getint();
    }
    int pp, aa, cc, mm;
    pp = getint();
    aa = getint();
    cc = getint();
    mm = getint();

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = pp; j >= 0; j--) {
            for (int k = aa; k >= 0; k--) {
                for (int x = cc; x >= 0; x--) {
                    for (int y = mm; y >= 0; y--) {
                        int a1 = j - f[i].p, a2 = k - f[i].a;
                        int a3 = x - f[i].c, a4 = y - f[i].m;
                        if (a1 >= 0 && a2 >= 0 && a3 >= 0 && a4 >= 0) {
                            int yy = dp[a1][a2][a3][a4];
                            if (dp[j][k][x][y] < yy + f[i].k) {
                                dp[j][k][x][y] = yy + f[i].k;
                                path[i][j][k][x][y] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    vector<int> ans;
    int a1 = pp, a2 = aa, a3 = cc, a4 = mm;
    for (int i = n; i >= 1; i--) {
        if (path[i][a1][a2][a3][a4]) {
            ans.push_back(i - 1);
            a1 -= f[i].p;
            a2 -= f[i].a;
            a3 -= f[i].c;
            a4 -= f[i].m;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0) {
            cout << ans[i];
        } else {
            cout << " " << ans[i];
        }
    }
    cout << endl;

    return 0;
}

