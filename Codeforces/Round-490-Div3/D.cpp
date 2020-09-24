// Greedy
// 4
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector <int> arr(n);
  vector <vector <int>> frec(m);
  int k = n / m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    frec[arr[i] % m].push_back(i);
  }
  long long ans = 0;
  vector <int> toMove;
  while (true) {
    bool ok = true;
    for (int i = 0; i < m; i++) {
      ok &= (frec[i].size() == k);
      while (frec[i].size() > k) {
        toMove.emplace_back(frec[i].back());
        frec[i].pop_back();
      }
      while (frec[i].size() < k and not toMove.empty()) {
        int id = toMove.back();
        int j = arr[id] % m;
        long long add;
        if (i >= j) add = i - j;
        else add = m - j + i;
        toMove.pop_back();
        frec[i].push_back(id);
        arr[id] += add;
        ans += add;
      }
    } 
    if (ok) break;
  }
  cout << ans << endl;
  for (int x: arr) cout << x << ' '; cout << endl;
  return  (0);
}
