//============================================================================
//Name：欧拉函数筛:基于线性素数筛
//1~i中与i互质的数的个数,返回1~N的欧拉函数表
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000;
bool notprime[MAX];
int prime[MAX];
int phi[MAX];

void get_Eular() {
	int cnt = 0;
	for (int i = 2; i < MAX; i++) {
		if (!notprime[i]) {
			prime[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
			notprime[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}

int main() {

	get_Eular();
	for (int i = 1; i <= MAX; i++) {
		printf("for i = %d phi = %d\n", i, phi[i]);
	}
	cout << endl;

	return 0;
}

