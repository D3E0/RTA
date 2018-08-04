//============================================================================
//Name：杭电多校第三场 J Heritage of Skywalkert 暴力
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)

using namespace std;
typedef unsigned long long ULL;
unsigned x, y, z;

inline unsigned tang() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif
    int T, cnt = 0;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d %u %u %u", &n, &x, &y, &z);
        set<ULL> s;
        ULL ans = 0, tmp;
        rep(i, 0, n) {
            tmp = tang();
            if (tmp > *s.begin()) {
                s.insert(tmp);
                if (s.size() >= 100) {
                    s.erase(s.begin());
                }
            }
        }

        auto iter2 = s.end();

        for (auto iter = s.begin(); iter != iter2; iter++) {
            ULL x = *iter;
            auto iter3 = s.begin();
            for (; iter3 != iter2 && *iter != *iter3; iter3++) {
                ULL y = *iter3;
                if (x != y && __gcd(x, y) == 1) ans = max(ans, x * y);
            }
        }

        printf("Case #%d: %llu\n", ++cnt, ans);
    }
    return 0;
}