//============================================================================
//Name：杭电多校第一场 1002 Balanced Sequence 贪心
//============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
struct ss {
    int x, y;
//    string str;
} f[101010];

bool cmp(ss a, ss b) {

    if (a.x >= a.y && b.x < b.y) {
        //  前长后短 前短后长
        return false;
    } else if (a.x < a.y && b.x >= b.y) {
        //  前短后长 前长后短
        return true;
    } else if (a.x >= a.y && b.x >= b.y) {
        //前长后短 后降序
        return a.y > b.y;
    }
    //前短后长 前升序
    return a.x < b.x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, ans = 0;
        scanf("%d", &n);
        char str[101010];
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
//            f[i].str = str;
            f[i].y = f[i].x = 0;
            int len = strlen(str);
            for (int j = 0; j < len; j++) {
                if (str[j] == '(') {
                    f[i].y++;
                } else {
                    if (f[i].y > 0) {
                        f[i].y--;
                        ans++;
                    } else {
                        f[i].x++;
                    }
                }
            }
        }

        sort(f, f + n, cmp);

//        for (int i = 0; i < n; i++) {
//            cout<<f[i].str;
//        }

        int low = 0;
        for (int i = 0; i < n; i++) {
            if (f[i].x > low)
                f[i].x = low;
            ans += f[i].x;
            low -= f[i].x;
            low += f[i].y;
        }

        printf("%d\n", ans * 2);

    }

    return 0;
}