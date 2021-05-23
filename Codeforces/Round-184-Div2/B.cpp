// Tags: Implementation
// Difficulty: 2.6
// Priority: 1
// Date: 22-05-2021

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
  ll p, q;
  cin >> p >> q;
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ll g = gcd(p, q);
  p /= g;
  q /= g;
  auto die = [&] () {
    cout << "NO\n";
    exit(0);
  };
  auto solve = [&] (ll r) {
    if (q >= LLONG_MAX / r) die();
    p = p - q * r;
    ll g = gcd(p, q);
    p /= g;
    q /= g;
    swap(p, q);
    if (q == 0) die();
    if (q < 0) q *= -1, p *= -1;
  };
  for (int i = 0; i + 1 < n; i++) solve(a[i]);
  ll r = a[n - 1];
  if (p < 0 or q > p / r) die();
  if (q * r == p) cout << "YES\n";
  else cout << "NO\n";
  return (0);
}
