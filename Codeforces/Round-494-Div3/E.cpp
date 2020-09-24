// Constructive Algorithms
// 4
// 23-12-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 4e5 + 10;

int n, d, k, dis[MAX_N], degree[MAX_N];
vector <pair <int, int>> E;

int main () {
  cin >> n >> d >> k;
  if (not (n >= d + 1)) {
    puts("NO");
    return (0);
  }
  dis[1] = d;
  for (int u = 2; u <= d + 1; u++) {
    E.emplace_back(u - 1, u);
    dis[u] = max(dis[u - 1] - 1, u - 1);
    degree[u - 1]++;
    degree[u]++;
    if (degree[u - 1] > k or degree[u] > k) {
      puts("NO");
      return (0);
    }
  }
  int u = 1, v = d + 2;
  while (u <= n and E.size() < n - 1) {
    while (u <= n and not (dis[u] + 1 <= d and degree[u] + 1 <= k)) u++;
    if (u > n) break;
    if (degree[u] == 0 or degree[v] != 0) {
      puts("NO");
      return (0);
    }
    E.emplace_back(u, v);
    degree[u]++;
    degree[v]++;
    dis[v] = dis[u] + 1;
    v++;
  }
  if (not (E.size() == n - 1)) {
    puts("NO");
    return (0);
  }
  puts("YES");
  for (auto pp: E) cout << pp.first << ' ' << pp.second << endl;
  return (0);
}
