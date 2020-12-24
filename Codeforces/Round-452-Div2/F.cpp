// BIT, Binary Search
// 5
// 24-11-2020

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

template <typename T = int>
struct BIT {
  vector <T> ft;
  BIT (int n): ft(n + 2, 0) {}
  void update (int pos, T val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  }
  void update (int l, int r, T val) {
    if (l > r) return;
    update(l, val);
    update(r + 1, -val);
  }
  T sum (int pos) {
    T ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos & -pos;
    }
    return ret;
  }
  T sum (int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  auto to = [&] (char ch) -> int {
    if ('a' <= ch and ch <= 'z') return ch - 'a';
    if ('A' <= ch and ch <= 'Z') return (ch - 'A') + 26;
    if ('0' <= ch and ch <= '9') return (ch - '0') + 52;
    assert(1 == 0);
  };
  const int SIGMA = 66;
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector <set <int>> pos(SIGMA);
  for (int i = 1; i <= n; i++) {
    pos[to(s[i - 1])].emplace(i);
  }
  BIT <int> ft(n);
  auto get_index = [&] (int x) {
    int l = 1, r = n;
    while (l != r) {
      int m = (l + r) >> 1;
      if (x <= m - ft.sum(m)) r = m;
      else l = m + 1;
    }
    return l;
  };
  for (int i = 0; i < m; i++) {
    int l, r;
    char ch;
    cin >> l >> r >> ch;
    int x = to(ch);
    l = get_index(l);
    r = get_index(r);
    for (auto it = pos[x].lower_bound(l); it != end(pos[x]) and *it <= r;) {
      int y = *it;
      ft.update(*it, 1);
      it = pos[x].erase(it);
    }
  }
  vi alive(n + 1, false);
  for (auto row: pos) {
    for (int x: row) {
      alive[x] = true;
    }
  }
  string ans = "";
  for (int i = 1; i <= n; i++) {
    if (alive[i]) ans += s[i - 1];
  }
  cout << ans << '\n';
  return (0);
}
