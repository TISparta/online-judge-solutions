// Combinatorics
// 7.2
// 21-04-2021

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
template <typename T>
T inverse (T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <class T, T mod>
class Modular {
private:
  T value;

public:
  constexpr Modular (): value(0) {}

  template <class U>
  Modular (const U& x) { value = normalize(x); }

  template <class U>
  static T normalize (const U& x) {
    T ret;
    if (-mod <= x and x < mod) ret = x;
    else ret = x % mod;
    if (ret < 0) ret += mod;
    return ret;
  }

  const T& operator ()() const { return value; }

  Modular& operator += (const Modular& other) { if ((value += other.value) >= mod) value -= mod; return *this; }
  Modular& operator -= (const Modular& other) { if ((value -= other.value) < 0) value += mod; return *this; }
  Modular& operator ++ () { return *this += 1; }
  Modular& operator -- () { return *this -= 1; }
  Modular operator ++ (int) { Modular ret(*this); *this += 1; return ret; }
  Modular operator -- (int) { Modular ret(*this); *this -= 1; return ret; }
  Modular operator - () const { return Modular(-value); }
  Modular& operator *= (const Modular& other) { value = normalize(1LL * value * other.value); return *this; }
  Modular& operator /= (const Modular& other) { return *this *= Modular(inverse(other.value, mod)); }

  template <class U, U umod>
  friend bool operator == (const Modular <U, umod>& lhs, const Modular <U, umod>& rhs);
  
  template <class U, U umod>
  friend bool operator < (const Modular <U, umod>& lhs, const Modular <U, umod>& rhs);

  template <class U, U umod>
  friend std::istream& operator >> (std::istream& stream, Modular <U, umod>& number);

};

template <class T, T mod>
bool operator == (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return lhs.value == rhs.value; }
template <class T, T mod, class U>
bool operator == (const Modular <T, mod>& lhs, U rhs) { return lhs == Modular <T, mod> (rhs); }
template <class U, class T, T mod>
bool operator == (U lhs, const Modular <T, mod>& rhs) { return Modular <T, mod> (lhs) == rhs; }

template <class T, T mod>
bool operator != (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return not (lhs == rhs); }
template <class T, T mod, class U>
bool operator != (const Modular <T, mod>& lhs, U rhs) { return not (lhs == rhs); }
template <class U, class T, T mod>
bool operator != (U lhs, const Modular <T, mod>& rhs) { return not (lhs == rhs); }

template <class T, T mod>
bool operator < (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return lhs.value < rhs.value; }

template <class T, T mod>
Modular <T, mod> operator + (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) += rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator + (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) += rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator + (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) += rhs; }

template <class T, T mod>
Modular <T, mod> operator - (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) -= rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator - (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) -= rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator - (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) -= rhs; }


template <class T, T mod>
Modular <T, mod> operator * (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) *= rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator * (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) *= rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator * (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) *= rhs; }

template <class T, T mod>
Modular <T, mod> operator / (const Modular <T, mod>& lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) /= rhs; }
template <class T, T mod, class U>
Modular <T, mod> operator / (const Modular <T, mod>& lhs, U rhs) { return Modular<T, mod> (lhs) /= rhs; }
template <class U, class T, T mod>
Modular <T, mod> operator / (U lhs, const Modular <T, mod>& rhs) { return Modular<T, mod> (lhs) /= rhs; }

template <class T, T mod, class U>
Modular <T, mod> power (Modular <T, mod> a, U b) {
  assert(b >= 0);
  Modular <T, mod> ret = 1;
  while (b != 0) {
    if (b & 1) ret *= a;
    a *= a;
    b >>= 1;
  }
  return ret;
}
template <class T, T mod, class U, U umod>
Modular <T, mod> power (Modular <T, mod> a, Modular <U, umod> b) { return power(a, b()); }
template <class U, class T, T mod>
Modular <T, mod> power (U a, Modular <T, mod> b) { return power(Modular <T, mod> (a), b()); }

template <class T, T mod>
std::ostream& operator << (std::ostream& stream, const Modular <T, mod>& number) { 
  return stream << number();
}

template <class T, T mod>
std::istream& operator >> (std::istream& stream, Modular <T, mod>& number) {
  T x;
  stream >> x;
  number.value = Modular <T, mod>::normalize(x);
  return stream;
}

// Modular Number Theory
template <class T, T mod>
struct MNT {
  using Mint = Modular <T, mod>;
  vector <Mint> fact;
  vector <Mint> inv_fact;
  vector <vector <Mint>> table;
  vector <vi> used;

  void preprocess_factorial (int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    table = vector <vector <Mint>> (n + 1, vector <Mint> (n + 1, 0));
    used = vector <vi> (n + 1, vi(n + 1, 0));
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    ll z = 1;
    inv_fact[n] = 1 / fact[n];
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1);
  }

  Mint comb (int a, int b) {
    if (a < b) return 0;
    return fact[a] * inv_fact[b] * inv_fact[a - b];
  }

  Mint comb_large (int a, int b) {
    if (a < b) return 0;
    if (used[a][b]) return table[a][b];
    used[a][b] = 1;
    Mint z = 1;
    for (int i = 0; i < b; i++) z *= (a - i);
    return table[a][b] = z * inv_fact[b];
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  const int mod = 1e9 + 7;
  using Mint = Modular <int, mod>;
  int n, k;
  cin >> n >> k;
  vector <vector <Mint>> dp(2 * k + 1, vector <Mint> (2 * k + 1, 0));
  for (int i = 1; i <= 2 * k; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= 2 * k; j++) {
      dp[i][j] = dp[i - 1][j] + (i - 1) * dp[i - 1][j - 1];
    }
  }
  MNT <int, mod> mnt;
  mnt.preprocess_factorial(2 * k);
  vector <Mint> ans(k + 1, 0);
  ans[0] = 1;
  vector <Mint> rf(2 * k + 1);
  Mint z = 1;
  for (int i = 0; i <= 2 * k; i++) {
    z *= (n - i);
    rf[i] = z;
  }
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i <= min(n, 2 * k); i++) {
      Mint sum = 0;
      for (int f = 0; f <= i; f++) {
        Mint sign = (f & 1) ? -1 : +1;
        sum += sign * mnt.comb_large(i, f) * dp[i - f][j];
      }
      ans[j] += sum * rf[i - 1] * mnt.inv_fact[i];;
    }
    if (j >= 2) ans[j] += ans[j - 2];
    cout << ans[j] << " \n"[j == k];
  }
  return (0);
}
