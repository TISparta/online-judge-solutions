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

const int SIZE = 100010;

struct Edge_{
   int u, v, w;
   bool operator < (const Edge_& other){
      return ( w > other.w );
   }
}E[SIZE];

int tc, N, M, sum;

int Kruskal(){
   UnionFind UF(N + 1);
   int max_cost = 0, setSize = 1;
   sort(E, E + M);
   for(int it = 0; it < M and setSize != N; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) )
         max_cost += E[it].w, setSize++,
         UF.unionSet(E[it].u, E[it].v);
   return max_cost;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      sum = 0;
      scanf("%d %d", &N, &M);
      for(int it = 0; it < M; it++){
         scanf("%d %d %d", &E[it].u, &E[it].v, &E[it].w);
         sum += E[it].w;
      }
      printf("%d\n", sum - Kruskal());
   }
   return(0);
}
