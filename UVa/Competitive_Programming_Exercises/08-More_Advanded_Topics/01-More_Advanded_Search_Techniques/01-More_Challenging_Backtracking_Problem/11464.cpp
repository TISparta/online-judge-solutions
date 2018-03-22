#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;

int tc, n, changes, ans;
bool grid[MAX_N][MAX_N];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool isValid(int r, int c) {
    return (0 <= r and 0 <= c and r < n and c < n);
}

bool evenParity(int r, int c) {
    int ct = 0;
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        ct += (isValid(nr, nc) and grid[nr][nc]);
    }
    return not (ct & 1);
}

void backtrack(int r = 0, int c = 0) {
    if (r == n) {
        ans = min(ans, changes);
        return;
    }
    if (changes > ans) return;
    if (grid[r][c] == false) {
        grid[r][c] = true, changes++;
        if (not isValid(r - 1, c) or evenParity(r - 1, c))
            backtrack(c + 1 == n ? r + 1 : r, c + 1 == n ? 0 : c + 1);
        grid[r][c] = false, changes--;
    }
    if (not isValid(r - 1, c) or evenParity(r - 1, c))    
        backtrack(c + 1 == n ? r + 1 : r, c + 1 == n ? 0 : c + 1);
}

void init() {
    ans = n * n;
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
}

int main() {
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        read();
        init();
        backtrack();
        printf("Case %d: %d\n", t, ans == n * n ? -1 : ans);
    }
    return (0);
}