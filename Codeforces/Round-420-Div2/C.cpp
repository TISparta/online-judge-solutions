/**
 * > Author: TISparta
 * > Date: 29-12-18
 * > Tags: Greedy
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, pib = 1, ans = 0;
  vector <int> arr;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    string command;
    cin >> command;
    if (command[0] == 'r') {
      if (arr.empty()) {
        pib++;
        continue;
      }
      if (arr.back() == pib) {
        arr.pop_back();
        pib++;
        continue;
      }
      arr.clear();
      ans++;
      pib++;
    }
    else {
      int add;
      cin >> add;
      arr.push_back(add);
    }
  }
  cout << ans << endl;
  return (0);
}
