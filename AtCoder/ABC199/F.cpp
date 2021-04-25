// Expected Value, Matrix Exponenciation
// 6.5
// 24-04-2021

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

template <class T>
struct Matrix {
  int n;
  vector <vector <T>> mat;
  Matrix () {};
  Matrix (int n): n(n), mat(vector <vector <T>> (n, vector <T> (n, 0))) {}

  void identity () {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mat[i][j] = (i == j);
  }

  void print () {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << mat[i][j] << " \n"[j + 1 == n];
      }
    }
  }

  template <class R>
  friend Matrix <R> operator * (const Matrix <R>& A, const Matrix <R>& B) {
    Matrix <R> ret(A.n);
    for (int i = 0; i < A.n; i++) {
      for (int j = 0; j < A.n; j++) {
        R ret_i = 0;
        for (int k = 0; k < A.n; k++) {
          ret_i += A.mat[i][k] * B.mat[k][j];
        }
        ret.mat[i][j] = ret_i;
      }
    }
    return ret;
  }

  template <typename R>
  friend Matrix <R> power (Matrix <R> A, ll b) {
    assert(b >= 0);
    Matrix <R> ret(A.n);
    ret.identity();
    while (b) {
      if (b & 1) ret = ret * A;
      A = A * A;
      b >>= 1;
    }
    return ret;
  }

  vector <T>& operator [] (int r) { return mat[r]; }

};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int mod = 1e9 + 7;
  Mint::set_mod(mod);
  int n, m, k;
  cin >> n >> m >> k;
  vector <Mint> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector <vi> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;
    g[u].pb(v);
    g[v].pb(u);
  }
  Matrix <Mint> mat(n);
  for (int i = 0; i < n; i++) {
    mat[i][i] = Mint(1) - Mint(sz(g[i])) / (m * 2);
    for (int v: g[i]) {
      mat[v][i] = Mint(1) / (2 * m);
    }
  }
  Matrix <Mint> Z = power(mat, k);
  for (int i = 0; i < n; i++) {
    Mint ans_i = 0;
    for (int j = 0; j < n; j++) {
      ans_i += a[j] * Z[j][i];
    }
    cout << ans_i << '\n';
  }
  return (0);
}
