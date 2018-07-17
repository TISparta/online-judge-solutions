/**
 * > Author: TISparta
 * > Date: 16-08-18
 * > Tags: Backtracking, Minimax
 * > Difficulty: 5 / 10
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
  KNIGHT,
  PAWN
};

enum PLAYER {
  NONE,
  BLACK,
  WHITE
};

int b, w, m, bit_grid;
vector <vector <int>> grid(N, vector <int>(N, PIECE::EMPTY));
vector <vector <int>> player(N, vector <int>(N, PLAYER::NONE));
vector <int> dr[10], dc[10];

inline bool isValid (const int& r, const int& c, const int& turn) {
  return 0 <= r and r < N and 0 <= c and c < N and player[r][c] != turn;
}

bool isFree (const int& r, const int& c, const int& nr, const int& nc) {
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

bool findQueen (const int& _player) {
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
  int pib_grid = bit_grid;
  while (pib_grid) {
    int power = pib_grid bitand -pib_grid, hash_ = __builtin_ctz(power);
    int r = hash_ / N, c = hash_ % N;
    if (player[r][c] == turn and grid[r][c] != PIECE::PAWN) {
      for (int d = 0; d < dr[grid[r][c]].size(); d++) {
        int nr = r + dr[grid[r][c]][d];
        int nc = c + dc[grid[r][c]][d];
        if (isValid(nr, nc, turn) and (grid[r][c] == PIECE::KNIGHT or isFree(r, c, nr, nc))) {
          vector <pair <int, pair <int, int>>> grid_pib, player_pib;
          grid_pib = {{grid[r][c], {r, c}}, {grid[nr][nc], {nr, nc}}};
          player_pib = {{player[r][c], {r, c}}, {player[nr][nc], {nr, nc}}};
          int tmp_grid = bit_grid;
          grid[nr][nc] = grid[r][c];
          grid[r][c] = PIECE::EMPTY;
          player[nr][nc] = player[r][c];
          player[r][c] = PLAYER::NONE;
          bit_grid ^= power;
          bit_grid |= (1 << (nr * N + nc));
          if (wTurn)
            win |= backtrack(moves + 1, 1 xor wTurn);
          else
            win &= backtrack(moves + 1, 1 xor wTurn);
          for (auto x: grid_pib) grid[x.second.first][x.second.second] = x.first;
          for (auto x: player_pib) player[x.second.first][x.second.second] = x.first;
          bit_grid = tmp_grid;
          if (wTurn and win) {
            pib_grid = 1;
            break;
          }
          if (not wTurn and not win) {
            pib_grid = 1;
            break;
          }
        }
      }
    }
    if (player[r][c] == turn and grid[r][c] == PIECE::PAWN) {
      for (int d = 0; d < dr[grid[r][c] + player[r][c]].size(); d++) {
        int nr = r + dr[grid[r][c] + player[r][c]][d];
        int nc = c + dc[grid[r][c] + player[r][c]][d];
        if (isValid(nr, nc, turn) and
            ((d == 0 and player[nr][nc] == PLAYER::NONE)
             or (d > 0 and player[nr][nc] != turn and player[nr][nc] != PLAYER::NONE))) {
          vector <pair <int, pair <int, int>>> grid_pib, player_pib;
          grid_pib = {{grid[r][c], {r, c}}, {grid[nr][nc], {nr, nc}}};
          player_pib = {{player[r][c], {r, c}}, {player[nr][nc], {nr, nc}}};
          int tmp_grid = bit_grid;
          grid[nr][nc] = grid[r][c];
          grid[r][c] = PIECE::EMPTY;
          player[nr][nc] = player[r][c];
          player[r][c] = PLAYER::NONE;
          bit_grid ^= power;
          bit_grid |= (1 << (nr * N + nc));
          bool promotion = wTurn ? (nr == N - 1) : (nr == 0);
          if (not promotion) {
            if (wTurn) 
              win |= backtrack(moves + 1, 1 xor wTurn);
            else
              win &= backtrack(moves + 1, 1 xor wTurn);
          }
          else {
            for (int nPiece: {PIECE::BISHOP, PIECE::KNIGHT, PIECE::ROOK}) {
              grid[nr][nc] = nPiece;
              if (wTurn)
                win |= backtrack(moves + 1, 1 xor wTurn);
              else
                win &= backtrack(moves + 1, 1 xor wTurn);
              if (wTurn and win) break;
              if (not wTurn and not win) break;
            }
          }
          for (auto x: grid_pib) grid[x.second.first][x.second.second] = x.first;
          for (auto x: player_pib) player[x.second.first][x.second.second] = x.first;
          bit_grid = tmp_grid;
          if (wTurn and win) {
            pib_grid = 1;
            break;
          }
          if (not wTurn and not win) {
            pib_grid = 1;
            break;
          }
        }
      }
    }
    pib_grid = pib_grid bitand (pib_grid - 1);
  }
  return win;
}

void readCase () {
  scanf("%d %d %d\n", &w, &b, &m);
  m = min(m, 5);
  char t, c;
  int r;
  for (int i = 0; i < w; i++) {
    scanf("%c %c %d\n", &t, &c, &r);
    if (t == 'Q') grid[r - 1][c - 'A'] = PIECE::QUEEN;
    if (t == 'N') grid[r - 1][c - 'A'] = PIECE::KNIGHT;
    if (t == 'B') grid[r - 1][c - 'A'] = PIECE::BISHOP;
    if (t == 'R') grid[r - 1][c - 'A'] = PIECE::ROOK;
    if (t == 'P') grid[r - 1][c - 'A'] = PIECE::PAWN;
    bit_grid |= (1 << ((r - 1) * N + (c - 'A')));
    player[r - 1][c - 'A'] = PLAYER::WHITE;
  }
  for (int i = 0; i < b; i++) {
    scanf("%c %c %d\n", &t, &c, &r);
    if (t == 'Q') grid[r - 1][c - 'A'] = PIECE::QUEEN;
    if (t == 'N') grid[r - 1][c - 'A'] = PIECE::KNIGHT;
    if (t == 'B') grid[r - 1][c - 'A'] = PIECE::BISHOP;
    if (t == 'R') grid[r - 1][c - 'A'] = PIECE::ROOK;
    if (t == 'P') grid[r - 1][c - 'A'] = PIECE::PAWN;
    bit_grid |= (1 << ((r - 1) * N + (c - 'A')));
    player[r - 1][c - 'A'] = PLAYER::BLACK;
  }
}

void initCase () {
  bit_grid = 0;
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

  dr[PIECE::PAWN + PLAYER::BLACK] = {-1, -1, -1};
  dc[PIECE::PAWN + PLAYER::BLACK] = {0, -1, 1};

  dr[PIECE::PAWN + PLAYER::WHITE] = {1, 1, 1};
  dc[PIECE::PAWN + PLAYER::WHITE] = {0, -1, 1};
}

int main () {
  init();
  int tc;
  scanf("%d\n", &tc);
  while (tc--) {
    initCase();
    readCase();
    puts(backtrack() ? "YES" : "NO");
  }
  return (0);
}
