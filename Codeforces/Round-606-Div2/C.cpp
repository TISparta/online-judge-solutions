// Tags: Greedy
// Difficulty: 3.0
// Priority: 1
// Date: 14-04-2021

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
    set <int> st;
    for (int i = 0; i < sz(s); i++) {
      string z = s.substr(i, 5);
      if (z == "twone") {
        st.emplace(i + 2);
        s[i + 2] = '#';
      }
    }
    for (int i = 0; i < sz(s); i++) {
      string z = s.substr(i, 3);
      if (z == "one") {
        st.emplace(i + 1);
      }
      if (z == "two") {
        st.emplace(i + 1);
      }
    }
    cout << sz(st) << '\n';
    bool first = true;
    for (int x: st) {
      if (not first) cout << ' ';
      cout << x + 1;
      first = false;
    }
    cout << '\n';
  }
  return (0);
}
