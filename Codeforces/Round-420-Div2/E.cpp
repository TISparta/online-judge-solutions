// Matrix Multiplicatino
// 4
// 29-12-2018

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

inline ll add (const ll& a, const ll& b) { return (a + b) % MOD; }
inline ll mul (const ll& a, const ll& b) { return (a * b) % MOD; }

struct Matrix {
  int n;
  vector <vector <int>> M;
  Matrix () {};
  Matrix (int n): n(n), M(vector <vector <int>> (n, vector <int> (n, 0))) {}
  void identity () { for (int i = 0; i < n; i++) M[i][i] = 1; }
};

deque <int> operator * (const Matrix& A, deque <int>& X) {
  deque <int> ret;
  for (int r = 0; r < A.n; r++) {
    ll ret_c = 0LL;
    for (int c = 0; c < A.n; c++) ret_c = add(ret_c, mul(A.M[r][c], X[c]));
    ret.push_back(ret_c);
  }
  return ret;
}

Matrix operator * (const Matrix& A, const Matrix& B) {
  Matrix ret(A.n);
  for (int i = 0; i < A.n; i++) {
    for (int j = 0; j < A.n; j++) {
      ll ret_i = 0LL;
      for (int k = 0; k < A.n; k++) ret_i = add(ret_i, mul(A.M[i][k], B.M[k][j]));
      ret.M[i][j] = ret_i;
    }
  }
  return ret;
}

Matrix pow (Matrix A, ll B) {
  Matrix ret(A.n);
  ret.identity();
  while (B) {
    if (B bitand 1) ret = ret * A;
    A = A * A;
    B >>= 1;
  }
  return ret;
}

Matrix build (int n) {
  Matrix ret(n);
  for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) if (abs(r - c) <= 1) ret.M[r][c] = 1;
  return ret;
}

int main () {
  ll n, k;
  cin >> n >> k;
  vector <pair <pair <ll, ll>, ll>> segments;
  for (int i = 0; i < n; i++) {
    ll l, r, c;
    cin >> l >> r >> c;
    r = min(r, k);
    segments.push_back({{l, r}, c});
  }
  deque <int> X = {1};
  for (auto s: segments) {
    ll l = s.first.first;
    ll r = s.first.second;
    ll y = s.second;
    while (int(X.size()) < y + 1) X.push_front(0);
    while (int(X.size()) > y + 1) X.pop_front();
    Matrix M = build(X.size());
    M = pow(M, r - l);
    X = M * X;
  }
  cout << X.back() << endl;
  return (0);
}
