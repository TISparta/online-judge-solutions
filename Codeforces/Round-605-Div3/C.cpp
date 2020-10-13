// Math
// 2
// 29-08-2020

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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int mask = 0;
  for (int i = 0; i < k; i++) {
    char ci;
    cin >> ci;
    mask |= (1 << (ci - 'a'));
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if ((mask >> (s[i] - 'a')) & 1) {
      int j = i;
      while (j + 1 < n and ((mask >> (s[j + 1] - 'a')) & 1)) {
        j += 1;
      }
      ll len = j - i + 1;
      ans += len * (len + 1) / 2;
      i = j;
    }
  }
  cout << ans << '\n';
  return (0);
}
