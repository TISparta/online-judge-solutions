/**
 * > Author: TISparta
 * > Date: 14-08-18
 * > Tags: Recursion
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll rec (ll sum) {
  if (sum < 10) return sum;
  ll new_sum = 0;
  while (sum) new_sum += sum % 10, sum /= 10;
  return rec(new_sum);
}

ll read () {
  string n;
  ll k, sum = 0;
  cin >> n >> k;
  for (auto ch: n) sum += ch - '0';
  sum *= k;
  return sum;
}

int main () {
  cout << rec(read()) << endl;
  return (0);
}
