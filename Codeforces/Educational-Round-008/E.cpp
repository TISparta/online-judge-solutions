// Tags: Merge Sort Tree 
// Difficulty: 7.0
// Priority: 1
// Date: 26-12-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

class STree {
private:
  int n;
  vector <vector <int>> x;
  void build (int u, int l, int r, const vector <int>& arr) {
    if (l == r) {
      x[u] = {arr[l]};
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    build(lu, l, m, arr);
    build(ru, m + 1, r, arr);
    merge(all(x[lu]), all(x[ru]), back_inserter(x[u]));
  }
  int gt (int u, int l, int r, const int L, const int R, const int val) {
    if (r < L or R < l) return 0;
    if (L <= l and r <= R) {
      if (x[u].back() <= val) return 0;
      return end(x[u]) - upper_bound(all(x[u]), val);
    }
    int m = (l + r) >> 1;
    return gt(u << 1, l, m, L, R, val) + gt(u << 1 | 1, m + 1, r, L, R, val);
  }
public:
  STree (int l, int r, const vector <int>& arr) {
    n = r;
    x.resize(4 * (n + 1));
    build(1, l, r, arr);
  }
  ~STree () {
    for (auto& row: x) row.clear();
    x.clear();
  }
  int gt (const int L, const int R, const int val) {
    return gt(1, 0, n, L, R, val);
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> l(n, vector <int> (m, 0));
  vector <vector <int>> r(n, vector <int> (m, 0));
  vector <vector <int>> d(n, vector <int> (m, 0));
  vector <string> mat(n);
  for (int i = 0; i < n; i++) cin >> mat[i];
  for (int i = 0; i < n; i++) {
    l[i][0] = (mat[i][0] == 'z');
    for (int j = 1; j < m; j++) {
      if (mat[i][j] == 'z') l[i][j] = 1 + l[i][j - 1];
      else l[i][j] = 0;
    }
    r[i][m - 1] = (mat[i][m - 1] == 'z');
    for (int j = m - 2; j >= 0; j--) {
      if (mat[i][j] == 'z') r[i][j] = 1 + r[i][j + 1];
      else r[i][j] = 0;
    }
    d[i][0] = (mat[i][0] == 'z');
    int k = 1;
    while (0 <= i - k and k < m) {
      if (mat[i - k][k] == 'z') d[i - k][k] = 1 + d[i - (k - 1)][k - 1];
      else d[i - k][k] = 0;
      k++;
    }
  }
  for (int j = 1; j < m; j++) {
    d[n - 1][j] = (mat[n - 1][j] == 'z');
    int k = 1;
    while (0 <= (n - 1) - k and j + k < m) {
      if (mat[(n - 1) - k][j + k] == 'z') d[(n - 1) - k][j + k] = 1 + d[(n - 1) - (k - 1)][j + k - 1];
      else d[(n - 1) - k][j + k] = 0;
      k++;
    }
  }
  ll ans = 0;
  for (int j = 0; j < m; j++) {
    vector <int> arr;
    int k = 0;
    // [k][j - k]
    while (k < n and 0 <= j - k) {
      arr.pb((j - k) + r[k][j - k]);
      k++;
    }
    STree tree(0, k - 1, arr);
    for (int x = 0; x < k; x++) {
      int z = min(l[x][j - x], d[x][j - x]);
      // j - k - t + r[x + t][j - x - t] > j - x, t < z
      ans += tree.gt(x, x + z - 1, j - x);
    }
  }
  for (int i = 1; i < n; i++) {
    vector <int> arr;
    int k = 0;
    // [i + k][m - 1 - k]
    while (i + k < n and 0 <= m - 1 - k) {
      arr.pb((m - 1 - k) + r[i + k][m - 1 - k]);
      k++;
    }
    STree tree(0, k - 1, arr);
    for (int x = 0; x < k; x++) {
      int z = min(l[i + x][m - 1 - x], d[i + x][m - 1 - x]);
      // m - 1 - x - t + r[i + x + t][m - 1 - x - t] > m - 1 - x, t < z
      ans += tree.gt(x, x + z - 1, m - 1 - x);
    }
  }
  cout << ans << '\n';
  return (0);
}
