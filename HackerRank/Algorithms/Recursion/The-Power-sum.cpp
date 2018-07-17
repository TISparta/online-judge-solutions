/**
 * > Author: TISparta
 * > Date: 14-08-18
 * > Tags: Recursion
 * > Difficulty: 2 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll X, N;

int rec (ll a, ll sum) {
  if (sum >= X) return sum == X;
  ll pib = pow(a, N);
  if (sum + pib > X) return 0;
  return rec(a + 1, sum + pib) + rec(a + 1, sum);
}

int main () {
  cin >> X >> N;
  cout << rec(1, 0) << endl;
  return (0);
}
