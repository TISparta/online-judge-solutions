// Tags: Implementation
// Difficulty: 1.0
// Priority: 5
// Date: 07-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_H = 110;

int stone[MAX_H];

int main () {
  int w, h;
  cin >> w >> h;
  for (int i = 0; i < 2; i++) {
    int u, d;
    cin >> u >> d;
    stone[d] = u;
  }
  for (int H = h; H >= 0; H--) {
    w += H;
    w -= stone[H];
    w = max(0, w);
  }
  cout << w << endl;
  return (0);
}
