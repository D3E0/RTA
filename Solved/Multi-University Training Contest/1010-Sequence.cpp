//============================================================================
//Name：杭电多校第七场 1010 Sequence 递推数列 矩阵快速幂 分块
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define mm(arr, val) memset(arr, val, sizeof(arr))

using namespace std;
typedef long long LL;

const int N = 3;
const int MOD = static_cast<const int>(1e9 + 7);

struct Mat {
    LL t[N][N];

    Mat() { mm(t, 0); }
};

//矩阵乘法
Mat operator*(Mat A, Mat B) {
    Mat C;
    rep(i, 0, N) {
        rep(j, 0, N) {
            rep(k, 0, N) C.t[i][j] += (1LL * A.t[i][k] * B.t[k][j]) % MOD;
        }
    }
    return C;
}

//矩阵快速幂
Mat pow_mod(Mat A, int b) {
    Mat B;
    B.t[0][0] = B.t[1][1] = B.t[2][2] = 1;
    while (b) {
        if (b & 1) B = B * A;
        A = A * A;
        b >>= 1;
    }
    return B;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, p, n;
        cin >> a >> b >> c >> d >> p >> n;
//      T.t[0][0] = a[i-1]  T.t[1][0] = a[i-2]
        Mat A, T;
        A.t[0][0] = d, A.t[0][1] = c, A.t[1][0] = 1, A.t[2][2] = 1;
        T.t[0][0] = b, T.t[1][0] = a, T.t[2][0] = 1;

        if (n == 1) {
            printf("%lld\n", T.t[1][0]);
            continue;
        }

        for (int i = 3; i <= n;) {
//          整除分块：按 p/i 进行分块，范围 [i...j]
//          j = p/(p/i), j 是满足 p / x = p / i 最大的 x
            int j = p < i ? n : min(n, p / (p / i));
            Mat W = A;
            W.t[0][2] = p / i;
            W = pow_mod(W, j - i + 1);
            T = W * T;
            i = j + 1;
        }
        printf("%lld\n", T.t[0][0] % MOD);
    }
    return 0;
}
