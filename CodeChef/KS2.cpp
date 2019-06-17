/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : DP, Binary Search, Greedy
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

typedef unsigned long long ll;
typedef pair <int, int> pii;

const int D = 19;
const int MAX_TC = 1e5 + 10;
const ll lim = 10000000000000000009ULL;

long long dp[10][D];
int vis[10][D];
int len;
int s[D];

inline long long rec (int pos, int res, bool flag) {
  int rpos = D - len + pos;
  if (rpos == D) return res == 0;
  if (flag and vis[res][rpos]) return dp[res][rpos];
  if (flag) vis[res][rpos] = true;
  long long ret = 0;
  if (flag) {
    for (int d = 0; d <= 9; d++) {
      ret += rec(pos + 1, (res + d >= 10) ? res + d - 10: res + d, flag);
    }
  } else {
    for (int d = 0; d <= s[pos]; d++) {
      ret += rec(pos + 1, (res + d >= 10) ? res + d - 10: res + d, d < s[pos]);
    }
  }
  if (flag) dp[res][rpos] = ret;
  return ret;
}

inline ll count (ll num) {
  len = 0;
  while (num) s[len++] = num % 10, num /= 10;
  int i = 0, j = len - 1;
  while (i < j) swap(s[i], s[j]), i++, j--;
  return rec(0, 0, 0) - 1;
}

ll tc;
pair <ll, int> arr[MAX_TC];
ll ans[MAX_TC];
ll mid;

inline ll get (ll pos, ll l = 1, ll r = lim) {
  if (r != lim) l = max(1ULL, r - 250);
  while (l != r) {
    mid = l + ((r - l) >> 1);
    if (count(mid) < pos) l = mid + 1;
    else r = mid;
  }
  return l;
}

inline void read (ll& num) {
  num = 0;
  register char ch = getchar_unlocked();
  while (ch < '0' or ch > '9') ch = getchar_unlocked();
  while ('0' <= ch and ch <= '9') {
    num = (num << 3) + (num << 1) + (ch - '0');
    ch = getchar_unlocked();
  }
}

int main () {
  read(tc);
  for (int t = 0; t < tc; t++) {
    read(arr[t].first);
    arr[t].second = t;
  }
  sort(arr, arr + tc);
  ll prev = get(arr[0].first);
  ans[arr[0].second] = prev;
  for (int i = 1; i < tc; i++) {
    ll dif = arr[i].first - arr[i - 1].first;
    ans[arr[i].second] = get(arr[i].first, prev + 89 * (dif / 9), 19 + prev + 90 * ((dif + 8) / 9));
    prev = ans[arr[i].second];
  }
  prev = ans[0];
  for (int i = 0; i < tc; i++) {
    printf("%llu\n", ans[i]);
  }
  return (0);
}
