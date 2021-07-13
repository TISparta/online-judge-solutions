// Tags: Brute Force
// Difficulty: 6.0
// Priority: 5
// Date: 18-06-2021

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
  vector <string> zz(n);
  for (int len = 1; len <= n; len++) {
    zz[len - 1] = s.substr(0, len);
    while (sz(zz[len - 1]) < k) zz[len - 1] += zz[len - 1];
  }
  sort(all(zz));
  string z = zz[0];
  while (sz(z) < k) z += z;
  cout << z.substr(0, k) << '\n';
  return (0);
}
