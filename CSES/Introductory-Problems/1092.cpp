// Constructive Algorithms
// 2
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
  ll n;
  cin >> n;
  if (n % 4 == 0) {
    vi a, b;
    for (int i = 1; i <= n; i += 4) {
      a.pb(i), a.pb(i + 3);
      b.pb(i + 1), b.pb(i + 2);
    }
    cout << "YES\n";
    cout << sz(a) << '\n';
    for (int i = 0; i < sz(a); i++) cout << a[i] << " \n"[i == sz(a) - 1];
    cout << sz(b) << '\n';
    for (int i = 0; i < sz(b); i++) cout << b[i] << " \n"[i == sz(b) - 1];
  } else if (n % 4 == 1 or n % 4 == 2) {
    cout << "NO\n";
  } else {
    vi a, b;
    a.pb(1), a.pb(2);
    b.pb(3);
    for (int i = 4; i <= n; i += 4) {
      a.pb(i), a.pb(i + 3);
      b.pb(i + 1), b.pb(i + 2);
    }
    cout << "YES\n";
    cout << sz(a) << '\n';
    for (int i = 0; i < sz(a); i++) cout << a[i] << " \n"[i == sz(a) - 1];
    cout << sz(b) << '\n';
    for (int i = 0; i < sz(b); i++) cout << b[i] << " \n"[i == sz(b) - 1];
  }
  return (0);
}
