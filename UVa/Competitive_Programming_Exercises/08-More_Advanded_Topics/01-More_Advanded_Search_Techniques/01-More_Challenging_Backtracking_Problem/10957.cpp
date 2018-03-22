#include <bits/stdc++.h>

using namespace std;

const int MAX_N_N = 10;

int tc, n, n_n, filled, ones, solutions, mat[MAX_N_N][MAX_N_N], row[MAX_N_N], col[MAX_N_N], sq[MAX_N_N];
bool valid;

void backtrack(int r, int c, int res) {
    if (res == 0) {
        solutions++;
        return;
    }
    if (r == n_n or solutions >= 2) return;
    int p = (r / n) * n + c / n;
    int pos = ones bitand (compl (row[r] bitor col[c] bitor sq[p]));
    if (mat[r][c] == 0) {
        while (pos and solutions < 2) {
            int bin_num = pos bitand -pos;
            row[r] |= bin_num, col[c] |= bin_num, sq[p] |= bin_num;
            backtrack(c + 1 == n_n ? r + 1 : r, c + 1 == n_n ? 0 : c + 1, res - 1);
            row[r] ^= bin_num; col[c] ^= bin_num, sq[p] ^= bin_num;
            pos -= bin_num;
        }
    }
    else backtrack(c + 1 == n_n ? r + 1 : r, c + 1 == n_n ? 0 : c + 1, res);        
}

void solve() {
    if (not valid) {
        printf("Case %d: Illegal.\n", ++tc);
        return;
    }
    backtrack(0, 0, n_n * n_n - filled);
    if (solutions == 0) printf("Case %d: Impossible.\n", ++tc);
    else if (solutions == 1) printf("Case %d: Unique.\n", ++tc);
    else printf("Case %d: Ambiguous.\n", ++tc);
}

void check(int r, int c) {
    if (mat[r][c] == 0) return;
    int pib = (1 << mat[r][c]), p = (r / n) * n + c / n;
    if ( (row[r] bitand pib) != 0 or
         (col[c] bitand pib) != 0 or
         (sq[p] bitand pib) != 0 ) valid = false;
    row[r] |= pib;
    col[c] |= pib;
    sq[p] |= pib;
    filled++;
}

void read() {
    for (int i = 0; i < n_n; i++) row[i] = col[i] = sq[i] = 1;
    check(0, 0);
    for (int i, j, p, pib, k = 1; k < n_n * n_n; k++) {
        i = k / n_n, j = k % n_n;
        scanf("%d", &mat[i][j]);
        check(i, j);
    }
}

int main() {
    n = 3, n_n = 9, ones = (1 << (n_n + 1)) - 1;
    while (scanf("%d", &mat[0][0]) == 1) {
        filled = solutions = 0;
        valid = true;
        read();
        solve();
    }
    return (0);
}