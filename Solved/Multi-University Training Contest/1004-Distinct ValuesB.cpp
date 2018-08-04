//============================================================================
//Name：杭电多校第一场 1004 Distinct Values 用Set（优先队列）维护当前区间可以用的值
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
struct ss {
    int x, y;
} f[100050];

bool cmp(ss p, ss q) {
    if (p.x == q.x) {
        return p.y > q.y;
    }
    return p.x < q.x;
}

int getint() {
    int res = 0, p = 1;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
    if (ch == '-') p = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * p;
}

int main() {
    int t;
    t = getint();
    while (t--) {
        int a[100050];
        int n, m;
        vector<ss> node;
        set<int> use;

        n = getint();
        m = getint();

        for (int i = 0; i < m; i++) {
            f[i].x = getint();
            f[i].y = getint();
        }

        sort(f, f + m, cmp);

        node.push_back({0, 0});
        int lasty = 0;
        for (int i = 0; i < m; i++) {
            if (f[i].y > lasty) {
                node.push_back(f[i]);
                lasty = f[i].y;
            }
        }

        for (int i = 1; i <= n; i++) {
            a[i] = 1;
            use.insert(i);
        }

        for (int i = 1; i < node.size(); i++) {
//           上一个区间与本区间没有相交的位置的值 重新 insert 到 set 中
            int right = (i == 1) ? 0 : min(node[i].x, node[i - 1].y + 1);
            for (int j = node[i - 1].x; j < right; j++) {
                use.insert(a[j]);
            }

            int start = node[i].x > node[i - 1].y ? node[i].x : node[i - 1].y + 1;
            for (int j = start; j <= node[i].y; j++) {
//                插入之后删除
                a[j] = *use.begin();
                use.erase(use.begin());
            }
        }

        printf("%d", a[1]);
        for (int i = 2; i <= n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}

