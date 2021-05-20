// Tags: Game Theory
// Difficulty: 3.0
// Priority: 1
// Date: 20-05-2021

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    string rs = s;
    reverse(all(rs));
    int zeros = count(all(s), '0');
    if (s == rs) {
      if (zeros & 1 and zeros >= 3) cout << "ALICE\n";
      else cout << "BOB\n";
    } else {
      int x = 0;
      for (int i = 0; i < n - 1 - i; i++) x += (s[i] != s[n - 1 - i]);
      if (x == 1 and zeros == 2) cout << "DRAW\n";
      else cout << "ALICE\n";
    }
  }
  return (0);
}
