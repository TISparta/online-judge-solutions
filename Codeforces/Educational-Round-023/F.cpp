// Brute Force
// 7
// 16-02-2019

#include <bits/stdc++.h>

#define all(X) begin(X), end(X)

using namespace std;

typedef unsigned long long ll;

const int B = 64;
const ll ONES = ULLONG_MAX;
const int MX = 2e5 + 10;

ll mask[MX];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  vector <ll> val;
  val.push_back(1);
  vector <pair <ll, pair <ll, ll>>> query;
  for (int i = 0; i < q; i++) {
    ll t, l, r;
    cin >> t >> l >> r;
    val.push_back(l);
    val.push_back(r + 1);
    query.push_back({t, {l, r + 1}});
  }
  sort(all(val));
  val.erase(unique(all(val)), end(val));
  for (auto pp: query) {
    ll t = pp.first;
    ll l = pp.second.first;
    ll r = pp.second.second;
    l = lower_bound(all(val), l) - begin(val);
    r = lower_bound(all(val), r) - begin(val);
    r--;
    while (l % B and l <= r) {
      if (t == 1) mask[l / B] |= 1ULL << (l % B);
      if (t == 2) mask[l / B] &= ~(1ULL << (l % B));
      if (t == 3)  mask[l / B] ^= (1ULL << (l % B));
      l++;
    }
    if (l % B == 0) {
      while (l + B <= r) {
        if (t == 1) mask[l / B] = ONES;
        if (t == 2) mask[l / B] = 0;
        if (t == 3) mask[l / B] = ~mask[l / B];
        l += B;
      }
    }
    while (l <= r) {
      if (t == 1) mask[l / B] |= 1ULL << (l % B);
      if (t == 2) mask[l / B] &= ~(1ULL << (l % B));
      if (t == 3)  mask[l / B] ^= (1ULL << (l % B));
      l++;
    }
    int ans = 0;
    while (mask[ans] == ONES) ans++;
    int bit = 0;
    for (; bit < B; bit++) if (((mask[ans] >> bit) & 1) == 0) break;
    ans = ans * B + bit;
    cout << val[ans] << '\n';
  }
  return (0);
}
