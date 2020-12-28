// Sorting
// 3
// 11-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector <pair <pair <int, int>, int>> arr(n);
    vector <int> group(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i].first.first >> arr[i].first.second;
      arr[i].second = i;
    }
    sort(begin(arr), end(arr));
    vector <pair <int, int>> one, two;
    bool ok = true;
    one.push_back(arr[0].first);
    int mx1 = arr[0].first.second, mx2 = -1;
    group[arr[0].second] = 1;
    for (int i = 1; i < n; i++) {
      int l = arr[i].first.first, r = arr[i].first.second;
      if (l <= mx1) {
        if (not two.empty() and l <= mx2) ok = false;
        one.push_back(arr[i].first);
        mx1 = max(mx1, arr[i].first.second);
        group[arr[i].second] = 1;
      }
      else {
        two.push_back(arr[i].first);
        group[arr[i].second] = 2;
        mx2 = max(mx2, arr[i].first.second);
      }
    }
    if (two.empty()) ok = false;
    if (not ok) cout << -1 << endl;
    else {
      for (int i = 0; i < n; i++) cout << group[i] << ' '; cout << endl;
    }
  }
  return (0);
}
