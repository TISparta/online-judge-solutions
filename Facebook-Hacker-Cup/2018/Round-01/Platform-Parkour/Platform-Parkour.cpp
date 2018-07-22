/**
 * > Author: TISparta
 * > Date: 21-07-18
 * > Tags: Binary Search
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10, MAX_M = 20 + 10, N_ITERATIONS = 80, INF = 1e9;

long long n, m, w, x, y, z, h[MAX_N], a[MAX_M], b[MAX_M], u[MAX_M], d[MAX_M], jump_u[MAX_N], jump_d[MAX_N];
long double lo_h[MAX_N], hi_h[MAX_N];

bool valid (long double t) {
  for (int i = 1; i <= n; i++) {
    lo_h[i] = max((long double)0, h[i] - t);
    hi_h[i] = h[i] + t;
  }
  for (int i = 2; i <= n; i++) {
    lo_h[i] = max(lo_h[i], lo_h[i - 1] - jump_d[i - 1]);
    hi_h[i] = min(hi_h[i], hi_h[i - 1] + jump_u[i - 1]);
    if (lo_h[i] > hi_h[i]) return false;
  }
  return true;
}

void preprocess () {
  for (int i = 1; i <= n; i++) {
    long long _d = INF, _u = INF;
    for (int j = 1; j <= m; j++) {
      if (a[j] <= i and i < b[j]) {
        _d = min(_d, d[j]);
        _u = min(_u, u[j]);
      }
    }
    jump_d[i] = _d;
    jump_u[i] = _u;
  }
}

long double solve () {
  preprocess();
  long double lo = 0, hi = 1e7, mid;
  for (int it = 0; it < N_ITERATIONS; it++) {
    mid = (lo + hi) / 2.0;
    valid(mid) ? hi = mid : lo = mid;
  }
  return (lo + hi) / 2.0;
}

void readCase () {
  cin >> n >> m;
  cin >> h[1] >> h[2] >> w >> x >> y >> z;
  for (int i = 3; i <= n; i++) h[i] = ((w * h[i - 2]) % z + (x * h[i - 1]) % z + y) % z;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> u[i] >> d[i];
    if (a[i] > b[i]) swap(a[i], b[i]), swap(u[i], d[i]);
  }
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    readCase();
    printf("Case #%d: %.12Lf\n", t, solve());
  }
  return (0);
}
