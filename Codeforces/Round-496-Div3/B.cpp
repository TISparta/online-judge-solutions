// Implementation
// 2
// 06-11-2020

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
  string s, t;
  cin >> s >> t;
  reverse(all(s));
  reverse(all(t));
  int c = 0;
  int n = sz(s);
  int m = sz(t);
  while (c < min(n, m) and s[c] == t[c]) c += 1;
  cout << n - c + m - c << '\n';
  return (0);
}
