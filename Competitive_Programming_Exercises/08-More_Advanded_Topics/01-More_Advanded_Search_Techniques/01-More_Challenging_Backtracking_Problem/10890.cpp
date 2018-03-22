#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 35;

int tc, N, S, T, ans;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
vector < pair <int, int> > treasures;

inline int dis(pair <int, int> A, pair <int, int> B) {
    return abs(A.first - B.first) + abs(A.second - B.second);
}

void backtrack(int used = 0, int cost = 0, pair <int, int> last_point = {0, 0}) {
    if (__builtin_popcount(used) == S) {
        ans = min(ans, cost + dis(last_point, {N - 1, N - 1}));
        return;
    }
    if (__builtin_popcount(used) == treasures.size()) return;
    for (int i = 0; i < treasures.size(); i++)
        if (((used >> i) & 1) == 0) {
            int n_cost = cost + dis(last_point, treasures[i]);
            if (n_cost < ans ) backtrack(used | (1 << i), n_cost, treasures[i]);
        }
}

void read() {
    int a, b;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);
        treasures.push_back({a, b});
    }
}

void init() {
    treasures.clear();
    ans = INT_MAX;
}

int main() {
    while (scanf("%d %d %d", &N, &T, &S), N bitor T bitor S) {
        init();
        read();
        backtrack();
        printf("Case %d: %d\n", ++tc, ans);
    }
    return (0);
}