#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7, MAX_M = 100 + 10, MAX_N = 10 + 10;

int n, m, memo[MAX_M][MAX_N];
vector <vector <pair <int, int>>> arr;

int dp (int sum, int id) {
  if (sum < 0) return -INF;
  if (id == n) return 0;
  if (memo[sum][id] != INF) return memo[sum][id];
  int ret = -INF;
  for (auto it: arr[id]) {
    int val = dp(sum - it.first, id + 1);
    if (val >= 0) ret = max(ret, it.second + val);
  }
  return memo[sum][id] = ret;
}

void readCase () {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    arr.push_back({});
    int prev = -1, curr;
    for (int j = 1; j <= m; j++) {
      cin >> curr;
      if (curr != prev and curr >= 5) arr[i].push_back({j, curr});
      prev = curr;
    }
  }
}

void clearCase () {
  fill(memo[0], memo[MAX_M], INF);
  arr.clear();
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    clearCase();
    readCase();
    int grade = dp(m, 0);
    if (5 * n <= grade) printf("Maximal possible average mark - %.2lf.\n", 1.0 * grade / n + 0.001, 2);
    else puts("Peter, you shouldn't have played billiard that much.");
  }
  return (0);
}
