// Brute Force, Number Theory
// 5
// 20-01-2019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// [X]_k = UNION [d]_(k - 1) / d | X
// Si X es primo -> [X]_k = [1] * k UNION [X]

const int MX = 1e5;

typedef long long ll;

vector <ll> divisors[MX];
map <ll, vector <ll>> memo;

vector <ll>& getDivisors (ll X) {
  if (X < MX) return divisors[X];
  if (memo.count(X)) return memo[X];
  vector <ll> ret;
  for (ll d = 1; d * d <= X; d++) {
    if (X % d == 0) {
      ret.push_back(d);
      if (d != X / d) ret.push_back(X / d);
    }
  }
  sort(begin(ret), end(ret));
  return memo[X] = ret;
}

int printed = 0;

void rec (ll X, ll k) {
  if (printed == MX) return;
  if (k == 0 or X == 1) {
    cout << X << ' ';
    printed++;
    return;
  }
  vector <ll>& D = getDivisors(X);
  if (D.size() == 2) {
    for (int i = 0; i < k and printed < MX; i++) {
      cout << 1 << ' ';
      printed++;
    }
    if (printed < MX) {
      cout << X << ' ';
      printed++;
    }
    return;  
  }
  for (ll d: D) rec(d, k - 1);
}

int main () {
  for (int u = 1; u < MX; u++) for (int v = u; v < MX; v += u) divisors[v].push_back(u);
  ll X, k;
  cin >> X >> k;
  rec(X, k);
  return (0);
}
