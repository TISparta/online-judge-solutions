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
  vll z;
  ll x = 2;
  z.pb(x - 1);
  while (2 * x <= 1e10) {
    x = 2 * x;
    z.pb(x - 1);
  }
  while (tt--) {
    int x;
    cin >> x;
    ll k = 0;
    for (auto zi: z) if (zi < x) k = zi;
    cout << k << '\n';
  }
  return (0);
}
