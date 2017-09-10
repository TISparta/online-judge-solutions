#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   vector <int> path, rank;

   UnionFind(int N_){
      rank.assign(N_, 0);
      path.assign(N_, 0);
      for(int it = 0; it < N_; it++) path[it] = it;
   };

   int findSet(int idx){
      return ( path[idx] == idx ? idx : path[idx] = findSet(path[idx]) );
   }

   bool isSameSet(int idx1, int idx2){
      return ( findSet(idx1) == findSet(idx2) );
   }

   void unionSet(int idx1, int idx2){
      if( isSameSet(idx1, idx2) ) return;
      int x = findSet(idx1), y = findSet(idx2);
      if( rank[x] > rank[y] ) path[y] = x;
      else path[x] = y;
      if( rank[x] == rank[y] ) rank[y]++;
   }
};

const int SIZE = 40000, LIM = 210;

struct Edge_{
   int u, v, w;
   Edge_() {};
   Edge_(int u_, int v_, int w_):
      u(u_), v(v_), w(w_) {};
   bool operator < (const Edge_& other) const{
      return ( w < other.w );
   }
}E[SIZE];

struct Point_{
   int x, y;
}P[LIM];

int tc, n, m;
vector < int > AdjList[LIM];
bool vis[LIM];

inline int pow2(int P_){
   return P_ * P_;
}

inline int dis(int i, int j){
   return pow2(P[i].x - P[j].x) + pow2(P[i].y - P[j].y);
}

void Kruskal(){
   UnionFind UF(n);
   sort(E, E + m);
   int setSize = 1;
   for(int it = 0; it < m and setSize != n; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) ){
         AdjList[E[it].u].push_back(E[it].v);
         AdjList[E[it].v].push_back(E[it].u);
         setSize++;
         UF.unionSet(E[it].u, E[it].v);
      }
}

double dfs(int u, double w = 0){
   vis[u] = true;
   if( u == 1 ) return w;
   double ans = 0;
   for(int it = 0; it < AdjList[u].size(); it++){
      int v = AdjList[u][it];
      if( not vis[v] )
         ans = max(ans, dfs(v, max(w, sqrt(dis(u, v)) ) ) );
   }
   return ans;
}

void clear_(){
   fill(vis, vis + n, false);
   for(int it = 0; it < n; it++)
      AdjList[it].clear();
   m = 0;
}

int main(){
   while(scanf("%d", &n), n){
      for(int it = 0; it < n; it++)
         scanf("%d %d", &P[it].x, &P[it].y);
      for(int i = 0; i < n; i++)
         for(int j = i + 1; j < n; j++)
            E[m++] = Edge_(i, j, dis(i, j));
      Kruskal();
      printf("Scenario #%d\n", ++tc);
      printf("Frog Distance = %.3lf\n\n", dfs(0));
      clear_();
   }
   return(0);
}
