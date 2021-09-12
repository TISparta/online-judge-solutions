// Tags: Cumulative Array
// Difficulty: 1.0
// Priority: 5
// Date: 07-09-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  vi w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  int total = accumulate(all(w), 0);
  int ans = INT_MAX;
  int s1 = 0;
  for (int i = 0; i + 1 < n; i++) {
    s1 += w[i];
    int s2 = total - s1;
    ans = min(ans, abs(s1 - s2));
  }
  cout << ans << '\n';
  return (0);
}
