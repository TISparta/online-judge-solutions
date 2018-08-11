/**
 * > Author : TISparta
 * > Date : 11-08-18
 * > Tags : Implementation
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

int T, Y;
vector <string> pile, hand;

void clear () {
  pile.clear();
  hand.clear();
  Y = 0;
}

void read () {
  string line;
  getline(cin, line);
  istringstream ss(line);
  string s;
  while (ss >> s) pile.size() == 27 ? hand.push_back(s) : pile.push_back(s);
}

void exec () {
  int X = isdigit(pile.back()[1]) ? stoi(pile.back()) : 10;
  Y += X;
  pile.pop_back();
  X = 10 - X;
  while (X--) pile.pop_back();
}

void solveCase (int t) {
  clear();
  read();
  for (int it = 0; it < 3; it++) exec();
  pile.insert(end(pile), begin(hand), end(hand));
  cout << "Case " << t << ": " << pile[Y - 1] << endl;
}

int main () {
  cin >> T;
  cin.ignore();
  for (int t = 1; t <= T; t++) solveCase(t);
  return (0);
}
