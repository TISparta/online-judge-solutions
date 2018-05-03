/**
 * > Author : TISparta
 * > Date : 03-05-18
 * > Tags : Sqrt decomposition, DSU
 * > Difficulty : 6 / 10
 */

#include <bits/stdc++.h>
 
using namespace std;
 
int BLOCK_SIZE;

struct Query {
    int L, R, id;
    Query() {}
    Query(const int& _L, const int& _R, const int& _id): L(_L), R(_R), id(_id) {}
    bool operator < (const Query& other) const {
        return R < other.R;
    }
};

struct Node {
    int u, rank_u, num_sets;
    bool rolling;
    Node() {}
    Node(const int& _u, const int& _rank_u, const int& _num_sets, const bool& _rolling):
        u(_u), rank_u(_rank_u), num_sets(_num_sets), rolling(_rolling) {}
};
 
vector <Node> movement;
 
struct DSU {
    int ct;
    int num_sets;
    bool rolling;
    vector <int> rank;
    DSU() {}
    void init(const int& V) {
        ct = 0;
        num_sets = V;
        rolling = false;
        rank.resize(V, 0);
        for (int i = 0; i < rank.size(); i++) rank[i] = i;
    }
    int findSet(int u) {
        if (rank[u] == u) return u;
        int rank_u = findSet(rank[u]);
        if (ct >= movement.size()) movement.emplace_back(Node());
        movement[ct++] = Node(u, rank[u], num_sets, rolling);
        return rank[u] = rank_u;
    }
    void merge(int u, int v) {
        int x = findSet(u);
        int y = findSet(v);
        if (x == y) return;
        if (ct >= movement.size()) movement.emplace_back(Node());
        if (x > y) swap(x, y);
        movement[ct++] = Node(x, rank[x], num_sets, rolling);
        rank[x] = y;
        num_sets--;
    }
    int getNumberCC() const {
        return num_sets;
    }
    void startRollback() {
        rolling = true;
    }
    void finishRollback() {
        ct--;
        while (ct >= 0 and movement[ct].rolling) {
            rank[movement[ct].u] = movement[ct].rank_u;
            num_sets = movement[ct].num_sets;
            ct--;
        }
        ct++;
        rolling = false;
    }
};
 
struct Graph {
    int V, E;
    vector <pair <int, int>> EdgeList;
    Graph() {};
    ~Graph() {};
    void build(const int& _V, const int& _E) {
        V = _V, E = _E;
        EdgeList.resize(E, pair <int, int> ());
    }
    void readGraph() {
        int u, v;
        for (int i = 0; i < E; i++) {
            scanf("%d %d", &u, &v);
            EdgeList[i] =  {--u, --v};
        }
    }
};
 
int T, V, E, Q;
Graph* G;
 
namespace Solver {
    vector <vector <Query>> chunks;
    vector <int> answer;
    DSU dsu;
    inline void init() {
        BLOCK_SIZE = sqrt(E);
        answer.resize(Q, 0);
    }
    void readQueries() {
        int L, R;
        for (int i = 0; i <= E / BLOCK_SIZE; i++) chunks.emplace_back(vector <Query> ());
        for (int i = 0, id = 0; i < Q; i++) {
            scanf("%d %d", &L, &R);
            L--, R--;
            chunks[L / BLOCK_SIZE].emplace_back(Query(L, R, i));
        }
        for (vector <Query>& chunk : chunks) sort(begin(chunk), end(chunk));
    }
    void processHeavyQuery(const int& id, const int& pos, const int R, int& P) {
        int u, v;
        while (P <= chunks[id][pos].R) {
            u = G -> EdgeList[P].first;
            v = G -> EdgeList[P].second;
            dsu.merge(u, v);
            P++;
        }
        dsu.startRollback();
        for (int i = chunks[id][pos].L; i < R; i++) {
            u = G -> EdgeList[i].first;
            v = G -> EdgeList[i].second;
            dsu.merge(u, v);
        }
        answer[chunks[id][pos].id] = dsu.getNumberCC();
        dsu.finishRollback();
    }
    void processLightQuery(const int& id, const int& pos) {
        int u, v;
        dsu.startRollback();
        for (int i = chunks[id][pos].L; i <= chunks[id][pos].R; i++) {
            u = G -> EdgeList[i].first;
            v = G -> EdgeList[i].second;
            dsu.merge(u, v);
        }
        answer[chunks[id][pos].id] = dsu.getNumberCC();
        dsu.finishRollback();
    }
    bool isLightQuery(const int& id, const int& pos, const int& P) {
        return chunks[id][pos].R < P;
    }
    void getAnswers() {
        for (int i = 0; i < chunks.size(); i++) {
            dsu.init(V);
            int P = (i + 1) * BLOCK_SIZE, R = min(P, E);
            int j = 0;
            int sz = chunks[i].size();
            while (j < sz and isLightQuery(i, j, P)) processLightQuery(i, j++);
            while (j < sz) processHeavyQuery(i, j++, R, P);
        }
    }
    void printAnswers() {
        for (int i = 0; i < Q; i++) printf("%d\n", answer[i]);
    }
    inline void clear() {
        chunks.clear();
        answer.clear();
    }
}
 
int main() {
    G = new Graph();
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &V, &E, &Q);
        G -> build(V, E);
        G -> readGraph();
        Solver::init();
        Solver::readQueries();
        Solver::getAnswers();
        Solver::printAnswers();
        Solver::clear();
    }
    delete G;
    return (0);
}
