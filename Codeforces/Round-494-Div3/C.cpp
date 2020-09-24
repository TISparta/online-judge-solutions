// Brute Force
// 2
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, k;
  cin >> n >> k;
  vector <int> arr(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
  double ans = 0;
  for (int i = 1; i <= n; i++) for (int j = i + k - 1; j <= n; j++) ans = max(ans, 1.0 * (arr[j] - arr[i - 1]) / (j - i + 1));
  printf("%.12f\n", ans);
  return (0);
}
