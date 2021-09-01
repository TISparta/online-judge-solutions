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
  string s;
  cin >> s;
  string ans;
  if (s[0] == 'S') ans = "Cloudy\n";
  if (s[0] == 'C') ans = "Rainy\n";
  if (s[0] == 'R') ans = "Sunny\n";
  cout << ans << '\n';
  return (0);
}
