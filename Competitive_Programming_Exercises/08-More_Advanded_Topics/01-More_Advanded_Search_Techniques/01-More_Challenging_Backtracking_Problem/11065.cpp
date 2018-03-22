#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_V = 65;

int tc, V, E, u, v, nSet, mxSet;
ll ones, Adj[MAX_V];

void backtrack(int id = 0, ll used = 0, int depth = 0) {
    if (used == ones) {
        nSet++;
        mxSet = max(mxSet, depth);
        return;
    }
    for (int i = id; i < V; i++)
        if (not (used bitand (1LL << i)))
            backtrack(i + 1, used bitor Adj[i], depth + 1);
}

void read() {
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) Adj[i] = (1LL << i);
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        Adj[u] |= (1LL << v);
        Adj[v] |= (1LL << u);
    }
    nSet = mxSet = 0;
    ones = (1LL << V) - 1;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        read();
        backtrack();
        printf("%d\n%d\n", nSet, mxSet);
    }
    return (0);
}