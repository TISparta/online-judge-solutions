#include <bits/stdc++.h>

using namespace std;

const int MAX_N_N = 10;

int n, n_n, filled, ones, mat[MAX_N_N][MAX_N_N], row[MAX_N_N], col[MAX_N_N], sq[MAX_N_N];
bool found, first = true;

void print() {
    if (not found) {
        puts("NO SOLUTION");
        return;
    }
    for (int i = 0; i < n_n; i++)
        for (int j = 0; j < n_n; j++)
            printf(j == n_n - 1 ? "%d\n" : "%d ", mat[i][j]);
}

void backtrack(int r, int c, int res) {
    if (res == 0) found = true;
    if (r == n_n or found) return;
    int p = (r / n) * n + c / n;
    int pos = ones bitand (compl (row[r] bitor col[c] bitor sq[p]));
    if (mat[r][c] == 0) {
        for (int num = 1; num <= n_n and not found; num++)
            if((pos >> num) & 1) {
                int bin_num = pos & -pos;
                mat[r][c] = num;
                row[r] |= bin_num, col[c] |= bin_num, sq[p] |= bin_num;
                backtrack(c + 1 == n_n ? r + 1 : r, c + 1 == n_n ? 0 : c + 1, res - 1);
                if (not found) mat[r][c] = 0;
                row[r] ^= bin_num; col[c] ^= bin_num, sq[p] ^= bin_num;
                pos -= bin_num;
            }
    }
    else backtrack(c + 1 == n_n ? r + 1 : r, c + 1 == n_n ? 0 : c + 1, res);        
}

void read() {
    for (int i = 0; i < n_n; i++) row[i] = col[i] = sq[i] = 1;
    for (int i = 0; i < n_n; i++)
        for (int j = 0; j < n_n; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j]) {
                filled++;
                row[i] |= (1 << mat[i][j]);
                col[j] |= (1 << mat[i][j]);
                sq[(i / n) * n + j / n] |= (1 << mat[i][j]);
            }
        }
}

int main() {
    while (scanf("%d", &n) == 1) {
        if (not first) putchar('\n');
        first = false;
        n_n = n * n;
        filled = 0;
        found = false;
        ones = (1 << (n_n + 1)) - 1;
        read();
        backtrack(0, 0, n_n * n_n - filled);
        print();
    }
    return (0);
}
