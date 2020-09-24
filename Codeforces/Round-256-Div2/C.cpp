// Divide and Conquer
// 4
// 20-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e3 + 10;

int arr[MAX_N];

int solve (int l, int r) {
  if (l > r) return 0;
  int cut = r - l + 1;
  int mn = arr[l];
  for (int i = l; i <= r; i++) {
    mn = min(mn, arr[i]);
  }
  vector <int> zero;
  for (int i = l; i <= r; i++) {
    arr[i] -= mn;
    if (arr[i] == 0) zero.push_back(i);
  }
  zero.push_back(r + 1);
  int res = mn, prev = l;
  for (int cur: zero) {
    res += solve(prev, cur - 1);
    prev = cur + 1;
  }
  return min(cut, res);
}

int main () {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  cout << solve(1, n) << endl;
  return (0);
}
