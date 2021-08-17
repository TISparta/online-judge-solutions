// Tags: Math
// Difficulty: 1.5
// Priority: 5
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
  int n, x, y;
  cin >> n >> x >> y;
  n /= 2;
  string ans = "YES";
  if ((x == n or x == n + 1) and (y == n or y == n + 1)) ans = "NO";
  cout << ans << '\n';
  return (0);
}
