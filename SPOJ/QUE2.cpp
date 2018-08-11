/**
 * > Author : TISparta
 * > Date : 10-08-18
 * > Tags : BIT, Binary Search
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 10;

struct BIT {
  vector <int> ft;
  BIT () {}
  BIT (int n) {
    ft.resize(n + 10);
  }
  void update (int pos, int val) {
    while (pos < ft.size()) {
      ft[pos] += val;
      pos = (pos bitor (pos - 1)) + 1;
    }
  }
  int get (int pos) {
    int ret = 0;
    while (pos) {
      ret += ft[pos];
      pos = pos bitand (pos - 1);
    }
    return ret;
  }
  int binary (int k) {
    int l = 1, r = ft.size() - 1;
    while (l < r) {
      int m = (l + r) >> 1;
      (k <= get(m)) ? r = m : l = m + 1;
    }
    return l;
  }
};

int n, ans[MAX_N];
pair <int, int> arr[MAX_N];

void print () {
  printf("%d", ans[1]);
  for (int i = 2; i <= n; i++) printf(" %d", ans[i]);
  puts("");
}

void solve () {
  BIT ft(n);
  for (int i = 1; i <= n; i++) ft.update(i, 1);
  sort(arr + 1, arr + n + 1);
  ans[arr[1].second + 1] = arr[1].first;
  ft.update(arr[1].second + 1, -1);
  for (int i = 2; i <= n; i++) {
    int pos = ft.binary(arr[i].second + 1);
    ans[pos] = arr[i].first;
    ft.update(pos, -1);
  }
}

void readCase () {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i].first);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i].second);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    readCase();
    solve();
    print();
  }
  return (0);
}
