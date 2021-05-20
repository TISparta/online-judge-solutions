// Tags: Game Theory
// Difficulty: 2.5
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
    int ones = count(all(s), '1');
    int zeros = n - ones;
    if (zeros == 0) {
      cout << "ALICE\n";
    } else if (zeros == 1) {
      cout << "BOB\n";
    } else {
      if (n & 1 and s[n / 2] == '0') {
        cout << "ALICE\n";
      } else {
        cout << "BOB\n";
      }
    }
  }
  return (0);
}
