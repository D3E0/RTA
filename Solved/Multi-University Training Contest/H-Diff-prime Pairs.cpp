//============================================================================
//Name：牛客多校第三场 H Diff-prime Pairs 素数筛
//https://www.nowcoder.com/acm/contest/141/H
//============================================================================

#include<iostream>
#include<cstring>

using namespace std;

const int N = 700000;
bool notprime[int(1e7 + 10)];
int prime[N];

int main() {
    int cnt = 0, n;
    cin >> n;
    memset(notprime, 0, sizeof(notprime));
    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            prime[cnt++] = i;
            for (int j = i * i; j <= n; j += i) {
                notprime[j] = true;
            }
        }
    }

    long long ans = 0;

// 每一个素数 x 可以与前面的i个素数组成素数对，
// 并且 kx(kx <= n) 也可以与前面的i个素数组成素数对；
    for (int i = 0; prime[i] != 0; i++) {
        ans += n / prime[i] * i;
    }

    cout << ans * 2 << endl;

    return 0;
}

