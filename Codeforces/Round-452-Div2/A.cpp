// Math
// 1
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
  int x = 0;
  int y = 0;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    if (ai == 1) x += 1;
    if (ai == 2) y += 1;
  }
  int ans = min(y, x);
  x -= ans;
  y -= ans;
  ans += x / 3;
  cout << ans << '\n';
  return (0);
}
