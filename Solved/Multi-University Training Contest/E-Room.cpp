//============================================================================
//Name：牛客多校第五场 E Room 带权二分图最佳匹配 KM
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;

const int N = 205;
const int MAX = INT_MAX;
const int MIN = INT_MIN;
int n, minz, arr[N][N];
int cy[N], wx[N], wy[N];
bool visx[N], visy[N];

bool dfs(int s) {
    visx[s] = true;
    rep(i, 1, n + 1) {
        if (!visy[i]) {
            int t = wx[s] + wy[i] - arr[s][i];
            if (!t) {
                visy[i] = true;
                if (!cy[i] || dfs(cy[i])) {
                    cy[i] = s;
                    return true;
                }
            } else if (t > 0 && t < minz) {
                minz = t;
            }
        }
    }
    return false;
}

int km() {
    mm(cy, 0), mm(wy, 0);
    rep(i, 1, n + 1) {
        while (true) {
            minz = MAX;
            mm(visx, 0), mm(visy, 0);
            if (dfs(i))break;
            rep(j, 1, n + 1) {
                if (visx[j]) wx[j] -= minz;
                if (visy[j]) wy[j] += minz;
            }
        }
    }
    int ans = 0;
    rep(i, 1, n + 1) ans += arr[cy[i]][i];
    return ans;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int a[N][5], b[N][5];
    cin >> n;

    rep(i, 0, n) {
        rep(j, 0, 4) cin >> a[i][j];
    }
    rep(i, 0, n) {
        rep(j, 0, 4) cin >> b[i][j];
    }
    mm(wx, 0);
    rep(i, 0, n) {
        rep(j, 0, n) {
            int cnt = 0;
            rep(k, 0, 4) {
                rep(p, 0, 4) {
                    if (a[i][k] == b[j][p]) cnt++;
                }
            }
            arr[i + 1][j + 1] = cnt;
            wx[i + 1] = max(wx[i + 1], cnt);
        }
    }

    cout << 4 * n - km() << endl;
    return 0;
}

