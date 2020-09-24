// Brute Force
// 2
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, k;
  string s;
  cin >> n >> k >> s;
  set <pair <char, int>> Q;
  for (int i = 0; i < n; i++) Q.insert({s[i], i});
  while (k--) Q.erase(begin(Q));
  vector <pair <int, char>> ans;
  for (auto x: Q) ans.push_back({x.second, x.first});
  sort(begin(ans), end(ans));
  for (auto x: ans) cout << x.second;
  cout << endl;
  return  (0);
}
