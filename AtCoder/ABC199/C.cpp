// Implementation
// 2.0
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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  string s;
  cin >> n >> s >> q;
  int order = 0;
  string x = s.substr(0, n);
  string y = s.substr(n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, b;
      cin >> a >> b;
      a -= 1;
      b -= 1;
      if (order == 0) {
        if (a < n and b < n) swap(x[a], x[b]);
        if (a >= n and b >= n) swap(y[a - n], y[b - n]);
        if (a < n and b >= n) swap(x[a], y[b - n]);
        if (a >= n and b < n) swap(y[a - n], x[b]);
      } else {
        if (a < n and b < n) swap(y[a], y[b]);
        if (a >= n and b >= n) swap(x[a - n], x[b - n]);
        if (a < n and b >= n) swap(y[a], x[b - n]);
        if (a >= n and b < n) swap(x[a - n], y[b]);
      }
    } else {
      int a, b;
      cin >> a >> b;
      order = 1 - order;
    }
  }
  if (order) {
    cout << y << x << '\n';
  } else {
    cout << x << y << '\n';
  }
  return (0);
}
