// Tags: Brute Force
// Difficulty: 3.5
// Priority: 4
// Date: 24-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  vector <pair <int, int>> seg(m + 1);
  for (int i = 1; i <= m; i++) cin >> seg[i].first >> seg[i].second;
  int ans = INT_MIN;
  vector <int> applied;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int mx = arr[i];
      int mn = arr[j];
      vector <int> tmp;
      for (int k = 1; k <= m; k++) {
        int l = seg[k].first, r = seg[k].second;
        if ((l <= j and j <= r) and not (l <= i and i <= r)) {
          mn--;
          tmp.push_back(k);
        }
      }
      if (mx - mn > ans) {
        ans = mx - mn;
        applied = tmp;
      }
    }
  }
  cout << ans << endl;
  cout << applied.size() << endl;
  for (int elem: applied) cout << elem << ' '; cout << endl;
  return (0);
}
