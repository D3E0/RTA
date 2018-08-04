//============================================================================
//Name��Miller_Rabin�㷨�ж�����
//============================================================================
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int times = 20;
int number = 0;
typedef long long LL;

LL Random(LL n) {
	//����[ 0 , n ]�������
	return ((double) rand() / RAND_MAX * n + 0.5);
}
//���ٳ˷����� (a*b) % mod
LL q_mul(LL a, LL b, LL mod) {
	LL ans = 0;
	while (b) {
		if (b & 1) {
			b--;
			ans = (ans + a) % mod;
		}
		b /= 2;
		a = (a + a) % mod;

	}
	return ans;
}
//������ȡģ���� (a^b) % mod
LL q_pow(LL a, LL b, LL mod) {
	LL ans = 1;
	while (b) {
		if (b & 1) {
			ans = q_mul(ans, a, mod);
		}
		b /= 2;
		a = q_mul(a, a, mod);
	}
	return ans;
}
//miller_rabin�㷨�ľ���,������a������n�ǲ�������
bool witness(LL a, LL n) {
	//
	LL tem = n - 1;
	int j = 0;
	while (tem % 2 == 0) {
		tem /= 2;
		j++;
	}
	LL x = q_pow(a, tem, n);
	if (x == 1 || x == n - 1) {
		return true;	//����Ϊ1��Ϊ����
	}
	//������������2���Ƿ�������� j
	while (j--) {
		x = q_mul(x, x, n);
		if (x == n - 1)
			return true;
	}
	return false;
}
//����n�Ƿ�������
bool miller_rabin(LL n) {
	if (n == 2) {
		return true;
	}
	if (n < 2 || n % 2 == 0) {
		//�����2�������������<2������>2��ż����������
		return false;
	}
	//��times���������
	for (int i = 1; i <= times; i++) {
		LL a = Random(n - 2) + 1; //�õ������������ a
		if (!witness(a, n))			//��a����n�Ƿ�������
			return false;
	}
	return true;
}

int main() {
	LL tar;
	while (cin >> tar) {
		if (miller_rabin(tar))	//����tar�ǲ�������
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
