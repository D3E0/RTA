//============================================================================
//Name：牛客多校第七场 C Bit Compression 暴力深搜 剪枝
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 20;

int ans = 0, n, m;
int arr[N][1 << N];
char str[1 << N];

void dfs(int x) {
    if (!x) {
        if (arr[0][0]) ans++;
        return;
    }
    int end = m >> (n - x);
    rep(i, 0, 3) {
        int cnt = 0;
        for (int j = 0; j < end; j += 2) {
            if (i == 0) arr[x - 1][j / 2] = arr[x][j] | arr[x][j + 1];
            else if (i == 1) arr[x - 1][j / 2] = arr[x][j] & arr[x][j + 1];
            else if (i == 2) arr[x - 1][j / 2] = arr[x][j] ^ arr[x][j + 1];
            if (arr[x - 1][j / 2]) cnt++;
        }
//      全 0 剪枝
        if (cnt) dfs(x - 1);
    }
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    cin >> n >> str;
    m = 1 << n;
    rep(i, 0, m) arr[n][i] = str[i] - '0';
    dfs(n);
    cout << ans << endl;
    return 0;
}
