//============================================================================
//Name：牛客多校第三场 E Sort String KMP 求最小循环节 (len-mynext[len])
//https://www.nowcoder.com/acm/contest/141/E
//============================================================================
#include<bits/stdc++.h>

using namespace std;
char b[1000005];
int Next[1000005];
int n;
namespace io {
    const int L = (1 << 21) + 1;
    char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, st[55];
    int f, tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)

    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }

    inline void putc(char x) {
        *oS++ = x;
        if (oS == oT) flush();
    }

    template<class I>
    inline void gi(I &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
        x *= f;
    }

    template<class I>
    inline void print(I x) {
        if (!x) putc('0');
        if (x < 0) putc('-'), x = -x;
        while (x) st[++tp] = x % 10 + '0', x /= 10;
        while (tp) putc(st[tp--]);
    }

    inline void gs(char *s, int &l) {
        for (c = gc(); c < 'a' || c > 'z'; c = gc());
        for (l = 0; c <= 'z' && c >= 'a'; c = gc()) s[l++] = c;
        s[l] = 0;
    }

    inline void ps(const char *s) { for (int i = 0, n = strlen(s); i < n; i++) putc(s[i]); }

    struct IOFLUSHER {
        ~IOFLUSHER() { flush(); }
    } _ioflusher_;
};

void SetNext() {
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < n) {
        if (j == -1 || b[i] == b[j]) {
            i++;
            j++;
            Next[i] = j;
        } else
            j = Next[j];
    }
}

int main() {
    ios::sync_with_stdio(false);//取消同步
    std::cin.tie(0);//解除cin与cout的绑定，进一步加快执行效率。
    io::gs(b, n);
    SetNext();
//    最小循环节
    int sum = n - Next[n];
//    最小循环节数目
    int cnt = n / sum;
    io::print(sum);
    io::putc('\n');
    for (int i = 0; i < sum; i++) {
        io::print(cnt);
        for (int j = i; j < n; j += sum) {
            io::putc(' ');
            io::print(j);
        }
        io::putc('\n');
    }
    return 0;
}