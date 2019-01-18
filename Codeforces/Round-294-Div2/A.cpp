/**
 * > Author: TISparta
 * > Date: 17-01-19
 * > Tags: Implementation
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

map <char, int> W;

int main () {
  W['q'] = 9, W['r'] = 5, W['b'] = 3, W['n'] = 3, W['p'] = 1;
  int white = 0, black = 0;
  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for (char ch: s) {
      int w = W[tolower(ch)];
      if (w and isupper(ch)) white += w;
      if (w and islower(ch)) black += w;
    }
  }
  if (white > black) cout << "White" << endl;
  else if (white < black) cout << "Black" << endl;
  else cout << "Draw" << endl;
  return (0);
}
