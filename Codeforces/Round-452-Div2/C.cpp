// Constructive
// 3
// 24-12-2020

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
  vi x;
  while (n >= 4) {
    x.pb(n);
    x.pb(n - 3);
    n -= 4;
  }
  int dif = 0;
  if (n == 1) dif = 1;
  if (n == 2) dif = 1, x.pb(1);
  if (n == 3) dif = 0, x.pb(3);
  cout << dif << '\n';
  cout << sz(x);
  for (int xi: x) cout << ' ' << xi;
  cout << '\n';
  return (0);
}
