#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100, INF = INT_MAX, N_DIR = 5;

int tc, q, ans, n, m, sRow, sCol, tRow, tCol, memo[SIZE][SIZE][N_DIR];
char grid[SIZE][SIZE], line[SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

void printBoard() {
    printf("Board #%d:\n", ++tc);
}

void printPair() {
    if (ans == INF) printf("Pair %d: impossible.\n", ++q);
    else printf("Pair %d: %d segments.\n", ++q, ans);
}

bool isValid(int r, int c) {
    return (0 <= r and 0 <= c and r < n and c < m and grid[r][c] == ' ');
}

void backtrack(int r, int c, int d) {
    for (int dir = 0; dir < 4; dir++) {
        int nr = r + dr[dir], nc = c + dc[dir];
        if (isValid(nr, nc) and memo[r][c][d] + (d != dir) <= memo[nr][nc][dir]) {
            memo[nr][nc][dir] = memo[r][c][d] + (d != dir);
            backtrack(nr, nc, dir);
        }
    }
}

void clear() {
    ans = INF;
    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
            for (int dir = 0; dir < N_DIR; dir++)
                memo[row][col][dir] = INF;
}

void solve() {
    clear();
    grid[tRow][tCol] = ' ';
    for (int dir = 0; dir < N_DIR; dir++) memo[sRow][sCol][dir] = 0;
    backtrack(sRow, sCol, 4);
    ans = memo[tRow][tCol][0];
    for (int dir = 1; dir < N_DIR; dir++) ans = min(ans, memo[tRow][tCol][dir]);
    grid[tRow][tCol] = 'X';
}


bool query() {
    cin.getline(line, SIZE);
    sscanf(line, "%d %d %d %d\n", &sCol, &sRow, &tCol, &tRow);
    return (sRow or sRow or tRow or tCol);
}

inline void init() {
    q = 0;
    memset(grid, ' ', sizeof grid);
}

bool readGrid() {
    init();
    cin.getline(line, SIZE);
    sscanf(line, "%d %d\n", &m, &n);
    if (m == 0 and n == 0) return false;
    for (int row = 1; row <= n; row++) {
        cin.getline(grid[row] + 1, SIZE);
        grid[row][m + 1] = ' ';
    }
    m += 2, n += 2;
    return true;
}

int main() {
    while (readGrid()) {
        printBoard();
        while (query()) {
            solve();
            printPair();
        }
        putchar('\n');
    }
    return (0);
}