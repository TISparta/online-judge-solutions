// Implementation
// 2
// 03-09-2020

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
  string s;
  cin >> s;
  int ans = 0;
  for (int l = 0; l < sz(s); l++) {
    int r = l;
    while (r + 1 < sz(s) and s[r + 1] == s[l]) r += 1;
    ans = max(ans, r - l + 1);
    l = r;
  }
  cout << ans << '\n';
  return (0);
}
