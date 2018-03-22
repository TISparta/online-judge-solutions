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

const int SIZE = 1000010;

struct Edge_{
   int u, v, w;
   Edge_() {};
   Edge_(int u_, int v_, int w_){
      u = u_, v = v_, w = w_;
   }
   bool operator < (const Edge_& other) const{
      return ( w  < other.w );
   }
}E[SIZE];

struct Point_{
   int x, y;
}P[SIZE];


int tc, N, M;

inline int pow2(int P_){
   return P_ * P_;
}

inline int dis(int i, int j){
   return pow2(P[i].x - P[j].x) + pow2(P[i].y - P[j].y);
}

void Kruskal(){
   UnionFind UF(N);
   int setSize = 1;
   for(int it = 0; it < M; it++)
      if( not UF.isSameSet(E[it].u - 1, E[it].v - 1) )
         setSize++, UF.unionSet(E[it].u - 1, E[it].v - 1);
   if( setSize == N ){
      puts("No new highways need");
      return;
   }
   M = 0;
   for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
         E[M++] = Edge_(i, j, dis(i, j));
   sort(E, E + M);
   for(int it = 0; it < M and setSize != N; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) ){
         printf("%d %d\n", E[it].u + 1, E[it].v + 1);
         setSize++;
         UF.unionSet(E[it].u, E[it].v);
      }
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &N);
      for(int it = 0; it < N; it++)
         scanf("%d %d", &P[it].x, &P[it].y);
      scanf("%d", &M);
      for(int it = 0; it < M; it++)
         scanf("%d %d", &E[it].u, &E[it].v);
      Kruskal();
      if(tc) putchar('\n');
   }
   return(0);
}
