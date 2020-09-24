// Math
// 1
// 04-09-2020

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
  int tc;
  cin >> tc;
  while (tc--) {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << '\n';
    } else if (abs(a - b) <= 10) {
      cout << 1 << '\n';
    } else {
      cout << (abs(b - a) + 9) / 10 << '\n';
    }
  }
  return (0);
}
