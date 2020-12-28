// Math
// 1
// 11-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int q;
  cin >> q;
  while (q--) {
    long long l, r, d;
    cin >> l >> r >> d;
    if (d < l) {
      cout << d << endl;
    }
    else {
      long long x = r / d;
      while (x * d <= r) {
        x++;
      }
      cout << x * d << endl;
    }
  }
  return (0);
}
