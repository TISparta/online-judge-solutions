// Tags: Greedy
// Difficulty: 1.5
// Priority: 5
// Date: 23-07-2021

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
    string s;
    cin >> s;
    vi cnt(30, 0);
    for (char ch: s) cnt[ch - 'a'] += 1;
    int extra = 0;
    int k = 0;
    for (char i = 0; i < 30; i++) {
      if (cnt[i] == 0) continue;
      if (cnt[i] == 1) extra += 1;
      if (cnt[i] >= 2) k += 1;
    }
    k += (extra / 2);
    cout << k << '\n';
  }
  return (0);
}
