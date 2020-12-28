// Implementation
// 2
// 11-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  string s;
  cin >> s;
  int open = -1, closed = -1;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '[') {
      open = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == ']') {
      closed = i;
      break;
    }
  }
  if (open == -1 or closed == -1 or open > closed) {
    cout << -1 << endl;
    return (0);
  }
  int a = -1, b = -1;
  for (int i = open + 1; i < closed; i++) {
    if (s[i] == ':') {
      a = i;
      break;
    }
  }
  for (int i = closed - 1; i > open; i--) {
    if (s[i] == ':') {
      b = i;
      break;
    }
  }
  if (a == -1 or b == -1 or a >= b) {
    cout << -1 << endl;
    return (0);
  }
  int ans = closed - open + 1;
  for (int i = open + 1; i < closed; i++) {
    if (i == a or i == b) continue;
    if (i < a) ans--;
    if (i > b) ans--;
    if (a < i and i < b and s[i] != '|') ans--;
  }
  cout << ans << endl;
  return (0);
}
