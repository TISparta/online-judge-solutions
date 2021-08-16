// Tags: Flows
// Difficulty: 7.0
// Priority: 3
// Date: 16-08-2021

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

// Source: https://github.com/t3nsor/codebook/blob/master/dinic.cpp
// Dinic's blocking flow algorithm
// Running time:
// * general networks: O(|V|^2 |E|)
// * unit capacity networks: O(E min(V^(2/3), E^(1/2)))
// * bipartite matching networks: O(E sqrt(V))

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  // N = number of vertices
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  // Add an edge to initially empty network. from, to are 0-based
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        if (!e) { amt = 0; break; }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  // Call this to get the max flow. s, t are 0-based.
  // Note, you can only call this once.
  // To obtain the actual flow values, look at all edges with
  // capacity > 0 (zero capacity edges are residual edges).

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, b, q;
  cin >> n >> b >> q;
  vector <pii> hint(q);
  for (int i = 0; i < n; i++) {
    cin >> hint[i].first >> hint[i].second;
  }
  sort(all(hint));
  if (hint.back().first != b) {
    hint.eb(b, n);
    q += 1;
  }
  Dinic dinic(q + b + 1 + 5 + 1);
  int source = 0;
  int prev = 0;
  int l = 0;
  for (int i = 0; i < q; i++) {
    int cap = hint[i].second - prev;
    int r = hint[i].first;
    if (cap < 0 or cap > r - l) {
      cout << "unfair\n";
      return (0);
    }
    if (cap != 0) {
      dinic.AddEdge(source, i + 1, cap);
      for (int j = l + 1; j <= r; j++) {
        dinic.AddEdge(i + 1, q + j, 1);
      }
    }
    l = r;
    prev = hint[i].second;
  }
  for (int i = 1; i <= b; i++) {
    dinic.AddEdge(q + i, q + b + 1 + (i % 5), 1);
  }
  int target = q + b + 1 + 5;
  for (int i = 0; i < 5; i++) {
    dinic.AddEdge(q + b + 1 + i, target, n / 5);
  }
  if (dinic.GetMaxFlow(source, target) == n) cout << "fair\n";
  else cout << "unfair\n";
  return (0);
}
