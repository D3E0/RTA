//============================================================================
//Name：牛客多校第八场 G Counting regions 多边形不重叠区域个数 结论题
//============================================================================
#include<stdio.h>

#define LL long long
#define mod 998244353
LL  f[1000005] = {1, 1};

//快速幂取法 a^b%p
LL pow_mod(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

//费马小定理求a关于p的逆元 inv(a)
LL Fermat(LL a) {
    return pow_mod(a, mod - 2);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int n, i;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }

//  (n-2)*a(n-2) - 3*(2*n-1)*a(n-1) + (n+1)*a(n) = 0.
    for (i = 2; i <= n; i++) {
        f[i] = ((6 * i - 3) * f[i - 1] % mod - (i - 2) * f[i - 2] % mod + mod) % mod * Fermat(i + 1) % mod;
    }

    printf("%lld\n", f[n - 1] * 2 % mod);
}