//============================================================================
//Name：杭电多校第三场 1001  Ascending Rating 滑窗最大值 双端队列
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)

using namespace std;

const int N = 1e7 + 10;
int a[N], cnt[N], rate[N];

int main() {

#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        deque<int> dq;
        int n, m, k, p, q, r, mod;

        scanf("%d %d %d %d %d %d %d", &n, &m, &k, &p, &q, &r, &mod);
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = k + 1; i <= n; i++) {
            a[i] = (1LL * p * a[i - 1] + 1LL * q * i + r) % mod;
        }
//        从后往前扫，队列大小即为最大值变化次数
        for (int i = n; i >= 1; i--) {
//            删除队尾元素，维护最值
            while (!dq.empty() && a[i] > a[dq.back()]) {
                dq.pop_back();
            }
//            插入队尾
            dq.push_back(i);
//            删除过时元素
            while (!dq.empty() && dq.front() >= i + m) {
                dq.pop_front();
            }
            rate[i] = dq.front();
            cnt[i] = dq.size();
        }

        long long x = 0, y = 0;

        for (int i = 1; i <= n - m + 1; i++) {
            x += (a[rate[i]] ^ i);
            y += ((cnt[i]) ^ i);
        }

        printf("%lld %lld\n", x, y);
    }
    return 0;
}
