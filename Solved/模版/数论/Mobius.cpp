//============================================================================
//Name：莫比乌斯函数筛:基于线性素数筛
//若i为奇数个不同素数之积mob[i] = -1
//若i为偶数个不同素数之积mob[i] = 1
//若i有平方因子则mob[i] = 0。
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
int prime[MAX];
bool notprime[MAX];
int mob[MAX];

void get_mobius() {
	int cnt = 0;
	mob[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (!notprime[i]) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
			notprime[i * prime[j]] = true;
			mob[i] = -1;
			if (i % prime[j] == 0) {
				mob[i * prime[j]] = 0;
				break;
			}
			mob[i * prime[j]] = -mob[i];
		}
	}
}

int main() {
	get_mobius();
	for (int i = 1; i < MAX; i++) {
		cout << mob[i] << " ";
	}
	cout << endl;
	return 0;
}

