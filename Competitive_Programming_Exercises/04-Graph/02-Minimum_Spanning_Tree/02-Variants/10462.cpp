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

const int SIZE = 210;

struct Edge_{
   int u, v, w;
   bool operator < (const Edge_& other) const{
      return ( w < other.w );
   }
}E[SIZE];

int tc, N, M, min_cost, min_cost1, min_cost2, setSize;

void Kruskal(){
   UnionFind UF(N + 1);
   min_cost1 = 0, min_cost2 = INT_MAX, setSize = 1;
   vector <int> used;
   sort(E, E + M);
   for(int it = 0; it < M and setSize != N; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) ){
         min_cost1 += E[it].w, setSize++;
         UF.unionSet(E[it].u, E[it].v), used.push_back(it);
      }
   if( setSize != N ){
      min_cost1 = -1;
      return;
   }
   for(int i = 0; i + 1 < N; i++){
      setSize = 1;
      UnionFind UF(N + 1);
      min_cost = 0;
      for(int it = 0; it < M and setSize != N; it++)
         if( it != used[i] and not UF.isSameSet(E[it].u, E[it].v) )
            min_cost += E[it].w, setSize++, UF.unionSet(E[it].u, E[it].v);
      if( setSize == N )
         min_cost2 = min(min_cost2, min_cost);
   }
   if( min_cost2 == INT_MAX ) min_cost2 = -1;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d", &N, &M);
      for(int it = 0; it < M; it++)
         scanf("%d %d %d", &E[it].u, &E[it].v, &E[it].w);
      Kruskal();
      if( min_cost1 == - 1) printf("Case #%d : No way\n", t);
      else if( min_cost2 == -1 ) printf("Case #%d : No second way\n", t);
      else printf("Case #%d : %d\n", t, min_cost2);
   }
   return(0);
}
