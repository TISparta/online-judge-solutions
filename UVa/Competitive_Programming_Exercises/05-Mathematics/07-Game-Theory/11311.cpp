#include <bits/stdc++.h>

using namespace std;

int tc, m, n, r, c;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d %d", &m, &n, &r, &c);
        puts((r xor c xor (m - r - 1) xor (n - c - 1)) == 0 ? "Hansel" : "Gretel");
    }
    return (0);
}