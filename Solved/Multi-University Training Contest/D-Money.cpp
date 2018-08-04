//============================================================================
//Name：牛客多校第二场 D Money DP || 贪心
//https://www.nowcoder.com/acm/contest/140/D
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        LL a[100005];

        memset(a, 0, sizeof(a));

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        LL sum = 0, cnt = 0;
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1]) {
                sum += a[i + 1] - a[i];
//				printf("a[i] = %d a[i+1] = %d\n", a[i], a[i+1]);
                if (!flag) {
                    cnt++;
                }
                flag = true;
            } else if (a[i] == a[i + 1]) {
//				do nothing 不能与上面合并
            } else {
                flag = false;
            }
        }
        cout << sum << " " << cnt * 2 << endl;
    }

    return 0;
}