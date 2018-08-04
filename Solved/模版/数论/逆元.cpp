/*
 * 逆元 快速乘 快速幂
 */
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
//快速乘法计算 (a*b) % mod
LL mul_mod(LL a, LL b, LL p) {
	LL ans = 0;
	while (b) {
		if (b & 1) {
			b--;
			ans = (ans + a) % p;
		}
		b /= 2;
		a = (a + a) % p;
	}
	return ans;
}
//快速幂取法a的b次方求余p
LL pow_mod(LL a, LL b, LL p) {
	LL ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans;
}
//费马小定理求a关于p的逆元
LL Fermat(LL a, LL p) {
	return pow_mod(a, p - 2, p);
}

