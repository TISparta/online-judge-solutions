// Interactive
// 7.1
// 20-04-2021

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto ask1 = [&] (int a, int b) {
      cout << 1 << ' ' << a << ' ' << b << endl;
      int res;
      cin >> res;
      assert(res != -1);
      return res;
    };
    vi order(n);
    iota(all(order), 0);
    stable_sort(all(order), ask1);
    int p = n - 2;
    vector <vi> ans(n, vi(n, 1));
    auto ask2 = [&] (int x, vi s) {
      cout << 2 << ' ' << x << ' ' << sz(s);
      for (int si: s) cout << ' ' << si;
      cout << endl;
      int res;
      cin >> res;
      assert(res != -1);
      return res;
    };
    for (int i = n - 1; i >= 0; i--) {
      // order[i] can go until order[p]
      if (p == i) {
        for (int j = 0; j <= i; j++) {
          for (int k = i + 1; k < n; k++) {
            ans[order[k]][order[j]] = 0;
          }
        }
        p -= 1;
      }
      vi z;
      for (int j = 0; j <= p; j++) z.pb(order[j]);
      while (ask2(order[i], z)) {
        p -= 1;
        z.pop_back();
      }
    }
    cout << 3 << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << ans[i][j];
      if (i + 1 == n) cout << endl;
      else cout << '\n';
    }
    int res;
    cin >> res;
    assert(res != -1);
  }
  return (0);
}
