/**
 * > Author: TISparta
 * > Date: 16-08-18
 * > Tags: Backtracking, Minimax
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

const int N = 4;

enum PIECE {
  EMPTY,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT
};

enum PLAYER {
  NONE,
  BLACK,
  WHITE
};

int b, w, m;
vector <vector <int>> grid(N, vector <int>(N, PIECE::EMPTY));
vector <vector <int>> player(N, vector <int>(N, PLAYER::NONE));
map <int, vector <int>> dr, dc;

bool isValid (int r, int c, int turn) {
  return 0 <= r and r < N and 0 <= c and c < N and player[r][c] != turn;
}

bool isFree (int r, int c, int nr, int nc) {
  int r1 = min(r, nr), r2 = max(r, nr);
  int c1 = min(c, nc), c2 = max(c, nc);
  int cnt1 = (grid[r][c] != PIECE::EMPTY) + (grid[nr][nc] != PIECE::EMPTY);
  int cnt2 = 0;
  if (r == nr) {
    for (int y = c1; y <= c2; y++)
      if (grid[r][y] != PIECE::EMPTY) cnt2++;
  }
  else if (c == nc) {
    for (int x = r1; x <= r2; x++)
      if (grid[x][c] != PIECE::EMPTY) cnt2++;
  }
  else if (mp(r1, c1) == mp(r, c) or mp(r1, c1) == mp(nr, nc)) {
    for (int i = 0; i <= r2 - r1; i++)
      if (grid[r1 + i][c1 + i] != PIECE::EMPTY) cnt2++;
  }
  else {
    for (int i = 0; i <= r2 - r1; i++)
      if (grid[r1 + i][c2 - i] != PIECE::EMPTY) cnt2++;
  }
  return cnt1 == cnt2;
}

bool findQueen (int _player) {
  for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++)
      if (grid[r][c] == PIECE::QUEEN and player[r][c] == _player) return true;
  return false;
}

bool backtrack (int moves = 0, bool wTurn = true) {
  if (not findQueen(PLAYER::WHITE)) return false;
  if (not findQueen(PLAYER::BLACK)) return true;
  if (moves >= m) return false;
  bool win = wTurn ? false : true;
  int turn = wTurn ? PLAYER::WHITE : PLAYER::BLACK;
  for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++)
      if (player[r][c] == turn) {
        for (int d = 0; d < dr[grid[r][c]].size(); d++) {
          int nr = r + dr[grid[r][c]][d];
          int nc = c + dc[grid[r][c]][d];
          if (isValid(nr, nc, turn) and (grid[r][c] == PIECE::KNIGHT or isFree(r, c, nr, nc))) {
            vector <vector <int>> grid_pib = grid, player_pib = player;
            grid[nr][nc] = grid[r][c];
            grid[r][c] = PIECE::EMPTY;
            player[nr][nc] = player[r][c];
            player[r][c] = PLAYER::NONE;
            if (wTurn)
              win |= backtrack(moves + 1, 1 xor wTurn);
            else
              win &= backtrack(moves + 1, 1 xor wTurn);
            grid = grid_pib;
            player = player_pib;
            if (wTurn and win) {
              r = c = N;
              break;
            }
            if (not wTurn and not win) {
              r = c = N;
              break;
            }
          }
        }
      }
  return win;
}

void readCase () {
  cin >> w >> b >> m;
  char t, c;
  int r;
  for (int i = 0; i < w; i++) {
    cin >> t >> c >> r;
    if (t == 'Q') grid[r - 1][c - 'A'] = PIECE::QUEEN;
    if (t == 'N') grid[r - 1][c - 'A'] = PIECE::KNIGHT;
    if (t == 'B') grid[r - 1][c - 'A'] = PIECE::BISHOP;
    if (t == 'R') grid[r - 1][c - 'A'] = PIECE::ROOK;
    player[r - 1][c - 'A'] = PLAYER::WHITE;
  }
  for (int i = 0; i < b; i++) {
    cin >> t >> c >> r;
    if (t == 'Q') grid[r - 1][c - 'A'] = PIECE::QUEEN;
    if (t == 'N') grid[r - 1][c - 'A'] = PIECE::KNIGHT;
    if (t == 'B') grid[r - 1][c - 'A'] = PIECE::BISHOP;
    if (t == 'R') grid[r - 1][c - 'A'] = PIECE::ROOK;
    player[r - 1][c - 'A'] = PLAYER::BLACK;
  }
}

void initCase () {
  fill(begin(grid), end(grid), vector <int> (N, PIECE::EMPTY));
  fill(begin(player), end(player), vector <int> (N, PLAYER::NONE));
}

void init () {
  dr[PIECE::QUEEN] = {0, 0, 0, 0, 0, 0, -1, -2, -3, 1, 2, 3, -1, -2, -3, 1, 2, 3, 1, 2, 3, -1, -2, -3};
  dc[PIECE::QUEEN] = {1, 2, 3, -1, -2, -3, 0, 0, 0, 0, 0, 0, 1, 2, 3, 1, 2, 3, -1, -2, -3, -1, -2, -3};

  dr[PIECE::ROOK] = {0, 0, 0, 0, 0, 0, -1, -2, -3, 1, 2, 3};
  dc[PIECE::ROOK] = {1, 2, 3, -1, -2, -3, 0, 0, 0, 0, 0, 0};

  dr[PIECE::BISHOP] = {-1, -2, -3, 1, 2, 3, 1, 2, 3, -1, -2, -3};
  dc[PIECE::BISHOP] = {1, 2, 3, 1, 2, 3, -1, -2, -3, -1, -2, -3};
  
  dr[PIECE::KNIGHT] = {-1, -2, -2, -1, 1, 2, 2, 1};
  dc[PIECE::KNIGHT] = {2, 1, -1, -2, -2, -1, 1, 2};
}

int main () {
  init();
  int tc;
  cin >> tc;
  while (tc--) {
    initCase();
    readCase();
    puts(backtrack() ? "YES" : "NO");
  }
  return (0);
}
