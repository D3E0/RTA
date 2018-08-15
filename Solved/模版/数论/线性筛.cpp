//============================================================================
//Name：线性筛求素数表
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;
int prime[N];
bool vis[N];

void getPrime() {
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < N; i++) {
		if (!vis[i]) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < N; j++) {
			vis[i * prime[j]] = true;
			cout << i * prime[j] << "  ";
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

int main() {
	getPrime();
	for (int i = 0; prime[i] != 0; i++) {
		cout << prime[i] << " ";
	}
	cout << endl;
	return 0;
}

