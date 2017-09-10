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

const int SIZE = 20000, LIM = 210, LEN = 35;

typedef pair <int, int> ii;

struct Edge_{
   int u, v, w;
   Edge_() {};
   Edge_(int u_, int v_, int w_):
      u(u_), v(v_), w(w_) {};
   bool operator < (const Edge_& other) const{
      return ( w > other.w );
   }
}E[SIZE];

int tc, n, m, ct;
vector < ii > AdjList[LIM];
bool vis[LIM];
char word1[LEN], word2[LEN];
map < string, int > mp;

void Kruskal(){
   UnionFind UF(n);
   sort(E, E + m);
   int setSize = 1;
   for(int it = 0; it < m and setSize != n; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) ){
         AdjList[E[it].u].push_back( ii(E[it].v, E[it].w) );
         AdjList[E[it].v].push_back( ii(E[it].u, E[it].w) );
         setSize++;
         UF.unionSet(E[it].u, E[it].v);
      }
}

int dfs(int u, int w = INT_MAX){
   vis[u] = true;
   if( u == mp[word2] ) return w;
   int ans = INT_MAX;
   for(int it = 0; it < AdjList[u].size(); it++){
      ii v = AdjList[u][it];
      if( not vis[v.first] )
         ans = min(ans, dfs(v.first, min(w, v.second ) ) );
   }
   return ans;
}

void clear_(){
   fill(vis, vis + n, false);
   for(int it = 0; it < n; it++)
      AdjList[it].clear();
   mp.clear();
   ct = 0;
}

int main(){
   while(scanf("%d %d\n", &n, &m), n | m){
      for(int it = 0; it < m; it++){
         scanf("%s %s %d\n", word1, word2, &E[it].w);
         if( mp.find(word1) == mp.end() ) mp[word1] = ct++;
         if( mp.find(word2) == mp.end() ) mp[word2] = ct++;
         E[it].u = mp[word1], E[it].v = mp[word2];
      }
      scanf("%s %s", word1, word2);
      Kruskal();
      printf("Scenario #%d\n", ++tc);
      printf("%d tons\n\n", dfs(mp[word1]));
      clear_();
   }
   return(0);
}
