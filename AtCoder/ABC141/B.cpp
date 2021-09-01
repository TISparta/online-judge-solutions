// Tags: Implementation
// Difficulty: 1.0
// Priority: 5
// Date: 31-08-2021

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
  bool ok = true;
  string s;
  cin >> s;
  for (int i = 0; i < sz(s); i += 2) ok &= (s[i] != 'L');
  for (int i = 1; i < sz(s); i += 2) ok &= (s[i] != 'R');
  if (ok) cout << "Yes\n";
  else cout << "No\n";
  return (0);
}
