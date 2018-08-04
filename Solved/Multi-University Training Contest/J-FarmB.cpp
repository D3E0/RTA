//============================================================================
//Name：牛客多校第二场 J Farm 二维树状数组 随机化解
//https://www.nowcoder.com/acm/contest/140/J
//============================================================================
#include<cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
const LL N = 1e6 + 100;
vector<LL> d[N];
vector<LL> a[N];

LL n, m, t;

//树状数组维护二维差分
LL lowbit(LL x) {
    return x & -x;
}

//a[x][y] += p
void update(LL x, LL y, LL p) {
    while (x <= n) {
        LL tmp = y;
        while (tmp <= m) {
            d[x][tmp] += p;
            tmp += lowbit(tmp);
        }
        x += lowbit(x);
    }
}

//return a[x][y]
LL sum(LL x, LL y) {
    LL sum = 0;
    while (x) {
        LL tmp = y;
        while (tmp) {
            sum += d[x][tmp];
            tmp -= lowbit(tmp);
        }
        x -= lowbit(x);
    }
    return sum;
}

//a[x1][y1] ... a[x2][y2] += p
void update_range(LL x1, LL y1, LL x2, LL y2, LL p) {
    update(x1, y1, p);
    update(x1, y2 + 1, -p);
    update(x2 + 1, y1, -p);
    update(x2 + 1, y2 + 1, p);
//	printf("(%d, %d) (%d, %d) %d\n", x1, y1, x2, y2, p);
}

inline LL rrand() { return (1LL * rand() << 15) + rand(); }

int main() {

    cin >> n >> m >> t;

    srand(233);
    vector<LL> r(n * m + 10);

    for (LL i = 1; i <= n * m; i++) {
        r[i] = rrand();
    }

    for (LL i = 1; i <= n; i++) {
        d[i].resize(m + 10);
        a[i].resize(m + 10);
    }

    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    LL x1, y1, x2, y2, k;
    for (LL i = 0; i < t; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        update_range(x1, y1, x2, y2, r[k]);
    }

    LL ans = 0;

    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= m; j++) {
            LL addtion = sum(i, j);
//			cout<<addtion<<" ";
            if (addtion % r[a[i][j]] != 0) {
//				printf("(%d, %d) \n",i, j);
                ans++;
            }
        }
//		cout<<endl;
    }

    cout << ans << endl;

    return 0;
}