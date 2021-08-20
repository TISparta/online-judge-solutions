// Tags: Brute Force
// Difficulty: 3.0
// Priority: 3
// Date: 24-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector <char> p = {0, 1, 2};
  string X = "RGB";
  int mn = INT_MAX;
  string ans;
  do {
    int cnt = 0;
    for (int i = 0; i < 3 and i < s.size(); i++) {
      for (int j = i; j < s.size(); j += 3) {
        cnt += s[j] != X[p[i]];
      }
    }
    if (cnt < mn) {
      mn = cnt;
      string ret = "";
      for (int k = 0; k < s.size(); k++) {
        ret += X[p[k % 3]];
      }
      ans = ret;
    }
  } while (next_permutation(begin(p), end(p)));
  cout << mn << endl;
  cout << ans << endl;
  return (0);
}
