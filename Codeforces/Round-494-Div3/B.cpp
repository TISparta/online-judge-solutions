// Greedy
// 2
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int a, b, x;
  cin >> a >> b >> x;
  string ans;
  if (a > b) ans = "0", a--;
  else ans = "1", b--;
  while (x > 1 and a and b) {
    if (ans.back() == '1') ans += '0', a--;
    else ans += '1', b--;
    x--;
  }
  if (ans.back() == '1') {
    while (b--) ans += '1';
    while (a--) ans += '0';
  }
  else {
    while (a--) ans += '0';
    while (b--) ans += '1';
  }
  cout << ans << endl;
  return (0);
}
