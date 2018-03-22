#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10, LEN = 100;

int on, ans;
char test_name[LEN], grid[SIZE + 1][SIZE + 1];
int dr[] = {-1, 0, 0, 0, 1};
int dc[] = {0, -1, 0, 1, 0};

inline void print() {
    printf("%s %d\n", test_name, ans == 101 ? -1 : ans);
}

inline bool isValid(int r, int c) {
    return (0 <= r and 0 <= c and r < SIZE and c < SIZE);
}

void press(int r, int c) {
    for (int d = 0; d < 5; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (isValid(nr, nc)) {
            if (grid[nr][nc] == '#') on++, grid[nr][nc] = 'O';
            else if (grid[nr][nc] == 'O') on--, grid[nr][nc] = '#';
        }
    }
}

void backtrack(int r = 0, int c = 0, int pressed = 0) {
    if (pressed >= ans) return;
    if (on == 0) {
        ans = min(ans, pressed);
        return;
    }
    if (r == SIZE) return;
    if (not isValid(r - 1, c) or grid[r - 1][c] == 'O') {
        press(r, c);
        backtrack(c + 1 == SIZE ? r + 1 : r, c + 1 == SIZE ? 0 : c + 1, pressed + 1);
        press(r, c);
    }
    if (not isValid(r - 1, c) or grid[r - 1][c] == '#')
        backtrack(c + 1 == SIZE ? r + 1 : r, c + 1 == SIZE ? 0 : c + 1, pressed);
}

void init() {
    on = 0;
    ans = 101;
}

bool read() {
    init();
    scanf("%s\n", test_name);
    if (strcmp(test_name, "end") == 0) return false;
    for (int row = 0; row < SIZE; row++) {
        scanf("%s\n", grid[row]);
        for (int col = 0; col < SIZE; col++)
            if (grid[row][col] == 'O') on++;
    }
    return true;
}

int main() {
    while (read()) {
        backtrack();
        print();
    }
    return (0);
}