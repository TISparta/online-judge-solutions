// Brute Force
// 2
// 19-11-20

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
  int n, L;
  cin >> n >> L;
  vi a(n);
  for (int& ai: a) cin >> ai;
  vi b(n);
  for (int& bi: b) cin >> bi;
  vi d1;
  vi d2;
  for (int i = 1; i < n; i++) {
    d1.pb(a[i] - a[i - 1]);
    d2.pb(b[i] - b[i - 1]);
  }
  d1.pb(L - accumulate(all(d1), 0));
  d2.pb(L - accumulate(all(d2), 0));
  bool ok = false;
  for (int i = 0; i < n; i++) {
    if (d1 == d2) ok = true;
    int x = d1.front();
    d1.erase(begin(d1));
    d1.pb(x);
  }
  if (ok) cout << "YES\n";
  else cout << "NO\n";
  return (0);
}
