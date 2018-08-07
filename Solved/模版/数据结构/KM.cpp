//============================================================================
//Name：KM 带权二分图最佳匹配
//https://blog.csdn.net/hello_sheep/article/details/77150497?locationNum=6&fps=1
//https://blog.csdn.net/sixdaycoder/article/details/47720471
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;

const int N = 105;
const int MAX = INT_MAX;
const int MIN = INT_MIN;
int n, m, minz, arr[N][N];
int cy[N], wx[N], wy[N];
bool visx[N], visy[N];

bool dfs(int s) {
    visx[s] = true;
    rep(i, 1, m + 1) {
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
        return false;
    }
}

int km() {
    mm(cy, 0), mm(wy, 0);
    rep(i, 1, n + 1) {
        while (1) {
            minz = MAX;
            mm(visx, 0), mm(visy, 0);
            if (dfs(i))break;
            rep(j, 1, n + 1) {
                if (visx[j]) wx[j] -= minz;
            }
            rep(j, 1, m + 1) {
                if (visy[j]) wy[j] += minz;
            }
        }
    }

    int ans = 0;
    rep(i, 1, m + 1) ans += arr[cy[i]][i];
    return ans;
}

int main() {
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

    cout << km() << endl;

    return 0;
}

