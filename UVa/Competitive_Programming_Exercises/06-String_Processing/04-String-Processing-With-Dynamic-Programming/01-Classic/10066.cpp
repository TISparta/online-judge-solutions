#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e2 + 10;

int n1, n2, arr1[MAX_N], arr2[MAX_N], dp[MAX_N][MAX_N];

int lcs () {
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (arr1[i - 1] == arr2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[n1][n2];
}

int main () {
  int tc = 0;
  while (cin >> n1 >> n2, n1 or n2) {
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    for (int i = 0; i < n2; i++) cin >> arr2[i];
    printf("Twin Towers #%d\n", ++tc);
    printf("Number of Tiles : %d\n", lcs());
    puts("");
  }
  return (0);
}
