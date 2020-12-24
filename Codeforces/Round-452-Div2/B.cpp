// Implementation
// 2
// 23-12-2020

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
  vi x = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vi y = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  auto check = [&] (vi a1, vi a2, vi a3, vi a4) {
    vi x = a1;
    x.insert(end(x), all(a2));
    x.insert(end(x), all(a3));
    x.insert(end(x), all(a4));
    for (int i = 0; i + sz(a) - 1 < sz(x); i++) {
      bool ok = true;
      for (int j = 0; j < sz(a); j++) {
        ok &= (x[i + j] == a[j]);
      }
      if (ok) return true;
    }
    return false;
  };
  if (check(x, x, x, x) or 
      check(y, x, x, x) or
      check(x, y, x, x) or
      check(x, x, y, x) or
      check(x, x, x, y)) cout << "Yes\n";
  else cout << "No\n";
  return (0);
}
