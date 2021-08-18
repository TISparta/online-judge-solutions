// Tags: Implementation
// Difficulty: 1.5
// Priority: 5
// Date: 16-01-2021

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
  if (sz(s) == 1) {
    cout << 0 << '\n';
    return (0);
  }
  int sum = 0;
  for (char ch: s) sum += ch - '0';
  int times = 1;
  while (sum >= 10) {
    ll z = 0;
    while (sum) z += sum % 10, sum /= 10;
    sum = z;
    times += 1;
  }
  cout << times << '\n';
  return (0);
}
