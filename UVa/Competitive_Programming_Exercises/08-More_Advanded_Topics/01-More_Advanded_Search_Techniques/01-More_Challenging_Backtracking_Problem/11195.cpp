#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;

int n, tc, ans, ones, notValid[MAX_N];
char c;

void backtrack(int row = 0, int upperD = 0, int lowerD = 0, int col = 0) {
    if (row == ones) { ans++; return; }
    int pos = ones bitand ( compl (row bitor upperD bitor lowerD bitor notValid[col]) );
    while (pos) {
        int pib = pos bitand -pos;
        pos -= pib;
        backtrack(row bitor pib, (upperD bitor pib) << 1, (lowerD bitor pib) >> 1, col + 1);
    }
}

void read() {
    for (int col = 0; col < n; col++) notValid[col] = 0;
    for (int row = 0; row < n; row++, getchar())
        for (int col = 0; col < n; col++)
            if ( ( c = getchar() ) == '*' ) notValid[col] |= 1 << row;
}

int main() {
    while (scanf("%d\n", &n), n) {
        ans = 0;
        ones = (1 << n) - 1;
        read();
        backtrack();
        printf("Case %d: %d\n", ++tc, ans);
    }
    return (0);
}