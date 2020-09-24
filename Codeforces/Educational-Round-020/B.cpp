// Ad-Hoc
// 2
// 07-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector <int> arr(n), left(n), right(n);
  int last = -1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) last = i;
    left[i] = last;
  }
  last = -1;
  for (int i = n - 1; i >= 0; i--) {
    cin >> arr[i];
    if (arr[i] == 0) last = i;
    right[i] = last;
  }
  for (int i = 0; i < n; i++) {
    int ans = INT_MAX;
    if (~left[i]) ans = min(ans, i - left[i]);
    if (~right[i]) ans = min(ans, right[i] - i);
    cout << ans << ' ';
  }
  cout << endl;
  return (0);
}
