//============================================================================
//Name：第一场 D-Two Graphs
//直接枚举所有映射，图一到图一可能存在a2次映射，图1和图2的映射总次数a1，
//答案中肯定重复了a2次，那么a1/a2就是我们求的答案。
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int ma1[15][15], ma2[15][15];
int a[15];
int main() {
	int n, m1, m2;
	while (cin >> n >> m1 >> m2) {

		memset(ma1, 0, sizeof(ma1));
		memset(ma2, 0, sizeof(ma2));

		for (int i = 1; i <= m1; i++) {
			int x, y;
			cin >> x >> y;
			ma1[x][y] = 1;
			ma1[y][x] = 1;
		}
		for (int i = 1; i <= m2; i++) {
			int x, y;
			cin >> x >> y;
			ma2[x][y] = 1;
			ma2[y][x] = 1;
		}

		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		int a1 = 0, a2 = 0;
		do {
			int flag = 1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (ma1[i][j] && (!ma2[a[i]][a[j]])) {
						flag = 0;
						break;
					}
			if (flag == 1) {
				for (int i = 1; i <= n; ++i) {
					cout << a[i] << ' ';
				}
				cout << endl;
			}
			a1 += flag;
		} while (next_permutation(a + 1, a + 1 + n));

//		cout << "--------------------------" << endl;

		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		do {
			int flag = 1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (ma1[i][j] && (!ma1[a[i]][a[j]])) {
						flag = 0;
						break;
					}
			if (flag == 1) {
				for (int i = 1; i <= n; ++i) {
					cout << a[i] << ' ';
				}
				cout << endl;
			}
			a2 += flag;
		} while (next_permutation(a + 1, a + 1 + n));

		cout << a1 / a2 << endl;
	}
	return 0;
}

