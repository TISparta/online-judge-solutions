// Tags: Number Theory
// Difficulty: 4.0
// Priority: 2
// Date: 10-05-2021

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
  int q;
  cin >> q;
  while (q--) {
    ll p, q, b;
    cin >> p >> q >> b;
    ll g = __gcd(p, q);
    p /= g;
    q /= g;
    while (b != 1) {
      while (q % b == 0) q /= b;
      b = __gcd(q, b);
    }
    if (q == 1) cout << "Finite\n";
    else cout << "Infinite\n";
  }
  return (0);
}
