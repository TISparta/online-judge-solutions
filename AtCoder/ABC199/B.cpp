// Brute Force
// 1.1
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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vi b(n);
  for (int i = 0; i < n; i++) cin >> b[i];
  int l = a[0];
  int r = b[0];
  int cnt = 0;
  for (int x = l; x <= r; x++) {
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok &= (a[i] <= x and x <= b[i]);
    }
    cnt += ok;
  }
  cout << cnt << '\n';
  return (0);
}
