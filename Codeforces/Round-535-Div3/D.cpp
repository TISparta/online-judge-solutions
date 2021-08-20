// Tags: Greedy
// Difficulty: 3.0
// Priority: 5
// Date: 24-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  map <char, int> mp;
  mp['R'] = 0, mp['G'] = 1, mp['B'] = 2;
  string p = "RGB";
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      ans++;
      int id = mp[s[i]];
      if (i == n - 1) {
        s[i] = p[(id + 1) % 3];
      }
      else {
        while (p[(id + 1) % 3] == s[i + 1]) id++;
        s[i] = p[(id + 1) % 3];
      }
    }
  }
  cout << ans << endl;
  cout << s << endl;
  return (0);
}
