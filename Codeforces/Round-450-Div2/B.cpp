// Implementation
// 2
// 27-11-2020

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
  int a, b, c;
  cin >> a >> b >> c;
  set <int> used;
  a *= 10;
  int it = 0;
  vi pos(10, INT_MAX);
  while (true) {
    int x = a / b;
    if (used.count(a)) break;
    used.emplace(a);
    pos[x] = min(pos[x], ++it);
    a = 10 * (a % b);
  }
  if (pos[c] == INT_MAX) pos[c] = -1;
  cout << pos[c] << '\n';
  return (0);
}
