// Tags: Brute Force
// Difficulty: 6.5
// Priority: 1
// Date: 07-01-2019

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <string> table;

int rowCheck (vector <string>& tmp, string pat) {
  int totalCost = 0;
  for (int row = 0; row < n; row++) {
    char a, b;
    if (row & 1) a = pat[2], b = pat[3];
    else a = pat[0], b = pat[1];
    int cost1 = 0, cost2 = 0;
    for (int col = 0; col < m; col++) {
      if (col & 1) cost1 += table[row][col] != b;
      else cost1 += table[row][col] != a;
    }
    swap(a, b);
    for (int col = 0; col < m; col++) {
      if (col & 1) cost2 += table[row][col] != b;
      else cost2 += table[row][col] != a;
    }
    totalCost += min(cost1, cost2);
    if (cost1 < cost2) swap(a, b);
    for (int col = 0; col < m; col++) tmp[row][col] = (col & 1) ? b : a;
  }
  return totalCost;
}

int colCheck (vector <string>& tmp, string pat) {
  int totalCost = 0;
  for (int col = 0; col < m; col++) {
    char a, b;
    if (col & 1) a = pat[1], b = pat[3];
    else a = pat[0], b = pat[2];
    int cost1 = 0, cost2 = 0;
    for (int row = 0; row < n; row++) {
      if (row & 1) cost1 += table[row][col] != b;
      else cost1 += table[row][col] != a;
    }
    swap(a, b);
    for (int row = 0; row < n; row++) {
      if (row & 1) cost2 += table[row][col] != b;
      else cost2 += table[row][col] != a;
    }
    if (cost1 < cost2) swap(a, b);
    totalCost += min(cost1, cost2);
    for (int row = 0; row < n; row++) tmp[row][col] = (row & 1) ? b : a;
  }
  return totalCost;
}

int main () {
  cin >> n >> m;
  table.resize(n);
  for (int row = 0; row < n; row++) cin >> table[row];
  string AGCT = "AGCT";
  int mn = n * m + 1;
  vector <string> ans;
  do {
    vector <string> tmp1(n, string(m, ' '));
    vector <string> tmp2(n, string(m, ' '));
    int ret1 = rowCheck(tmp1, AGCT);
    int ret2 = colCheck(tmp2, AGCT);
    if (ret1 <= ret2 and ret1 < mn) {
      ans = tmp1;
      mn = ret1;
    }
    if (ret2 <= ret1 and ret2 < mn) {
      ans = tmp2;
      mn = ret2;
    }
  } while (next_permutation(begin(AGCT), end(AGCT)));
  for (string row: ans) cout << row << endl;
  cerr << mn << endl;
  return (0);
}
