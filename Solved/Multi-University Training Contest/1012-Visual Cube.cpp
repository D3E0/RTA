//============================================================================
//Name：杭电多校第三场 1012 Visual Cube 画图
//============================================================================
#include<bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
char str[150][150];

int main() {
    IO;

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int w = 2 * a + 1 + 2 * b;
        int h = 2 * c + 1 + 2 * b;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                str[i][j] = '.';
            }
        }

        for (int i = 0; i < 2 * b; i++) {
            for (int j = w - i - 1; j >= w - i - (2 * a + 1); j--) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        str[i][j] = '+';
                    } else {
                        str[i][j] = '-';
                    }
                } else {
                    if (j % 2 == 0) {
                        str[i][j] = '.';
                    } else {
                        str[i][j] = '/';
                    }
                }
            }
        }
        for (int i = 2 * b; i < h; i++) {
            for (int j = 0; j < 2 * a + 1; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        str[i][j] = '+';
                    } else {
                        str[i][j] = '-';
                    }
                } else {
                    if (j % 2 == 0) {
                        str[i][j] = '|';
                    } else {
                        str[i][j] = '.';
                    }
                }
            }
        }

        for (int j = w - 1; j >=  2 * a + 1; j--) {
            for (int i = w - j; i < w - j + 2 * c; i++) {
                str[i][j] = '*';
                if (j % 2 == 0) {
                    if (i % 2 == 0) {
                        str[i][j] = '+';
                    } else {
                        str[i][j] = '|';
                    }
                } else {
                    if (i % 2 == 0) {
                        str[i][j] = '.';
                    } else {
                        str[i][j] = '/';
                    }
                }

            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << str[i][j];
            }
            cout << endl;
        }
    }
    return 0;

}
