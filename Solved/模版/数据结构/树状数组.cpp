/*
 * 树状数组 单点更新 区间查询
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5;
int c[N], a[N];
int lowbit(int x) {
	return x & -x;
}
//a[x] += v
void add(int x, int v) {
	while (x < N) {
		c[x] += v;
		x += lowbit(x);
	}
}
//a[1]~a[x]的区间和
int sum(int x) {
	int s = 0;
	while (x) {
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}
int main() {

}
