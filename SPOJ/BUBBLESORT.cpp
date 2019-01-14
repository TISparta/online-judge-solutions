/**
 * > Author: TISparta
 * > Date: 12-09-18
 * > Tags: BIT
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

#define all(X) begin(X), end(X)

using namespace std;

const int MAX_N = 1e4 + 10, MOD = 1e7 + 7;

struct BIT {
  int* ft;
  int sz = 0;
  BIT (int n): sz(n) {
    ft = new int[n];
    fill(ft, ft + n, 0);
  }
  ~BIT () {
    delete[] ft;
  }
  int get (int pos) {
    int ret = 0;
    while (pos) {
      ret += ft[pos];
      pos = pos bitand (pos - 1);
    }
    return ret;
  }
  void update (int pos, const int inc) {
    while (pos < sz) {
      ft[pos] += inc;
      pos = (pos bitor (pos - 1)) + 1;
    }
  }
  int getRightSum (int a) {
    return get(sz - 1) - get(a - 1);
  }
};

int n, arr[MAX_N + 10];

int solve () {
  BIT* ft = new BIT(n + 10);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + ft -> getRightSum(arr[i] + 1)) % MOD;
    ft -> update(arr[i], 1);
  }
  delete ft;
  return ans % MOD;
}

void compress () {
  vector <int> x(arr, arr + n);
  sort(all(x));
  x.erase(unique(all(x)), end(x));
  for (int i = 0; i < n; i++) arr[i] = lower_bound(all(x), arr[i]) - begin(x) + 1;
}

void read () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
}

int main () {
  int tc;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; t++) {
    read();
    compress();
    printf("Case %d: %d\n", t, solve());
  }
  return (0);
}
