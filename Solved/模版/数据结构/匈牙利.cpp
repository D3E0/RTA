//============================================================================
//Name：匈牙利算法 二分图最大匹配
//============================================================================
#include<bits/stdc++.h>

#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;

const int N = 105;
int n, m, arr[N][N], cx[N], cy[N];
bool vis[N];

bool dfs(int v) {
    rep(u, 1, m + 1) {
        if (arr[v][u] && !vis[u]) {
            vis[u] = 1;
            if (!cy[u] || dfs(cy[u])) {
                cx[v] = u, cy[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int hungarian() {
    mm(cx, 0), mm(cy, 0);
    int ans = 0;
    rep(v, 1, n + 1) {
        if (!cx[v]) {
            mm(vis, 0);
            ans += dfs(v);
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            cin >> arr[i][j];
        }
    }
    cout << hungarian() << endl;
    return 0;
}

