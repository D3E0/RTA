//============================================================================
//Name：杭电多校第二场 1007 Naive Operations 线段树 + 树状数组
//线段树维护 b 数组, 每次 add 时对应的 b 数组区间 -1，
//b[i] 为 0 时， 答案 + 1;
//============================================================================
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define INFINITE 0X3f3f3f
using namespace std;
const int N = 100005;
//    flag 记录最小值出现的位置
struct SegTreeNode {
    int val, mark, left, right, flag;
} node[4 * N + 10];
int a[N], b[N], c[N];
int n, q;

void build(int index, int left, int right) {
    node[index] = {0, 0, left, right, -1};
    if (left == right) {
        node[index].flag = left;
        node[index].val = b[left];
        return;
    }
    int mid = (right + left) / 2;
    build(2 * index, left, mid);
    build(2 * index + 1, mid + 1, right);
    int ll = node[2 * index].val;
    int rr = node[2 * index + 1].val;
    if (ll < rr) {
        node[index].flag = node[2 * index].flag;
    } else {
        node[index].flag = node[2 * index + 1].flag;
    }
    node[index].val = min(ll, rr);
}

void pushdown(int index) {
    if (node[index].mark != 0) {
        node[2 * index].mark += node[index].mark;
        node[2 * index + 1].mark += node[index].mark;
        node[2 * index].val += node[index].mark;
        node[2 * index + 1].val += node[index].mark;
        node[index].mark = 0;
    }
}

int query(int index, int left, int right) {
    if (left > node[index].right || right < node[index].left) {
        return INFINITE;
    }
    if (left <= node[index].left && right >= node[index].right) {
        return node[index].val;
    }
    pushdown(index);
    int mid = (node[index].left + node[index].right) / 2;
    return min(query(2 * index, left, right), query(2 * index + 1, left, right));
}

void rangeupdate(int index, int start, int end, int val) {
    if (start > node[index].right || end < node[index].left) {
        return;
    }
    if (start <= node[index].left && end >= node[index].right) {
        node[index].mark += val;
        node[index].val += val;
        return;
    }
    pushdown(index);
    int mid = (node[index].left + node[index].right) / 2;
    rangeupdate(2 * index, start, end, val);
    rangeupdate(2 * index + 1, start, end, val);
    int ll = node[2 * index].val;
    int rr = node[2 * index + 1].val;
    if (ll < rr) {
        node[index].flag = node[2 * index].flag;
    } else {
        node[index].flag = node[2 * index + 1].flag;
    }
    node[index].val = min(ll, rr);
}

int lowbit(int x) {
    return x & -x;
}

void add(int x, int val) {
    while (x <= n) {
        c[x] += val;
        x += lowbit(x);
    }
}

int sum(int x) {
    int sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    IO;
    while (cin >> n >> q) {

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(node, 0, sizeof(node));

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        build(1, 1, n);

//        for (int i = 1; i <= 4 * n; i++) {
//			printf("i = %d val = %d  %d -- %d  %d\n", i, node[i].val, node[i].left, node[i].right, node[i].flag);
//		}

        while (q--) {
            string str;
            int x, y;
            cin >> str >> x >> y;

            if ("add" == str) {
//                对应区间值 -1
                rangeupdate(1, x, y, -1);
//                最小值为 0，将对应位置i的值重置为b[i]，答案+1
                while (query(1, 1, n) == 0) {
                    int i = node[1].flag;
                    add(i, 1);
                    rangeupdate(1, i, i, b[i]);
                }
            } else {
                cout << sum(y) - sum(x - 1) << endl;
            }
        }
    }
    return 0;
}



