// Sparse Table, Binary Search
// 4
// 16-02-2019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6, LG = 21;

int n, arr[MAX_N];
int mn[MAX_N][LG], mx[MAX_N][LG];

void build () {
  for (int i = 0; i < n; i++) mn[i][0] = mx[i][0] = i;
  for (int j = 1; j < LG; j++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << j) > n) break;
      int k = i + (1 << (j - 1));
      if (arr[mn[i][j - 1]] <= arr[mn[k][j - 1]]) mn[i][j] = mn[i][j - 1];
      else mn[i][j] = mn[k][j - 1];
      if (arr[mx[i][j - 1]] <= arr[mx[k][j - 1]]) mx[i][j] = mx[k][j - 1];
      else mx[i][j] = mx[i][j - 1];
    }
  }
}

int getMin (int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  int i = mn[l][k], j = mn[r - (1 << k) + 1][k];
  return (arr[i] <= arr[j]) ? i : j;
}

int getMax (int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  int i = mx[l][k], j = mx[r - (1 << k) + 1][k];
  return (arr[i] <= arr[j]) ? j : i;
}

ll contributionMax (int i) {
  int L, R;
  {
    int l = 0, r = i;
    while (l != r) {
      int m = (l + r) >> 1;
      if (arr[getMax(m, i)] > arr[i]) l = m + 1;
      else r = m;
    }
    L = i - l + 1;
  }
  {
    int l = i, r = n - 1;
    while (l != r) {
      int m = (l + r + 1) >> 1;
      if (getMax(i, m) == i) l = m;
      else r = m - 1;
    }
    R = l - i + 1;
  }
  return 1LL * L * R;
}

ll contributionMin (int i) {
  int L, R;
  {
    int l = 0, r = i;
    while (l != r) {
      int m = (l + r) >> 1;
      if (getMin(m, i) == i) r = m;
      else l = m + 1;
    }
    L = i - l + 1;
  }
  {
    int l = i, r = n - 1;
    while (l != r) {
      int m = (l + r + 1) >> 1;
      if (arr[getMin(i, m)] < arr[i]) r = m - 1;
      else l = m;
    }
    R = l - i + 1;
  }
  return 1LL * L * R;
}

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  build();
  ll ans = 0LL;
  contributionMax(1);
  for (int i = 0; i < n; i++) {
    ans += arr[i] * contributionMax(i);
    ans -= arr[i] * contributionMin(i);
  }
  cout << ans << endl;
  return (0);
}
