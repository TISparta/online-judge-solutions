// Tags: Number Theory
// Difficulty: 5.0
// Priority: 5
// Date: 13-03-2019

#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 10;

int main () {
  vector <vector <int>> divisors(MX);
  for (int u = 1; u < MX; u++) {
    for (int v = u; v < MX; v += u) {
      divisors[v].push_back(u);
    }
  }
  int n;
  scanf("%d", &n);
  vector <int> vis(MX, 0);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int ans = 0;
    for (int d: divisors[x]) {
      if (vis[d] < i - y) ans++;
      vis[d] = i;
    }
    printf("%d\n", ans);
  }
  return (0);
}
