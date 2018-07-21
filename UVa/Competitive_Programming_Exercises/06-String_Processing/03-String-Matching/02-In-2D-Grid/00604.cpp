#include <bits/stdc++.h>

using namespace std;

const int N = 4, N_VOWELS = 2;
const char FILLED = '#';
const string VOWELS = "AEIOUY";

string s;
vector <string> grid1, grid2;
set <string> word1, word2;
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

void findCommonWords () {
  bool ok = false;
  for (const string w: word1) {
    if (word2.find(w) != end(word2)) {
      ok = true;
      cout << w << endl;
    }
  }
  if (not ok) puts("There are no common words for this pair of boggle boards.");
}

bool isWord () {
  int nVowels = 0;
  for (char ch: s) if (VOWELS.find(ch) != string::npos) nVowels++;
  return nVowels == N_VOWELS;
}

inline bool isValid (const int r, const int c) {
  return 0 <= r and 0 <= c and r < N and c < N;
}

void backtrack (int r, int c, int len, vector <string>& grid, set <string>& word) {
  if (len == N) {
    if (isWord()) word.insert(s);
    return;
  }
  for (int d = 0; d < 8; d++) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (isValid(nr, nc) and grid[nr][nc] != FILLED) {
      char ch = grid[nr][nc];
      grid[nr][nc] = FILLED;
      s += ch;
      backtrack(nr, nc, len + 1, grid, word);
      grid[nr][nc] = ch;
      s.pop_back();
    }
  }
}

void findWords (vector <string>& grid, set <string>& word ) {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      char ch = grid[r][c];
      grid[r][c] = FILLED;
      s += ch;
      backtrack(r, c, 1, grid, word);
      grid[r][c] = ch;
      s.pop_back();
    }
  }
}

bool readGrid () {
  string line;
  getline(cin, line);
  if (line[0] == '#') return false;
  for (int r = 0; r < 4; r++) {
    grid1.push_back("");
    grid2.push_back("");
    istringstream token(line);
    char ch;
    for (int c = 0; c < 4; c++) {
      token >> ch;
      grid1[r] += ch;
    }
    for (int c = 0; c < 4; c++) {
      token >> ch;
      grid2[r] += ch;
    }
    getline(cin, line);
  }
  return true;
}

void clearCase () {
  grid1.clear(), grid2.clear();
  word1.clear(), word2.clear();
}

int main () {
  bool first = true;
  while (true) {
    clearCase();
    if (not readGrid()) break;
    if (not first) puts("");
    findWords(grid1, word1);
    findWords(grid2, word2);
    findCommonWords();
    first = false;
  }
  return (0);
}
