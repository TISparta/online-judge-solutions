// Brute Force
// 4
// 18-08-2020

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
  set <ll> val;
  for (int i = 1; i <= n; i++) {
    int xi;
    cin >> xi;
    val.insert(xi);
  }
  int ans = 0;
  pii ans_x;
  for (ll x1: val) {
    if (ans < 1) {
      ans = 1;
      ans_x = pii(x1, 0);
    }
    for (int bit = 0; bit <= 32; bit++) {
      ll add = 1LL << bit;
      int cnt = 1;
      for (int j = 1; j <= 2; j++) {
        if (val.count(x1 + add * j) == 0) break;
        cnt++;
        if (ans < cnt) {
          ans = cnt;
          ans_x = pii(x1, add);
        }
      }
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < ans; i++) {
    cout << ans_x.first << " \n"[i == ans - 1];
    ans_x.first += ans_x.second;
  }
  return (0);
}
