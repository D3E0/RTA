#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int sum[26][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, cnt = 0;
    string str;
    cin >> t;
    while (t--) {
        memset(sum, 0, sizeof(sum));
        int n, q;
        cin >> n >> q >> str;
        for (int j = 1; j <= str.length(); ++j) {
            int index = str[j - 1] - 'A';
            for (int k = 0; k < 26; ++k) {
                if (k == index) sum[k][j] = sum[k][j - 1] + 1;
                else sum[k][j] = sum[k][j - 1];
            }
        }

        cout << "Case #" << ++cnt << ":\n";
        while (q--) {
            int l, r;
            cin >> l >> r;
            for (int j = 0; j < 26; ++j) {
                if (sum[j][r] - sum[j][l - 1] > 0) {
                    cout << sum[j][r] - sum[j][l - 1] << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
