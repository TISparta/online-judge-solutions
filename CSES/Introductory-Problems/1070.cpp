// Constructive Algorithms
// 3
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
  int n;
  cin >> n;
  vi p;
  for (int i = 2; i <= n; i += 2) p.pb(i);
  for (int i = 1; i <= n; i += 2) p.pb(i);
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (abs(p[i] - p[i - 1]) == 1) ok = false;
  }
  if (not ok) cout << "NO SOLUTION\n";
  else for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
  return (0);
}
