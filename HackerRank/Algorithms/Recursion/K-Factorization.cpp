/**
 * > Author: TISparta
 * > Date: 16-08-18
 * > Tags: Backtracking
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_K = 20;

ll n, k, a[MAX_K + 10];
vector <ll> ans, used;

void print (bool found) {
  if (not found) puts("-1");
  else {
    cout << "1";
    for (ll x: ans) cout << ' ' << x;
    cout << endl;
  }
}

bool backtrack (ll prod = 1, int id = 0) {
  if (prod == n) {
    if (ans.empty() or used.size() < ans.size()) ans = used;
    return true;
  }
  if (id == k or prod * a[id] > n) return false;
  bool ret = false;
  used.push_back(prod * a[id]);
  ret |= backtrack(prod * a[id], id);
  used.pop_back();
  ret |= backtrack(prod, id + 1);
  return ret;
}

int main () {
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> a[i];
  sort(a, a + k);
  print(backtrack());
  return (0);
}
