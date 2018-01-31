#include <bits/stdc++.h>

#define WIN       1
#define DRAW      0
#define FAIL     -1
#define CONTINUE -2

using namespace std;

const int MAX_N = 4, SIZE = 6, MAX_ORD = 130;

bool possible;
char ch, grid[SIZE][SIZE];
int available, ans_row, ans_col, weight[MAX_ORD];
int x_row[MAX_N], x_col[MAX_N], x_main_diag, x_sec_diag;
int o_row[MAX_N], o_col[MAX_N], o_main_diag, o_sec_diag;
map <int, int> vis;

int minVal();
int maxVal();

void print() {
    if (possible) printf("(%d,%d)\n", ans_row, ans_col);
    else puts("#####");
}

int getHash() {
    int ret = 0;
    for (int row = 0; row < MAX_N; row++)
        for (int col = 0; col < MAX_N; col++)
            ret += weight[grid[row][col]], ret *= 10;
    return ret;
}

inline int getIndex(const int& row, const int& col) {
    return row * MAX_N + col;
}

inline void toggleAvailables(const int& row, const int& col) {
    available ^= (1 << getIndex(row, col));
}

void mark(const int& row, const int& col, const bool is_x, const int variation) {
    if (is_x) {
        grid[row][col] = (variation == 1) ? 'x' : '.';
        x_row[row] += variation;
        x_col[col] += variation;
        if (row == col) x_main_diag += variation;
        if (row + col == MAX_N - 1) x_sec_diag += variation;
    }
    else {
        grid[row][col] = (variation == 1) ? 'o' : '.';
        o_row[row] += variation;
        o_col[col] += variation;
        if (row == col) o_main_diag += variation;
        if (row + col == MAX_N - 1) o_sec_diag += variation;
    }
}

bool isDraw() {
    bool ret = true;
    ret &= x_main_diag and x_sec_diag;
    ret &= o_main_diag and o_sec_diag;
    for (int id = 0; id < MAX_N and ret; id++)
        ret &= x_row[id] and x_col[id] and o_row[id] and o_col[id];
    return ret;
}

int isTerminal() {
    int sum = 0;
    if (x_main_diag == MAX_N or x_sec_diag == MAX_N) return WIN;
    if (o_main_diag == MAX_N or o_sec_diag == MAX_N) return FAIL;
    if (isDraw()) return DRAW;
    for (int id = 0; id < MAX_N; id++) {
        if (x_row[id] == MAX_N or x_col[id] == MAX_N) return WIN;
        else if(o_row[id] == MAX_N or o_col[id] == MAX_N) return FAIL;
        sum += x_row[id] + o_row[id];
    }
    return (sum == MAX_N * MAX_N) ? DRAW : CONTINUE;
}

int minVal() {
    int pib = available, res = WIN, pos, row, col, ret;
    int _hash = getHash();
    if (vis.find(_hash) != vis.end()) return vis[_hash];
    while (pib and res != FAIL) {
        pos = __builtin_ctz(pib), row = pos / MAX_N, col = pos - MAX_N * row;
        toggleAvailables(row, col);
        mark(row, col, false, 1);
        ret = isTerminal();
        res = min(res, (ret == CONTINUE) ? maxVal() : ret);
        toggleAvailables(row, col);
        mark(row, col, false, -1);
        pib &= pib - 1;
    }
    return vis[_hash] = res;
}

int maxVal() {
    int pib = available, res = FAIL, pos, row, col, ret;
    int _hash = getHash();
    if (vis.find(_hash) != vis.end()) return vis[_hash];
    while (pib and res != WIN) {
        pos = __builtin_ctz(pib), row = pos / MAX_N, col = pos - MAX_N * row;
        toggleAvailables(row, col);
        mark(row, col, true, 1);
        ret = isTerminal();
        res = max(res, (ret == CONTINUE) ? minVal() : ret);
        toggleAvailables(row, col);
        mark(row, col, true, -1);
        pib &= pib - 1;
    }
    return vis[_hash] = res;
}

int minimax(const int& row, const int& col) {
    toggleAvailables(row, col);
    mark(row, col, true, 1);
    int res = isTerminal();
    if (res == CONTINUE) res = minVal();
    toggleAvailables(row, col);
    mark(row, col, true, -1);
    return res;
}

void solve() {
    for (int row = 0; row < MAX_N; row++)
        for (int col = 0; col < MAX_N; col++)
            if (grid[row][col] != '.') mark(row, col, grid[row][col] == 'x', 1);
            else available |= (1 << getIndex(row, col));
    int pib = available, pos, row, col, res;
    while (pib and not possible) {
        pos = __builtin_ctz(pib), row = pos / MAX_N, col = pos - MAX_N * row;
        res = minimax(row, col);
        if (res == WIN) ans_row = row, ans_col = col, possible = true;
        pib &= pib - 1;
    }
}

void read() {
    for (int row = 0; row < MAX_N; row++) scanf("%s\n", grid[row]);
}

inline void clear() {
    available = 0;
    possible = false;
    x_main_diag = x_sec_diag = o_main_diag = o_sec_diag = 0;
    for (int id = 0; id < MAX_N; id++) x_row[id] = x_col[id] = o_row[id] = o_col[id] = 0;
}

inline void init() {
    weight['o'] = 1;
    weight['x'] = 2;
}

int main() {
    init();
    while (scanf("%s\n", &ch), ch != '$') {
        clear();
        read();
        solve();
        print();
    }
    return (0);
}