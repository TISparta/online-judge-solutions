// Implementation
// 2
// 07-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, k;
  cin >> n >> k;
  vector <vector <int>> mat(n, vector <int> (n, 0));
  if (k > n * n) {
    cout << -1 << endl;
    return (0);
  }
  int i = 0;
  while (i < n and k > 0) {
    mat[i][i] = 1;
    k--;
    int j = i + 1;
    while (j < n and k >= 2) {
      mat[i][j] = mat[j][i] = 1;
      k -= 2;
      j++;
    }
    i++;
  }
  for (auto row: mat) {
    for (auto col: row) cout << col << ' ';
    cout << endl;
  }
  return (0);
}
