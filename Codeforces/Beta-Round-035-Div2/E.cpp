/**
 * > Author: TISparta
 * > Date: 24-12-18
 * > Tags: Sweep Line
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  map <int, vector <int>> mp;
  for (int i = 0; i < n; i++) {
    int h, l, r;
    cin >> h >> l >> r;
    mp[l].push_back(h);
    mp[r].push_back(-h);
  }
  multiset <int> H;
  int h = 0;
  vector <pair <int, int>> ans;
  for (auto pp: mp) {
    int x = pp.first;
    for (int y: mp[x]) {
      if (y > 0) H.insert(y);
      else H.erase(H.find(-y));
    }
    int nh = H.empty() ? 0 : *H.rbegin();
    if (h != nh) {
      ans.push_back({x, h});
      ans.push_back({x, nh});
      h = nh;
    }
  }
  cout << int(ans.size()) << endl;
  for (auto pp: ans) cout << pp.first << ' ' << pp.second << '\n';
  return (0);
}
