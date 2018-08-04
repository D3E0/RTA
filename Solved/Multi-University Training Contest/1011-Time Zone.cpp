//============================================================================
//Name：杭电多校第一场 1011 Time Zone
//============================================================================
#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    int t;
    int a, b;
    char ch;
    double time;
    cin >> t;
    while (t--) {
        scanf("%d %d %c%c%c%lf", &a, &b, &ch, &ch, &ch, &time);

//      b -= (8 - time) * 60 false
        b -= (80 - time * 10) * 6;

        while (b < 0) {
            b += 60;
            a--;
        }
        while (b >= 60) {
            b -= 60;
            a++;
        }
        while (a < 0) {
            a += 24;
        }
        while (a >= 24) {
            a -= 24;
        }

        printf("%02d:%02d\n", a, b);
    }
    return 0;

}