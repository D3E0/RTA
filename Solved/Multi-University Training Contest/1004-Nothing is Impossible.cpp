//============================================================================
//Name：杭电多校第四场 1004 Nothing is Impossible 贪心
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)

using namespace std;

typedef long long LL;

int main() {

    int t;
    cin >> t;
    while (t--) {
        LL n, m, x, muti = 1, cnt = 0, b[1005];
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> x >> b[i];
        }

        sort(b, b + n);

        for (int i = 0; i < n; i++) {
            muti *= (1 + b[i]);
            if (muti > m) {
                break;
            }
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
