// Mo Algorithm
// 5.5
// 19-04-2021

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

// Query in 0-indexing
int B;
struct Mo {
  struct Query {
    int l, r, id;
    Query () {}
    Query (int l, int r, int id): l(l), r(r), id(id) {}
    bool operator < (const Query& other) const {
      int x = l / B;
      int y = other.l / B;
      if (x != y) return x < y;
      return r < other.r;
    };
  };
  
  int n, q;
  vi a;
  vi frec;
  vi cnt;
  int mx = 0;

  vector <Query> query;
  Mo (int n, int q, vi a): n(n), q(q), a(a) {
    B = 1 + sqrt(n);
    query.reserve(q);
  };

  void add_query (int l, int r) {
    query.emplace_back(l, r, sz(query));
  };

  void add (int x) {
    frec[cnt[x]] -= 1;
    cnt[x] += 1;
    assert(cnt[x] <= n);
    frec[cnt[x]] += 1;
    mx = max(mx, cnt[x]);
  }

  void remove (int x) {
    frec[cnt[x]] -= 1;
    cnt[x] -= 1;
    assert(0 <= cnt[x]);
    frec[cnt[x]] += 1;
    if (frec[mx] == 0) mx--;
  };

  void solve (vi& ans) {
    frec = vi(n + 1, 0);
    cnt = vi(n + 1, 0);
    sort(all(query));
    int L = 0, R = -1;
    for (auto [l, r, i]: query) {
      while (L > l) add(a[--L]);
      while (R < r) add(a[++R]);
      while (L < l) remove(a[L++]);
      while (R > r) remove(a[R--]);
      int z = r - l + 1;
      int limit = (z + 1) / 2;
      if (mx <= limit) {
        ans[i] = 1;
      } else {
        if (mx == z) {
          ans[i] = z;
        } else {
          ans[i] = 1 + 2 * mx - z - 1;
        }
      }
    }
  };

};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n);
  vector <vi> pos(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  Mo mo(n, q, a);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    mo.add_query(--l, --r);
  }
  vi ans(q);
  mo.solve(ans);
  for (int ans_i: ans) cout << ans_i << '\n';
  return (0);
}
