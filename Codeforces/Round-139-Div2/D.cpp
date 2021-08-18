// Tags: Implementation, Dijkstra
// Difficulty: 6.0
// Priority: 1
// Date: 18-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  int n, m;
  cin >> n >> m;
  vector <string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vpii pos;
  for (char ch = '1'; ch <= '9'; ch++) {
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (s[r][c] == ch) pos.eb(r, c);
      }
    }
  }
  vi dr = {0, 0, 1, -1};
  vi dc = {1, -1, 0, 0};
  vi snake_dir;
  for (int i = 1; i < sz(pos); i++) {
    auto [pr, pc] = pos[i - 1];
    auto [r, c] = pos[i];
    for (int d = 0; d < 4; d++) {
      if (pr + dr[d] == r and pc + dc[d] == c) snake_dir.pb(d);
    }
  }
  auto get_hash = [&] (const vi& snake_dir) {
    int hash = 0;
    int p = 1;
    for (int d: snake_dir) {
      hash = hash + (d + 1) * p;
      p *= 5;
    }
    return hash;
  };
  auto get_vector = [&] (int hash) {
    vi snake_dir;
    while (hash) {
      snake_dir.pb((hash % 5) - 1);
      hash /= 5;
    }
    return snake_dir;
  };
  using State = tuple <int, int, int>;
  map <State, int> dis;
  auto state = mt(get_hash(snake_dir), pos[0].first, pos[0].second);
  dis[state] = 0;
  set <pair <int, State>> st;
  st.emplace(0, state);
  while (not empty(st)) {
    auto [dis_state, state] = *begin(st);
    auto [snake_dir_hash, r, c] = state;
    vi snake_dir = get_vector(snake_dir_hash);
    st.erase(begin(st));
    vpii snake;
    snake.eb(r, c);
    for (int d: snake_dir) {
      snake.eb(snake.back().first + dr[d], snake.back().second + dc[d]);
    }
    if (s[r][c] == '@') {
      cout << dis_state << '\n';
      return (0);
    }
    for (int d = 0; d < 4; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (not (0 <= min(nr, nc) and nr < n and nc < m)) continue;
      if (s[nr][nc] == '#') continue;
      bool valid = true;
      for (int i = 0; i + 1 < sz(snake); i++) {
        valid &= (snake[i] != mp(nr, nc));
      }
      if (not valid) continue;
      vi new_snake_dir;
      new_snake_dir.pb(2 * (d / 2) + (1 - (d % 2)));
      new_snake_dir.insert(end(new_snake_dir), all(snake_dir));
      new_snake_dir.pop_back();
      auto new_state = mt(get_hash(new_snake_dir), nr, nc);
      if (dis.count(new_state) == 0 or (dis[new_state] > dis_state + 1)) {
        st.erase(mp(dis[new_state], new_state));
        dis[new_state] = dis_state + 1;
        st.emplace(mp(dis[new_state], new_state));
      }
    }
  }
  cout << -1 << '\n';
  return (0);
}
