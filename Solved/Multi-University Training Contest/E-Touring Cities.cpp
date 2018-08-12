//============================================================================
//Name：牛客多校第八场 E Touring Cities 构造
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 105;

int arr[N][N];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t;
    cin >> t;
    mm(arr, 0);
    rep(i, 1, N) {
        for (int j = i % 2; j < N; j += 2) arr[i][j] = 1;
    }
    while (t--) {
        int n, m, k, x1, y1, x2, y2;
        cin >> n >> m >> k;
        int ans = n * m + 1;
        rep(i, 0, k) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (arr[x1][y1] && arr[x2][y2] && (x1 != x2 || y1 != y2)) ans = n * m;
        }
        if (n % 2 == 0 || m % 2 == 0) ans = n * m;
        cout << ans << endl;
    }
    return 0;
}
