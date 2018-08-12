//============================================================================
//Name：牛客多校第八场 G Counting regions 多边形不重叠区域个数 欧拉定理
//============================================================================
/*
 * v - e + f = 2
 * v = C(n, 4) + n
 * e = n + (C(n, 2) - n) + 2 * C(n, 4)
 */
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

//快速幂取法 a^b%p
LL pow_mod(LL a, LL b, LL p) {
    LL ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

//费马小定理求a关于p的逆元 inv(a)
LL Fermat(LL a, LL p) {
    return pow_mod(a, p - 2, p);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    LL n;
    cin >> n;
    LL inv24 = Fermat(24, MOD), inv2 = Fermat(2, MOD);
//  ans = C(n, 4) + C(n, 2) - n + 1
    LL ans = n * (n - 1) % MOD * (n - 2) % MOD * (n - 3) % MOD * inv24 % MOD +
             n * (n - 1) % MOD * inv2 % MOD - n + 1 + MOD;
    cout << ans % MOD << endl;
    return 0;
}