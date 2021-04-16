// Math
// 2
// 05-04-2021

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
  ll b;
  cin >> b;
  ll div = 1;
  for (ll d = 2; d * d <= b; d++) {
    if (b % d) continue;
    ll e = 0;
    while (b % d == 0) e += 1, b /= d;
    div *= (e + 1);
  }
  if (b != 1) div *= 2;
  cout << div << '\n';
  return (0);
}
