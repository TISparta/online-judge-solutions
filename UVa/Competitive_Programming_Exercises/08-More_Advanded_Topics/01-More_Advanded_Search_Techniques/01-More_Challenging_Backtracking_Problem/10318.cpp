#include <bits/stdc++.h>

using namespace std;

const int SIZE = 5, MAX_MASK = (1 << (SIZE * SIZE));

int tc, R, C, ones;
char ch;
bool valid[SIZE][SIZE];
vector < int > ans, ret;

void print() {
    printf("Case #%d\n", ++tc);
    if (ans.empty()) puts("Impossible.");
    else for (int i = 0, sz = ans.size(); i < sz; i++) printf(i == sz - 1 ? "%d\n" : "%d ", ans[i] + 1);
}

inline bool isValid(int r, int c) {
    return (0 <= r and 0 <= c and r < R and c < C);
}

int mark(int mask, int id) {
    int r = id / C, c = id % C;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++) {
            int nr = r + dr, nc = c + dc, hh = nr * C + nc;
            if (valid[dr + 1][dc + 1] and isValid(nr, nc))
                mask ^= (1 << hh);
        }
    return mask;
}

bool isTurned(int mask, int id) {
    int r = (id / C) - 1, c = (id % C) - 1, hh = r * C + c;
    return (not isValid(r, c) or (mask >> hh) & 1);
}

void backtrack(int used = 0, int id = 0) {
    if (used == ones) {
        ans = ret;
        return;
    }
    if (id == R * C) return;
    if ((ans.empty() or ret.size() + 1 < ans.size()) and isTurned(mark(used, id), id)) {
        ret.push_back(id);
        backtrack(mark(used, id), id + 1);
        ret.pop_back();
    }
    backtrack(used, id + 1);
}

void read() {
    for (int row = 0; row < 3; row++, getchar())
        for (int col = 0; col < 3; col++)
            if ((ch = getchar()) == '*') valid[row][col] = true;
}

void init() {
    memset(valid, false, sizeof valid);
    ones = (1 << (R * C)) - 1;
    ans.clear();
}

int main() {
    while(scanf("%d %d\n", &R, &C), R bitor C) {
        init();
        read();
        backtrack();
        print();
    }
    return (0);
}