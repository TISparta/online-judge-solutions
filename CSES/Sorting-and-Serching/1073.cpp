// Greedy
// 2
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
  multiset <int> tower;
  for (int i = 0; i < n; i++) {
    int ki;
    cin >> ki;
    if (tower.empty() or *(--end(tower)) <= ki) {
      tower.insert(ki);
    } else {
      tower.erase(tower.upper_bound(ki));
      tower.insert(ki);
    }
  }
  cout << sz(tower) << '\n';
  return (0);
}
