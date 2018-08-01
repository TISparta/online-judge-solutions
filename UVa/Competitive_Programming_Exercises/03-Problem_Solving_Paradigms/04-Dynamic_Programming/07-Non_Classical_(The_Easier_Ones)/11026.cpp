#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1000 + 10;

ll n, m, arr[MAX_N], memo[MAX_N][MAX_N];

ll dp () {
  for (int i = 0; i <= n; i++) memo[i][0] = 1;
  for (int i = 1; i <= n + 1; i++)
    for (int j = 0; j <= n; j++)
      memo[i][j] = (memo[i - 1][j] + (memo[i - 1][j - 1] * arr[i - 1]) % m) % m;
  ll ans = 0;
  for (int j = 1; j <= n; j++) ans = max(ans, memo[n][j] % m);
  return ans;
}

int main () {
  while (cin >> n >> m, n + m) {
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      arr[i] %= m;
    }
    cout << dp() << endl;
  }
  return (0);
}
