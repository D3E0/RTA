//============================================================================
//Name：杭电多校第三场 1007  Chiaki Sequence Revisited 找规律 二分
//============================================================================

#include<bits/stdc++.h>

using namespace std;

namespace io {
    const int L = (1 << 21) + 1;
    char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, st[55];
    int f, tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)

    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }

    inline void putc(char x) {
        *oS++ = x;
        if (oS == oT) flush();
    }

    template<class I>
    inline void gi(I &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
        x *= f;
    }

    template<class I>
    inline void print(I x) {
        if (!x) putc('0');
        if (x < 0) putc('-'), x = -x;
        while (x) st[++tp] = x % 10 + '0', x /= 10;
        while (tp) putc(st[tp--]);
    }

    inline void gs(char *s, int &l) {
        for (c = gc(); c < 'a' || c > 'z'; c = gc());
        for (l = 0; c <= 'z' && c >= 'a'; c = gc()) s[l++] = c;
        s[l] = 0;
    }

    inline void ps(const char *s) { for (int i = 0, n = strlen(s); i < n; i++) putc(s[i]); }

    struct IOFLUSHER {
        ~IOFLUSHER() { flush(); }
    } _ioflusher_;
};

typedef long long LL;
LL tmp[65], n;
const LL mod = 1e9 + 7;
const LL inv2 = 500000004;

inline bool check(LL mid) {
    LL sum = mid + 1;
//  1---i 中因子 2 的个数
    for (int j = 1; j <= 60; j++) {
        sum += mid / tmp[j];
        if (sum >= n) {
            return true;
        }
    }
    return false;
}


int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    tmp[0] = 1;
    for (int i = 1; i <= 60; i++) {
        tmp[i] = tmp[i - 1] * 2;
    }
    int t;
    io::gi(t);
    while (t--) {
        io::gi(n);
//    给定一个 n，因为 a[i] 是有序的,(a[i] = 1...n)，所以可以通过二分得到 a[n]；求下界
//    Condition：n <= 最后一个 mid 的出现的位置 x;
        LL high = min(n, n / 2 + 30), low = max(1LL, n / 2 - 30), mid;
        while (low < high) {
            mid = (high + low) >> 1;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

//      a[n] = low    a[x] = low-1   ans = a[1]...a[x]
        LL ans = 1, val = low - 1, cnt;
        for (int i = 0; i <= 60; i++) {
            if (tmp[i] > val) break;
            cnt = (val / tmp[i]) % mod;
//          等差数列求和 化简
            ans += (tmp[i] % mod * (cnt + 1) % mod * cnt % mod * inv2 % mod);
        }

//      x = sum
        LL sum = val + 1;
        for (int j = 1; j <= 60; j++) {
            sum += val / tmp[j];
        }

        ans += ((n - sum) * low);

        io::print(ans % mod);
        io::putc('\n');
    }


    return 0;
}

/*
    1
    2 2
    3
    4 4 4
    5
    6 6
    7
    8 8 8 8
    f[i] = (i 出现的次数) = (i 中因子 2 的个数 + 1)；
    最后一个 i 出现的位置 x = f[1] + f[2] + .. + f[i] = 1---i 中因子 2 的个数 + i
    for (int i = 1; i <= 10; i++) {
        int sum = i + 1;
        1---i 中因子 2 的个数  求法同n! 阶乘 0 的个数
        for (int j = 1; j <= 62; j++) {
            sum += i / pow(2, j);
        }
    }

    n! 阶乘 0 的个数 == n! 中因子 5 的个数 == n / (5 ^ i) i = 1,2,3....求和
    for (int j = 1; j <= 10; j++) {
        sum += n / pow(5, j);
    }

    while (n >= 5) {
        ans += n / 5;
        n /= 5;
    }

 */