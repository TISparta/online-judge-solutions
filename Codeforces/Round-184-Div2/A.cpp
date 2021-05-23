// Tags: Case Analysis
// Difficulty: 1.7
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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vi z;
  if (find(all(a), 0) != end(a)) z.pb(0);
  if (find(all(a), 100) != end(a)) z.pb(100);
  int f = 0;
  for (int i = 0; i < n; i++) {
    if (1 <= a[i] and a[i] <= 9) {
      z.pb(a[i]);
      f += 1;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (10 <= a[i] and a[i] <= 90 and a[i] % 10 == 0) {
      z.pb(a[i]);
      f += 1;
      break;
    }
  }
  if (f == 0) {
    for (int i = 0; i < n; i++) if (0 < a[i] and a[i] < 100) {
      z.pb(a[i]);
      break;
    }
  }
  cout << sz(z) << '\n';
  for (int i = 0; i < sz(z); i++) cout << z[i] << " \n"[i + 1 == sz(z)];
  return (0);
}
