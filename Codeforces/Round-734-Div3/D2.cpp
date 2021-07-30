// Tags: Constructive Algorithms, Implementation
// Difficulty: 4.0
// Priority: 3
// Date: 24-07-2021

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
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 1) {
      if (k == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; i += 2) {
          char ch = "ab"[(i / 2) & 1];
          cout << ch << '\n';
          cout << ch << '\n';
        }
      } else {
        cout << "NO\n";
      }
      continue;
    }
    if (n % 2 == 0) {
      int mx = n * (m / 2);
      if (k % 2 == 0 and k <= mx) {
        // putting horizontals from the left
        cout << "YES\n";
        vector <string> ans(n, string(m, '*'));
        for (int col = 0; col < m and k; col += 2) {
          char ch1 = 'a';
          char ch2 = 'b';
          if ((col / 2) & 1) swap(ch1, ch2);
          for (int row = 0; row < n and k; row += 2) {
            ans[row][col] = ans[row][col + 1] = ch1;
            ans[row + 1][col] = ans[row + 1][col + 1] = ch2;
            k -= 2;
          }
        }
        for (int row = 0; row < n; row += 2) {
          string ch = "cd";
          if ((row / 2) & 1) ch = "dc";
          for (int col = 0; col < m; col++) {
            if (ans[row][col] == '*') {
              ans[row][col] = ans[row + 1][col] = ch[col & 1];
            }
          }
        }
        for (int i = 0; i < n; i++) cout << ans[i] << '\n';
      } else {
        cout << "NO\n";
      }
    } else {
      int m2 = m / 2;
      int mx = n * (m / 2);
      if (k < m2 or ((k - m2) & 1) or k > mx) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        vector <string> ans(n, string(m, '*'));
        for (int col = 0; col < m; col += 2) {
          char ch = "xy"[(col / 2) & 1];
          ans[0][col] = ans[0][col + 1] = ch;
          k -= 1;
        }
        for (int col = 0; col < m and k; col += 2) {
          char ch1 = 'a';
          char ch2 = 'b';
          if ((col / 2) & 1) swap(ch1, ch2);
          for (int row = 1; row < n and k; row += 2) {
            ans[row][col] = ans[row][col + 1] = ch1;
            ans[row + 1][col] = ans[row + 1][col + 1] = ch2;
            k -= 2;
          }
        }
        for (int row = 1; row < n; row += 2) {
          string ch = "cd";
          if ((row / 2) & 1) ch = "dc";
          for (int col = 0; col < m; col++) {
            if (ans[row][col] == '*') {
              ans[row][col] = ans[row + 1][col] = ch[col & 1];
            }
          }
        }
        for (int i = 0; i < n; i++) cout << ans[i] << '\n';
      }
    }
  }
  return (0);
}
