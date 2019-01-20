/**
 * > Author: TISparta
 * > Date: 20-01-19
 * > Tags: Ad-Hoc
 * > Difficulty: 2 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int main () {
  string a, b;
  cin >> a >> b;
  int it = 0;
  for (char ch: a) {
    if (it < b.size() and ch == b[it]) it++;
  }
  if (it == b.size()) {
    cout << "automaton" << endl;
    return (0);
  }
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  if (a == b) {
    cout << "array" << endl;
    return (0);
  }
  it = 0;
  for (char ch: a) {
    if (it < b.size() and ch == b[it]) it++;
  }
  if (it == b.size()) {
    cout << "both" << endl;
    return (0);
  }
  cout << "need tree" << endl;
  return (0);
}
