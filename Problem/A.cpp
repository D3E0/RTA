//============================================================================
//Name：KM 带权二分图最佳匹配
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;

const int N = 105;
const int MAX = INT_MAX;
const int MIN = INT_MIN;
int n, m, minz, ans, arr[N][N];
int cx[N], cy[N], wx[N], wy[N];
bool visx[N], visy[N];

//匈牙利算法找增广路径
bool dfs(int s) {
    visx[s] = 1;
    for (int i = 1; i <= m; i++)
        if (!visy[i]) {
            int t = wx[s] + wy[i] - arr[s][i];
//            相等子图中寻找增广路
            if (t == 0) {
                printf("(%d -- %d -- %d)\n", s, i, cy[i]);
                visy[i] = 1;
                if (cy[i] == 0 || dfs(cy[i])) {
                    cx[s] = i, cy[i] = s;
                    return true;
                }
            } else if (t > 0 && t < minz) {
                //取最小的不在相等子图中的常数 d
                minz = t;
            }
        }
    return false;
}

void km() {
    memset(cx, 0, sizeof(cx));
    memset(cy, 0, sizeof(cy));
    memset(wy, 0, sizeof(wy));
    for (int i = 1; i <= n; i++) {
        printf("%d start: \n", i);
        while (1) {
            minz = MAX;
            memset(visx, 0, sizeof visx);
            memset(visy, 0, sizeof visy);
            if (dfs(i))break;

            //将增广轨中 X 部的点的顶标减去 minz
            for (int j = 1; j <= n; j++)
                if (visx[j]) wx[j] -= minz;
            //将增广轨中 Y 部的点的顶标加上 minz
            for (int j = 1; j <= m; j++)
                if (visy[j]) wy[j] += minz;

            printf("min[%d] = %d\n", i, minz);
            rep(j, 1, n + 1) {
                printf("wx[%d] = %d  wy[%d] = %d\n", j, wx[j], j, wy[j]);
            }
        }
    }

    ans = 0;
    for (int i = 1; i <= m; i++)
        if (cy[i]) ans += arr[cy[i]][i];
}

int main() {
    IO;
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    cin >> n >> m;

    rep(i, 1, n + 1) {
        wx[i] = MIN;
        rep(j, 1, m + 1) {
            cin >> arr[i][j];
            wx[i] = max(wx[i], arr[i][j]);
        }
    }

    rep(i, 1, n + 1) {
        printf("wx[%d] = %d\n", i, wx[i]);
    }

    km();

    cout << ans << endl;


    return 0;
}

