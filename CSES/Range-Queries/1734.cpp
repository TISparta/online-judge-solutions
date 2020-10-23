// BIT, Sorting
// 4
// 21-09-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  map <int, vi> pos;
  vi a(n + 1);
  map <int, int> last;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].pb(i);
    last[a[i]] = -1;
  }
  vi ft(n + 1, 0);
  auto update = [&] (int pos, int val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  };
  auto sum = [&] (int pos) {
    int sum = 0;
    while (pos) {
      sum += ft[pos];
      pos -= pos & -pos;
    }
    return sum;
  };
  vector <tuple <int, int, int>> query(m);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    query[i] = make_tuple(l, r, i);
  }
  for (auto pp: pos) {
    int val = pp.first;
    for (auto p: pp.second) {
      update(p, 1);
      last[val] = 0;
      break;
    }
  }
  sort(all(query));
  int cur = 1;
  vi ans(m);
  for (auto qq: query) {
    int l, r, i;
    tie(l, r, i) = qq;
    while (cur < l) {
      int j = last[a[cur]];
      int p = pos[a[cur]][j];
      update(p, -1);
      last[a[cur]] += 1;
      j += 1;
      if (j < sz(pos[a[cur]])) {
        p = pos[a[cur]][j];
        update(p, 1);
      }
      cur += 1;
    }
    ans[i] = sum(r) - sum(l - 1);
  }
  for (int ans_i: ans) cout << ans_i << '\n';
  return (0);
}
