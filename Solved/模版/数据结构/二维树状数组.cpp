//============================================================================
//Name：二维树状数组 c[x][y]记录的是右下角为(x, y)，高为lowbit(x), 宽为 lowbit(y)的区间的区间和
//============================================================================
#include <iostream>
#include <cstring>

using namespace std;
const int N = 100005;
int c[N][N];

int lowbit(int x) {
    return x & -x;
}

//将点(x, y)加上z
void add(int x, int y, int z) {
    int memo_y = y;
    while (x <= N) {
        y = memo_y;
        while (y <= N)
            c[x][y] += z;
        y += lowbit(y);
        x += lowbit(x);
    }
}

//求左上角为(1,1)右下角为(x,y) 的矩阵和
void sum(int x, int y) {
    int res = 0, memo_y = y;
    while (x) {
        y = memo_y;
        while (y) {
            res += c[x][y];
            y -= lowbit(y);
        }
        x -= lowbit(x);
    }
}
