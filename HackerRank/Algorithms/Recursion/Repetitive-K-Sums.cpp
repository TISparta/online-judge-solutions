/**
 * > Author: TISparta
 * > Date: 17-08-18
 * > Tags: Backtracking, Combinatorics
 * > Difficulty: 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int MAX_N = 1e5;

ull n, k, a[MAX_N + 10];
multiset <ull> s;

void print () {
  cout << a[0];
  for (int i = 1; i < n; i++) cout << ' ' << a[i];
  cout << endl;
}

void deleteCombinations (int id, int mx_id, int used, ull s_i) {
  if (id > mx_id) return;
  if (used == k) {
    s.erase(s.find(s_i));
    return;
  }
  deleteCombinations(id, mx_id, used + 1, s_i + a[id]);
  deleteCombinations(id + 1, mx_id, used, s_i);
}

void solve () {
  a[0] = (*begin(s)) / k;
  s.erase(begin(s));
  for (int i = 1; i < n; i++) {
    a[i] = (*begin(s)) - (k - 1) * a[0];
    deleteCombinations(0, i, 1, a[i]);
  }
}

void readCase () {
  cin >> n >> k;
  cin.ignore();
  string line;
  getline(cin, line);
  istringstream token(line);
  ull s_i;
  while (token >> s_i) s.insert(s_i);
}

inline void initCase () {
  s.clear();
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    initCase();
    readCase();
    solve();
    print();
  }
  return (0);
}
