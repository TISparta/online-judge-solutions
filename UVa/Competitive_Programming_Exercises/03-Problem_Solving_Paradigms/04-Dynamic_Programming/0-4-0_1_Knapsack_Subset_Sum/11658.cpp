#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 5, MAX_SUM = 5000 + 5, INF = 1e7;

int n, x, arr[MAX_N], memo[MAX_N][MAX_SUM];

int dp (int id, int sum) {
  if (5000 < sum) return sum;
  if (id == n + 1) return INF;
  if (~memo[id][sum]) return memo[id][sum];
  if (id == x) return dp(id + 1, sum);
  return memo[id][sum] = min(dp(id + 1, sum), dp(id + 1, sum + arr[id]));
}

void read () {
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d.%d", &a, &b);
    arr[i] = a * 100 + b;
  }
}

void clear () {
  memset(memo, -1, sizeof memo);
}

int main () {
  while (scanf("%d %d", &n, &x), n or x) {
    clear();
    read();
    printf("%.2lf\n", 100.0 * arr[x] / dp(1, arr[x]));
  }
  return (0);
}
