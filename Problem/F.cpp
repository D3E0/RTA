//============================================================================
//Name：杭电多校第五场 1002 Beautiful Now 交换次数 全排列枚举
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;
const int N = 105;
int arr[N][N];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "r", stdin);
//    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\std-out)", "w", stdout);
#endif
    int n, m, x, y;
    while (cin >> n >> m) {
        mm(arr, 0);
        rep(i, 1, m + 1) {
            cin >> x >> y;
            arr[x][y] = 1;
        }

        int cnt = 0;
        rep(i, 1, n + 1) {
            rep(j, i + 1, n + 1) {
                rep(q, j + 1, n + 1) {
                    rep(p, q + 1, n + 1) {
                        if (arr[i][j] && arr[i][q] && arr[i][p]) {
                            if (arr[j][p] && arr[j][q] && arr[q][p]) {
                                cnt++;
//                                printf("%d--%d--%d--%d\n", i, j, q, p);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}