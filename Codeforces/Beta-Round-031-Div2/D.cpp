// Recursion
// 4
// 11-09-2018

#include <bits/stdc++.h>

using namespace std;

const int MX = 100 + 10;

bool xCut[MX][MX][MX], yCut[MX][MX][MX];
vector <int> ans;

void rec (int X1, int Y1, int X2, int Y2) {
  for (int i = X1 + 1; i < X2; i++) {
    if (xCut[i][Y1][Y2]) {
      rec(X1, Y1, i, Y2);
      rec(i, Y1, X2, Y2);
      return;
    }
  }
  for (int j = Y1 + 1; j < Y2; j++) {
    if (yCut[j][X1][X2]) {
      rec(X1, Y1, X2, j);
      rec(X1, j, X2, Y2);
      return;
    }
  }
  ans.push_back((X2 - X1) * (Y2 - Y1));
}

int main () {
  int w, h, n, X1, X2, Y1, Y2;
  cin >> w >> h >> n;
  for (int i = 0; i < n; i++) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1 == X2) xCut[X1][Y1][Y2] = true;
    if (Y1 == Y2) yCut[Y1][X1][X2] = true;
  }
  rec(0, 0, w, h);
  sort(begin(ans), end(ans));
  for (auto ans_i: ans) cout << ans_i << ' '; cout << endl;
  return (0);
}
