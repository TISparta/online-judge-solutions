#include <bits/stdc++.h>

using namespace std;

const int SIZE = 12, MAX_N = 4, MAX_M = 3;

int tc, t, ans;
string s[SIZE], grid[MAX_N][MAX_M];
map <string, int> ct;

void print() {
    printf("Case %d: %d\n", ++t, ans);
}

inline bool isValid(int r, int c) {
    return (0 <= r and 0 <= c and r < MAX_N and c < MAX_M);
}

bool check(int r, int c, string ss) {
    if (isValid(r, c - 1) and grid[r][c - 1][1] != ss[3]) return false;
    if (isValid(r - 1, c) and grid[r - 1][c][2] != ss[0]) return false;
    return true;
}

void backtrack(int r = 0, int c = 0, int ret = 1) {
    if (r == MAX_N) {
        ans += ret;
        return;
    }
    for (map<string, int> :: iterator it = ct.begin(); it != ct.end(); ++it)
        if (it -> second and check(r, c, it -> first)) {
            int p = it -> second;
            grid[r][c] = it -> first;
            ct[it -> first]--;
            backtrack(c + 1 == MAX_M ? r + 1 : r, c + 1 == MAX_M ? 0 : c + 1, ret * p);
            grid[r][c] = "";
            ct[it -> first]++;
        }
}

void solve() {
    for (int i = 0; i < SIZE; i++) ct[s[i]]++;        
    backtrack();
}

void read() {
    for (int i = 0; i < SIZE; i++) cin >> s[i];
}

void init() {
    ans = 0;
    ct.clear();
    fill(grid[0], grid[MAX_N], "");
}

int main() {
    scanf("%d\n", &tc);
    while(tc--) {
        init();
        read();
        solve();
        print();
    }
    return (0);
}