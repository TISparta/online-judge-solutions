// Sweep Line
// 2
// 06-09-2020

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
  vector <tuple <int, int, int>> event;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    event.emplace_back(a, -1, i);
    event.emplace_back(b, 1, i);
  }
  sort(all(event));
  set <int> st;
  int ans = 0;
  for (auto tt: event) {
    int type, index;
    tie(ignore, type, index) = tt;
    if (type == -1) {
      st.emplace(index);
    } else {
      st.erase(index);
    }
    ans = max(ans, sz(st));
  }
  cout << ans << '\n';
  return (0);
}
