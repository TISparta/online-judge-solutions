// Ad-Hoc
// 1
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, k;
  cin >> n >> k;
  deque <int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 0;
  while (not arr.empty() and arr.front() <= k) arr.pop_front(), ans++;
  while (not arr.empty() and arr.back() <= k) arr.pop_back(), ans++;
  cout << ans << endl;
  return  (0);
}
