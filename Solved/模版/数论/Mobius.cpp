//============================================================================
//Name：莫比乌斯函数筛:基于线性素数筛
//若i为奇数个不同素数之积mob[i] = -1
//若i为偶数个不同素数之积mob[i] = 1
//若i有平方因子则mob[i] = 0。
//============================================================================
#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;
int prime[MAX], mu[MAX];
bool vis[MAX];

void mobius() {
    int cnt = 0;
    mu[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
}

int main() {
    mobius();
    for (int i = 1; i < MAX; i++) {
        cout << mu[i] << " ";
    }
    cout << endl;
    return 0;
}

