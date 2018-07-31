#include <bits/stdc++.h>

using namespace std;

const int N_COINS = 6, MAX_SUM = 1000, INF = 1e7;
const vector <int> value = {5, 10, 20, 50, 100, 200};

int money, memo1[MAX_SUM][N_COINS], memo2[MAX_SUM][N_COINS];
vector <int> coin(N_COINS);

int coinChange (int sum, int id) {
  if (sum == 0) return 0;
  if (id == N_COINS or sum >= MAX_SUM) return INF;
  if (~memo1[sum][id]) return memo1[sum][id];
  int ret = INF;
  for (int k = 0; value[id] * k <= sum; k++) {
    ret = min(ret, k + coinChange(sum - value[id] * k, id + 1));
  }
  return memo1[sum][id] = ret;
}

int dp (int sum, int id) {
  if (sum >= MAX_SUM) return INF;
  if (id == N_COINS) {
    if (sum < money) return INF;
    return coinChange(sum - money, 0);
  }
  if (~memo2[sum][id]) return memo2[sum][id];
  int ret = INF;
  for (int a = 0; a <= coin[id]; a++) {
    ret = min(ret, a + dp(sum + value[id] * a, id + 1));
  }
  return memo2[sum][id] = ret;
}

bool read () {
  int sum = 0;
  for (int i = 0; i < N_COINS; i++) {
    cin >> coin[i];
    sum += coin[i];
  }
  if (sum == 0) return false;
  int a, b;
  scanf("%d.%d", &a, &b);
  money = 100 * a + b;
  return true;
}

int main () {
  memset(memo1, -1, sizeof memo1);
  while (read()) {
    memset(memo2, -1, sizeof memo2);
    cout << setw(3) << dp(0, 0) << endl;
  }
  return (0);
}
