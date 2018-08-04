//============================================================================
//Name：杭电多校第一场 1004 Distinct Values 优先队列??? Set??? 最小不包含mex???
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

/*
1
11 3
1 4
2 6
3 8
 */

using namespace std;
struct ss {
    int x, y;
} f[100005];

bool cmp(ss p, ss q) {
    if (p.x == q.x) {
        return p.y > q.y;
    }
    return p.x < q.x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a[100005];
        int n, m;
        vector<ss> node;
        memset(a, 0, sizeof(a));

        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &f[i].x, &f[i].y);
        }

        sort(f, f + m, cmp);

//       区间预处理，合并区间
        node.push_back({0, 0});
        node.push_back(f[0]);
        int lasty = f[0].y;
        for (int i = 1; i < m; i++) {
            if (f[i].y > lasty) {
                node.push_back(f[i]);
                lasty = f[i].y;
            }
        }

//        for (int i = 0; i < node.size(); i++) {
//            cout << "---" << node[i].x << " " << node[i].y << endl;
//        }

        int usage[100005];

        for (int i = 1; i < node.size(); i++) {
            int mySize = min(sizeof(int) * (node[i].y - node[i].x + 5) * 2, sizeof(usage));
//            memset(usage, 0,  sizeof(usage)); TLE
            memset(usage, 0, mySize);
            int iter = 1;
//            与上一个区间相交的部分，在本区间不能使用
            for (int j = node[i].x; j <= node[i - 1].y; j++) {
                usage[a[j]] = 1;
            }
            int start = node[i].x > node[i - 1].y ? node[i].x : node[i - 1].y + 1;
            for (int j = start; j <= node[i].y; j++) {
                while (usage[iter]) {
                    iter++;
                }
                a[j] = iter++;
            }
        }

        if (!a[1]) {
            a[1] = 1;
        }
        printf("%d", a[1]);
        for (int i = 2; i <= n; i++) {
            if (!a[i]) {
                a[i] = 1;
            }
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}

