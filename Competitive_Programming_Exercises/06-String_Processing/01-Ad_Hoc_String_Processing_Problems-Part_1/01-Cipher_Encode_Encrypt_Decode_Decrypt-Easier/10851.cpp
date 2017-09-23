#include <bits/stdc++.h>

using namespace std;

const int N_ROWS = 20, N_COLS = 90;

int tc, M;
char grid[N_ROWS][N_COLS];

char getLetter(int col) {
    int ret = 0;
    for (int row = 1, power = 1; row < 9; row++, power <<= 1)
        if (grid[row][col] == '\\') ret += power;
    return ret;
}

int main() {
    scanf("%d\n", &tc);
    while (tc--) {
        for (int row = 0; row < 10; row++) scanf("%s\n", grid[row]);
        M = strlen(grid[0]);
        for (int col = 1; col + 1 < M; col++) putchar(getLetter(col)); putchar('\n');
    }
    return(0);
}