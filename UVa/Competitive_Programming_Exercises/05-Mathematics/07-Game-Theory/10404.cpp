#include <bits/stdc++.h>

#define P_POS 1
#define N_POS 2
#define U_POS 3

using namespace std;

const int MAX_M = 12, MAX_N = 1e6 + 10;

int n, m, s[MAX_M], dp[MAX_N];

void print() {
    puts(dp[n] == N_POS ? "Stan wins" : "Ollie wins");
}

bool isNposition(int id) {
    bool ret = false;
    for (int k = 0; k < m and not ret; k++) if (id - s[k] >= 0) ret |= dp[id - s[k]] == P_POS;
    return ret;
}

void setNpositions(int id) {
    for (int k = 0; k < m; k++) if (id + s[k] <= n) dp[id + s[k]] = N_POS;
}

void solve() {
    dp[0] = P_POS;
    setNpositions(0);
    for (int id = 1; id <= n; id++) if (dp[id] == U_POS) dp[id] = isNposition(id) ? N_POS : P_POS;
}

void read() {
    for (int i = 0; i < m; i++) scanf("%d", s + i);    
}

void clear() {
    fill(dp, dp + n + 1, U_POS);
}

int main() {
    while (~scanf("%d %d", &n, &m)) {
        clear();
        read();
        solve();
        print();
    }
    return (0);
}