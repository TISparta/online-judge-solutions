// Tags: Implementation
// Difficulty: 3.0
// Priority: 5
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
  int k1;
  cin >> k1;
  deque <int> a(k1);
  for (int i = 0; i < k1; i++) cin >> a[i];
  int k2;
  cin >> k2;
  deque <int> b(k2);
  for (int i = 0; i < k2; i++) cin >> b[i];
  set <pair <deque <int>, deque <int>>> used;
  int it = 0;
  while (true) {
    if (used.count({a, b})) {
      cout << -1 << '\n';
      return (0);
    }
    used.insert({a, b});
    it++;
    int x = a.front();
    int y = b.front();
    a.pop_front();
    b.pop_front();
    if (x > y) {
      a.push_back(y);
      a.push_back(x);
    } else {
      b.push_back(x);
      b.push_back(y);
    }
    if (a.empty()) {
      cout << it << ' ' << 2 << '\n';
      return (0);
    }
    if (b.empty()) {
      cout << it << ' ' << 1 << '\n';
      return (0);
    }
  }
  return (0);
}
