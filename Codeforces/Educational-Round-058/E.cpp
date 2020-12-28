// Implementation
// 3
// 11-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int H = -1, W = -1;
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      int x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      if (H == -1) {
        W = x, H = y;
      }
      W = max(W, x);
      H = max(H, y);
    }
    else {
      int h, w;
      cin >> h >> w;
      if (w > h) swap(h ,w);
      if (h >= H and w >= W) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return (0);
}
