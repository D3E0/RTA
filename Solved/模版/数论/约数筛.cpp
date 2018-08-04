//============================================================================
//Name：约数个数筛:基于线性素数筛
//============================================================================
#include <algorithm>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
int prime[MAX];
bool notprime[MAX];
int facnum[MAX];
int d[MAX];

void get_facnum() {
	int cnt  = 0;
	facnum[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (!notprime[i]) {
			prime[cnt++] = i;
			facnum[i] = 2;
			d[i] = 1;
		}
		for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
			notprime[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				facnum[i * prime[j]] = facnum[i] / (d[i] + 1) * (d[i] + 2);
				d[i * prime[j]] = d[i] + 1;
				break;
			}
			facnum[i * prime[j]] = facnum[i] * 2;
			d[i * prime[j]] = 1;
		}
	}
}

int main() {
	get_facnum();
	for (int i = 1;	i < MAX; i++) {
		cout << facnum[i] << " ";
	}
	cout << endl;
	return 0;
}

