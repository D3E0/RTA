//============================================================================
//Name：杭电多校第四场 1010 J. Let Sudoku Rotate  深搜  可行性剪枝
//============================================================================
#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define rep(i, a, n) for (int i = a; i < n; i++)
//#define per(i, a, n) for (int i = n-1; i >= a; i--)

using namespace std;
typedef long long LL;

const int N = 16;
const int MN = N + 5;
int a[MN][MN], r[MN][MN], c[MN][MN], tmp[N][N], ans;

void add(int x, int y, int op) {
    rep(i, 4 * x, 4 * (x + 1)) {
        rep(j, 4 * y, 4 * (y + 1)) {
            r[i][a[i][j]] += op;
            c[j][a[i][j]] += op;
        }
    }
}

bool rorate(int x, int y) {
    rep(i, 4 * x, 4 * (x + 1)) {
        rep(j, 4 * y, 4 * (y + 1)) {
            r[i][a[i][j]]--;
            c[j][a[i][j]]--;
//            tmp[4 - 1 - (j - 4 * y)][i - 4 * x] = a[i][j];
            tmp[j - 4 * y][4 * (x + 1) - i - 1] = a[i][j];
        }
    }
    bool flag = true;
    rep(i, 4 * x, 4 * (x + 1)) {
        rep(j, 4 * y, 4 * (y + 1)) {
            a[i][j] = tmp[i - 4 * x][j - 4 * y];
            r[i][a[i][j]]++, c[j][a[i][j]]++;
            if (r[i][a[i][j]] > 1 || c[j][a[i][j]] > 1) flag = 0;
        }
    }
    return flag;
}

void dfs(int x, int y, int cnt) {
    if (x == 4 && y == 0) {
        ans = min(ans, cnt);
        return;
    }

    add(x, y, 1);

    for (int i = 1; i <= 4; i++) {
        if (rorate(x, y)) {
            dfs(y == 3 ? x + 1 : x, y == 3 ? 0 : y + 1, cnt + i % 4);
        }
    }

    add(x, y, -1);

}

int main() {
    IO;
#ifdef ONLINE_JUDGE
#else
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\in)", "r", stdin);
    freopen(R"(C:\Users\ACM-PC\CLionProjects\Competitaon\Problem\out)", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        memset(tmp, 0, sizeof(tmp));
        char ch;
        rep(i, 0, N) {
            rep(j, 0, N) {
                cin >> ch;
                if (isdigit(ch)) {
                    a[i][j] = ch - '0';
                } else {
                    a[i][j] = ch - 'A' + 10;
                };
            }
        }
        ans = 64;
        dfs(0, 0, 0);

        printf("%d\n", ans);

    }

    return 0;
}

