// Brute Force
// 1
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 0;
  while (not arr.empty()) {
    set <int> tmp;
    for (int i = arr.size() - 1; i >= 0; i--) {
      if (tmp.count(arr[i]) == 0) {
        tmp.insert(arr[i]);
        arr.erase(begin(arr) + i);
      }
    }
    ans++;
  }
  cout << ans << endl;
  return (0);
}
