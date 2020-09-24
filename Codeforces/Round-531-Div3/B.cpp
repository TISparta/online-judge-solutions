// Greedy
// 09-01-2019
// 2

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, k;
  cin >> n >> k;
  vector <int> a(n), ans(n);
  map <int, int> frec;
  vector <int> toColor[5010];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    toColor[a[i]].push_back(i);
  }
  int color = 1;
  bool ok = true;
  for (int i = 1; i <= 5000; i++) {
    if (toColor[i].size() > k) ok = false;
    for (int j: toColor[i]) {
      ans[j] = color;
      color++;
      if (color == k + 1) color = 1;
    }
  }
  set <int> x;
  for (int i = 0; i < n; i++) x.insert(ans[i]);
  if (x.size() != k) ok = false;
  if (not ok) puts("NO");
  else {
    puts("YES");
    for (int x: ans) cout << x << ' '; cout << endl;
  }
  return (0);
}
