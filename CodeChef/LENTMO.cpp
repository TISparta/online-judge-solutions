/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : DP
 * > Difficulty : 5 / 10
 */

#pragma comment (linker,"/STACK:1024000000")
#pragma GCC optimize(2)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAX_N = 1e4 + 10;
const int PRUNING = 1000;

int n, k;
bool vis[MAX_N];
set <int> go[2];

void rec (int ones) {
  if (vis[ones]) return;
  vis[ones] = true;
  go[ones & 1].erase(ones);
  int zeros = n - ones;
  int r1 = ones + k - 2 * max(1, k - zeros);
  int l1 = ones + k - 2 * min(ones, k);
  for (int n_ones = l1; n_ones <= r1; n_ones += 2) {
    if (vis[n_ones]) {
      auto it = go[n_ones & 1].lower_bound(n_ones);
      if (it == end(go[n_ones & 1]) or r1 < *it) break;
      n_ones = *it;
    }
    rec(n_ones);
  }
  int l2 = ones - k + 2 * max(1, k - ones);
  int r2 = ones - k + 2 * min(zeros, k);
  for (int n_ones = l2; n_ones <= r2; n_ones += 2) {
    if (vis[n_ones]) {
      auto it = go[n_ones & 1].lower_bound(n_ones);
      if (it == end(go[n_ones & 1]) or r2 < *it) break;
      n_ones = *it;
    }
    rec(n_ones);
  }
};

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    vector <int> arr(n);
    ll sum = 0LL;
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      sum += arr[i];
    }
    int x;
    scanf("%d %d", &k, &x);
    vector <int> diff(n);
    go[0].clear(), go[1].clear();
    for (int i = 0; i < n; i++) {
      int val = arr[i] ^ x;
      diff[i] = val - arr[i];
      vis[i] = false;
      go[i & 1].insert(i);
    }
    go[n & 1].insert(n);
    vis[n] = false;
    sort(rall(diff));
    rec(0);
    ll ans = sum;
    ll acc = 0LL;
    for (int ones = 0; ones <= n; ones++) {
      if (vis[ones]) ans = max(ans, sum + acc);
      acc += diff[ones];
    }
    printf("%lld\n", ans);
  }
  return (0);
}
