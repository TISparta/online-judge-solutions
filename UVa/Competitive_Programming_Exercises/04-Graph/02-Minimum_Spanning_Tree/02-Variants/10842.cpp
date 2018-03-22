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

const int SIZE = 10010;

struct Edge_{
   int u, v, w;
   bool operator < (const Edge_& other) const{
      return ( w > other.w );
   }
}E[SIZE];

int tc, n, m;

int Kruskal(){
   UnionFind UF(n);
   int road, setSize = 1;
   sort(E, E + m);
   for(int it = 0; it < m and setSize != n; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) )
         road = E[it].w, setSize++, UF.unionSet(E[it].u, E[it].v);
   return road;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d", &n, &m);
      for(int it = 0; it < m; it++)
         scanf("%d %d %d", &E[it].u, &E[it].v, &E[it].w);
      printf("Case #%d: %d\n", t, Kruskal());
   }
   return(0);
}
