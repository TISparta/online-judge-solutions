// Tags: DFS
// Difficulty: 7.0
// Priority: 1
// Date: 29-07-2021

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

// Based on tourist template: https://codeforces.com/contest/1423/submission/94770723
int mod = 1e9 + 7;

class Mint {
private:
  int value;

  template <typename T>
  static T inverse (T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
      T t = m / a;
      m -= t * a; swap(a, m);
      u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
  }

public:

  constexpr Mint (): value(0) {}

  template <class U>
  Mint (const U& x) { value = normalize(x); }

  template <class U>
  static int normalize (const U& x) {
    int ret;
    if (-mod <= x and x < mod) ret = x;
    else ret = x % mod;
    if (ret < 0) ret += mod;
    return ret;
  }

  static void set_mod (int new_mod) { mod = new_mod; }

  const int& operator ()() const { return value; }

  Mint& operator += (const Mint& other) { if ((value += other.value) >= mod) value -= mod; return *this; }
  Mint& operator -= (const Mint& other) { if ((value -= other.value) < 0) value += mod; return *this; }
  Mint& operator ++ () { return *this += 1; }
  Mint& operator -- () { return *this -= 1; }
  Mint operator ++ (int) { Mint ret(*this); *this += 1; return ret; }
  Mint operator -- (int) { Mint ret(*this); *this -= 1; return ret; }
  Mint operator - () const { return Mint(-value); }
  Mint& operator *= (const Mint& other) { value = normalize(1LL * value * other.value); return *this; }
  Mint& operator /= (const Mint& other) { return *this *= Mint(inverse(other.value, mod)); }

  friend bool operator == (const Mint& lhs, const Mint& rhs) { return lhs.value == rhs.value; }
  template <class U>
  friend bool operator == (const Mint& lhs, U rhs) { return lhs == Mint(rhs); }
  template <class U>
  friend bool operator == (U lhs, const Mint& rhs) { return Mint(lhs) == rhs; }

  friend bool operator != (const Mint& lhs, const Mint& rhs) { return not (lhs == rhs); }
  template <class U>
  friend bool operator != (const Mint& lhs, U rhs) { return not (lhs == rhs); }
  template <class U>
  friend bool operator != (U lhs, const Mint& rhs) { return not (lhs == rhs); }

  friend bool operator < (const Mint& lhs, const Mint& rhs) { return lhs.value < rhs.value; }

  friend Mint operator + (const Mint& lhs, const Mint& rhs) { return Mint(lhs) += rhs; }
  template <class U>
  friend Mint operator + (const Mint& lhs, U rhs) { return Mint(lhs) += rhs; }
  template <class U>
  friend Mint operator + (U lhs, const Mint& rhs) { return Mint(lhs) += rhs; }

  friend Mint operator - (const Mint& lhs, const Mint& rhs) { return Mint(lhs) -= rhs; }
  template <class U>
  friend Mint operator - (const Mint& lhs, U rhs) { return Mint(lhs) -= rhs; }
  template <class U>
  friend Mint operator - (U lhs, const Mint& rhs) { return Mint(lhs) -= rhs; }

  friend Mint operator * (const Mint& lhs, const Mint& rhs) { return Mint(lhs) *= rhs; }
  template <class U>
  friend Mint operator * (const Mint& lhs, U rhs) { return Mint(lhs) *= rhs; }
  template <class U>
  friend Mint operator * (U lhs, const Mint& rhs) { return Mint(lhs) *= rhs; }

  friend Mint operator / (const Mint& lhs, const Mint& rhs) { return Mint(lhs) /= rhs; }
  template <class U>
  friend Mint operator / (const Mint& lhs, U rhs) { return Mint(lhs) /= rhs; }
  template <class U>
  friend Mint operator / (U lhs, const Mint& rhs) { return Mint(lhs) /= rhs; }

  friend Mint power (Mint a, ll b) {
    assert(b >= 0);
    Mint ret = 1;
    while (b != 0) {
      if (b & 1) ret *= a;
      a *= a;
      b >>= 1;
    }
    return ret;
  }

  friend std::ostream& operator << (std::ostream& stream, const Mint& number) { return stream << number(); }

  friend std::istream& operator >> (std::istream& stream, Mint& number) {
    ll x;
    stream >> x;
    number.value = Mint::normalize(x);
    return stream;
  }

};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector <vi> g(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    const int mod = 998244353;
    Mint::set_mod(mod);
    vector <Mint> ans(n + 1, 0);
    ans[1] = power(Mint(2), n - 1);
    for (int k = 2; k <= n; k++) {
      if ((n - 1) % k) continue;
      vi dp(n + 1, 0);

      function <int(int,int)> dfs = [&] (int u, int p) {
        int ret = 1;
        for (int v: g[u]) {
          if (v != p) ret *= dfs(v, u);
        }
        if (dp[u] % k == 0) {
          if (p != -1) dp[p] += 1;
          return ret;
        }
        if (p != -1) dp[u] += 1;
        ret *= (dp[u] % k == 0);
        return ret;
      };

      ans[k] = dfs(1, -1);
    }
    for (int u = n; u >= 1; u--) {
      for (int v = u + u; v <= n; v += u) ans[u] = ans[u] - ans[v];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
  }
  return (0);
}
