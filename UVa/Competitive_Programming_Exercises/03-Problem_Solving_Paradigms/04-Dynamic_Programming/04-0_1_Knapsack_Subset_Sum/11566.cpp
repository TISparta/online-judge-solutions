#include <bits/stdc++.h>

using namespace std;

const int MAX_K = 100 + 10, INF = 1e6, MAX_N = 10 + 15, MAX_COST = 20000 + 10;

int n, x, t, k, price[MAX_K], favour[MAX_K], memo[MAX_K][MAX_COST][MAX_N];

int dp (int id, int cost, int dishes) {
  if (dishes < 0) return -INF;
  if (id == k) {
    int total_cost = cost + t * (n + 1);
    total_cost = total_cost + ceil(0.10 * total_cost);
    if (total_cost <= x * (n + 1)) return 0;
    return -INF;
  }
  if (memo[id][cost][dishes] != INF) return memo[id][cost][dishes];
  int ret = -INF;
  for (int it = 0; it < 3; it++) {
    ret = max(ret, favour[id] * it + dp(id + 1, cost + it * price[id], dishes - it));
  }
  return memo[id][cost][dishes] = ret;
}

void readCase () {
  for (int i = 0; i < k; i++) {
    cin >> price[i];
    favour[i] = 0;
    for (int j = 0, val; j <= n; j++) {
      cin >> val;
      favour[i] += val;
    }
  }
}

void clearCase () {
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < MAX_COST; j++)
      for (int k = 0; k <= 2 * (n + 1); k++)
        memo[i][j][k] = INF;
}

int main () {
  while (cin >> n >> x >> t >> k, n + x + t + k) {
    readCase();
    clearCase();
    int mxFavour = dp(0, 0, 2 * (n + 1));
    printf("%.2lf\n", 1.0 * mxFavour / (n + 1));
  }
  return (0);
}
