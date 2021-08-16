// Tags: FFT
// Difficulty: 6.5
// Priority: 1
// Date: 27-12-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int mod = 998244353;
const int PR = 3;

int modPow(int a, int b, int mod)
{
  int ret = 1;
  while (b) {
    if (b & 1)
      ret = (1LL * ret * a) % mod;
    b >>= 1;
    a = (1LL * a * a) % mod;
  }
  return ret;
}

int inverse(int a, int mod) { return modPow(a, mod - 2, mod); }

void fft1(vector<int>& a, bool invert)
{
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;

    if (i < j)
      swap(a[i], a[j]);
  }

  for (int t = 2; t <= n; t <<= 1) {
    long long bw = modPow(PR, (mod - 1) / t, mod);
    if (invert)
      bw = inverse(bw, mod);
    for (int i = 0; i < n; i += t) {
      long long w = 1;
      for (int j = 0; j < t / 2; ++j) {
        int j1 = i + j, j2 = i + j + t / 2;
        long long c1 = a[j1], c2 = a[j2] * w % mod;
        a[j1] = c1 + c2;
        a[j2] = c1 - c2 + mod;
        while (a[j1] >= mod)
          a[j1] -= mod;
        while (a[j2] >= mod)
          a[j2] -= mod;
        w = w * bw % mod;
      }
    }
  }
  if (invert) {
    int n_1 = inverse(n, mod);
    for (int& x : a)
      x = (int)(1LL * x * n_1 % mod);
  }
}

const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

void fft2(vector<int>& a, bool invert)
{
  int n = a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;

    if (i < j)
      swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1)
      wlen = (int)(1LL * wlen * wlen % mod);

    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % mod);
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
        w = (int)(1LL * w * wlen % mod);
      }
    }
  }

  if (invert) {
    int n_1 = inverse(n, mod);
    for (int& x : a)
      x = (int)(1LL * x * n_1 % mod);
  }
}

vector<int> compute(vector<int> const& a, int k, bool flag)
{
  vector<int> fa(all(a));
  if (flag)
    fft1(fa, false);
  else
    fft2(fa, false);
  for (int i = 0; i < sz(fa); i++) {
    fa[i] = modPow(fa[i], k, mod);
  }
  if (flag)
    fft1(fa, true);
  else
    fft2(fa, true);
  return fa;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  const int N = 1e3 + 1;
  int m = 1;
  while (m < N * k)
    m <<= 1;
  vector<int> poly(m, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    poly[a] = 1;
  }
  vector <int> r1 = compute(poly, k, true);
  mod = 7340033;
  vector <int> r2 = compute(poly, k, false);
  bool first = true;
  for (int i = 0; i < sz(poly); i++) {
    if (r1[i] == 0 and r2[i] == 0)
      continue;
    if (!first)
      cout << ' ';
    first = false;
    cout << i;
  }
  cout << '\n';
  return (0);
}
