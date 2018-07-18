/**
 * > Author: TISparta
 * > Date: 02-07-18
 * > Tags: Ad-Hoc
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n = 5;
  vector <long long> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long sum = accumulate(begin(arr), end(arr), 0LL);
  long long mn = LLONG_MAX, mx = LLONG_MIN;
  for (auto arr_i: arr) {
    mn = min(mn, sum - arr_i);
    mx = max(mx, sum - arr_i);
  }
  cout << mn << ' ' << mx << endl;
  return (0);
}
