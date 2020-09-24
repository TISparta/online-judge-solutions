// Brute Force
// 2
// 11-09-2020

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
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  auto go = [&] (int k, int a, int b, int x) {
    int boxes = 0;
    while (a > 0) {
      boxes += 1;
      int put = min(k - 1, b);
      a -= x * (put + 1);
      b -= put;
    }
    return boxes;
  };
  int ans = INT_MAX;
  for (int x = 1; x <= v; x++) {
    ans = min(ans, go(k, a, b, x));
  }
  cout << ans << '\n';
  return (0);
}
