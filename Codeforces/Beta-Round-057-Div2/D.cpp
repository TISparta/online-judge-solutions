// DP on trees
// 4
// 12-02-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;

int n;
vector <pair <int, int>> G[MAX_N];
long long dp[MAX_N][2];

long long dfs (int u, int p = -1, int flag = 0) {
  long long& sum = dp[u][flag];
  if (~sum) return sum;
  int degree = 0;
  pair <int, int> qq;
  for (auto pp: G[u]) if (pp.first != p) qq = pp, degree++;
  if (degree == 0) return sum = 0;
  if (degree == 1) {
    if (flag == 0) return sum = qq.second + dfs(qq.first, u, 0);
    return sum = 2 * qq.second + dfs(qq.first, u, 1); 
  }
  long long acc = 0;
  for (auto pp: G[u]) {
    if (pp.first != p) {
      acc += 2 * pp.second + dfs(pp.first, u, 1);
    }
  }
  if (flag == 1) return sum = acc;
  sum = LLONG_MAX;
  for (auto pp: G[u]) {
    if (pp.first != p) {
      long long go = 2 * pp.second + dfs(pp.first, u, 1);
      sum = min(sum, acc - go + pp.second + dfs(pp.first, u, 0));
    }
  }
  return sum;
}

int main () {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  cout << dfs(1) << endl;
  return (0);
}
