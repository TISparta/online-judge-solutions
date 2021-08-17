// Tags: Brute Force
// Difficulty: 1.5
// Priority: 1
// Date: 16-08-2021

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
  set <int> st;
  int ans = 0;
  int limit = n * n;
  for (int a = 1; a <= n; a++) {
    int a2 = a * a;
    for (int b = a; b <= n; b++) {
      int val = a2 + b * b;
      if (val > limit) break;
      int c = sqrt(val);
      if ((c + 1) * (c + 1) <= val) c += 1;
      if (c * c == val) ans += 1;
    }
  }
  cout << ans << '\n';
  return (0);
}
