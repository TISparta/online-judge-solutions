// Tags: Math, Linear Algebra
// Difficulty: 6.7
// Priority: 1
// Date: 16-01-2021

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
  ll x, y;
  cin >> x >> y;
  complex <ll> A{x, y};
  cin >> x >> y;
  complex <ll> B{x, y};
  cin >> x >> y;
  complex <ll> C{x, y};
  complex <ll> i{0, 1};
  auto solve = [&] (ll a, ll b, ll c, ll d, ll e, ll f) {
    if (c == 0 and f == 0) return 1;
    // [a b] [x] = [c]
    // [d e] [y] = [f]
    ll det = a * e - b * d;
    if (det == 0) return 0;
    // [e -b] [c]
    // [-d a] [f]
    ll x = e * c - b * f;
    ll y = -d * c + a * f;
    if (x % det or y % det) return 0;
    return 1;
  };
  bool ok = false;
  for (int k = 0; k < 4; k++) {
    complex <ll> Z;
    if (k == 0) Z = B - A;
    if (k == 1) Z = B - A * i;
    if (k == 2) Z = B + A;
    if (k == 3) Z = B + A * i;
    ok |= solve(C.real(), (C * i).real(), Z.real(), C.imag(), (C * i).imag(), Z.imag());
  }
  ok |= (A == B);
  if (ok) cout << "YES\n";
  else cout << "NO\n";
  return (0);
}
