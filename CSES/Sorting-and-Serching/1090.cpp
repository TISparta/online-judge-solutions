// Greedy
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
  int n, x;
  cin >> n >> x;
  multiset <int> st;
  for (int i = 0; i < n; i++) {
    int pi;
    cin >> pi;
    st.insert(pi);
  }
  int ans = 0;
  while (not st.empty()) {
    ans += 1;
    int a = *begin(st);
    st.erase(begin(st));
    if (st.empty() or a + *begin(st) > x) continue;
    auto it = --st.upper_bound(x - a);
    st.erase(it);
  }
  cout << ans << '\n';
  return (0);
}
