//============================================================================
//Name：杭电多校第四场 1002 Harvest of Apples 组合数 莫队算法
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
//#define per(i, a, n) for (int i = n-1; i >= a; i--)

using namespace std;
typedef long long LL;

const int N = static_cast<const int>(1e5 + 7);
const int MOD = static_cast<const int>(1e9 + 7);
LL pos[N], n;
//Finv 阶乘的逆元  F 阶乘
LL Finv[N], F[N], ans[N];
struct ss {
    LL l, r, id;
} f[N];
//区间排序，左端点所在块内为第一关键字，右端点为第二关键字
bool cmp(ss p, ss q) {
    if (pos[p.l] == pos[q.l]) {
        return p.r < q.r;
    }
    return p.l < q.l;
}

LL qpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

LL comb(LL n, LL m) {
    if (n < 0 || m < 0 || m > n) return 0;
    if (m == 0 || m == n) return 1;
    return F[n] * Finv[n - m] % MOD * Finv[m] % MOD;
}

void init() {
    F[1] = 1;
    rep(i, 2, N) {
        F[i] = F[i - 1] * 1LL * i % MOD;
    }
    rep(i, 1, N) {
        Finv[i] = qpow(F[i], MOD - 2);
    }
//    预处理区间分块 将 N 个数分成 sqrt(N) 块
    int block = (int) sqrt(N);
    rep(i, 1, N) {
        pos[i] = (i - 1) / block;
    }
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    IO;
    init();
    cin >> n;
    rep(i, 0, n) {
        cin >> f[i].r >> f[i].l;
        f[i].id = i;
    }

    sort(f, f + n, cmp);

    LL l = 0, r = 1, res = 1;
    rep(i, 0, n) {
        while (r < f[i].r) {
            res = (2 * res - comb(r, l) + MOD) % MOD;
            r++;
        }
        while (r > f[i].r) {
            res = (res + comb(r - 1, l)) * Finv[2] % MOD;
            r--;
        }
        while (l < f[i].l) {
            res = (res + comb(r, l + 1)) % MOD;
            l++;
        }
        while (l > f[i].l) {
            res = (res - comb(r, l) + MOD) % MOD;
            l--;
        }
        ans[f[i].id] = res;
    }

    rep(i, 0, n) {
        cout << ans[i] << endl;
    }
    return 0;
}


