//============================================================================
//Name：牛客多校第二场 A Run DP
//============================================================================
#include <iostream>;
#include <algorithm>;
#include <map>

using namespace std;

int main() {

    int n;
    int a[100005];//颜色的权值
    long long sum = 0;//总的权值
    map<int, int> m;//个数
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]] += i;
        sum += a[i];
    }

    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
    }
    long long ans = INT64_MIN;
    for (int i = 0; i < n; i++) {
        long long q = m[a[i]] * a[i];
        long long tmp = a[i] * n + sum - q;
        ans = min(tmp, ans);
    }

    printf("%lld", ans);

    return 0;
}