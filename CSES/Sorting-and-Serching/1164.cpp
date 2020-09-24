// Sweep Line
// 3
// 09-09-2020

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
  struct Event { int time, id, type; };
  vector <Event> event;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    event.pb({a, i, 0});
    event.pb({b, i, 1});
  }
  sort(all(event), [&] (Event x, Event y) { 
    if (x.time != y.time) return x.time < y.time;
    return x.type < y.type;
  });
  vi ans(n);
  set <int> available;
  int k = 0;
  for (auto e: event) {
    if (e.type == 0) { // open
      if (available.empty()) {
        available.insert(++k);
      }
      ans[e.id] = *begin(available);
      available.erase(begin(available));
    } else {
      available.insert(ans[e.id]);
    }
  }
  cout << k << '\n';
  for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
  return (0);
}
