//============================================================================
//Name：牛客多校第七场 1005 GuGuFishtion 莫比乌斯反演 数论
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = a; i >= n; i--)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 1005;
const int MOD = 1000000007;

LL a[N], f[N][N];

LL F[N], Finv[N];

LL qpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    F[1] = 1;
    rep(i, 2, N) {
        F[i] = F[i - 1] * 1LL * i % MOD;
    }
    // inv(x!) = inv(x) * inv((x-1)!)  --->  inv(x!) * x = inv((x-1)!)
    Finv[N - 1] = qpow(F[N - 1], MOD - 2);
    per(i, N - 2, 1) {
        Finv[i] = Finv[N - 1] * (i + 1) % MOD;
    }
}

//comb(n, m) 就是 C(n, m)
LL comb(LL n, LL m) {
    if (n < 0 || m < 0 || m > n) return 0;
    if (m == 0 || m == n) return 1;
    return F[n] * Finv[n - m] % MOD * Finv[m] % MOD;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif

    init();
    int n, m;
    cin >> n >> m;

    rep(i, 1, n + 1) {
        cin >> a[i];
    }

    LL inv = qpow(100, MOD - 2);

    mm(f, 0);
    rep(i, 0, n + 1) {
        f[i][0] = 1;
    }

    rep(i, 1, n + 1) {
        int x = i - 1;
        rep(j, 1, m + 1) {
            LL tmp = 0;
            rep(k, 0, j + 1) {
                tmp += comb(j, k) * f[x][j - k] % MOD;
            }
            f[i][j] = 1LL * tmp * a[i] % MOD * inv % MOD;
        }
    }

    LL res = 0;
    rep(i, 1, n + 1) {
//        printf("for i = %d f1 = %lld f2 = %lld f3 = %lld\n", i, f[i][1], f[i][2], f[i][3]);
        res += f[i][m] - f[i - 1][m] * a[i] % MOD * inv % MOD;
    }
    cout << res % MOD << endl;

    return 0;
}
