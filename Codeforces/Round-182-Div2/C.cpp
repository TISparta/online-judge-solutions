// Tags: Constructive Algorithms
// Difficulty: 3.5
// Priority: 1
// Date: 01-08-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i + 1;
  }
  b.back() = 0;
  vector <int> c(n);
  set <int> used;
  for (int i = 0; i < n; i++) {
    c[i] = (a[i] + b[i]) % n;
    used.insert(c[i]);
  }
  if (sz(used) != n) {
    cout << -1 << '\n';
    return (0);
  }
  for (int elem: a) cout << elem << ' '; cout << '\n';
  for (int elem: b) cout << elem << ' '; cout << '\n';
  for (int elem: c) cout << elem << ' '; cout << '\n';
  return (0);
}
