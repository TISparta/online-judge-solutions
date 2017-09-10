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


int tc, CC, N;

inline int pow2(int P_){
   return P_ * P_;
}

inline int dis(int i, int j){
   return pow2(P[i].x - P[j].x) + pow2(P[i].y - P[j].y);
}

double Kruskal(){
   UnionFind UF(N);
   double D, setSize = N;
   int M = 0;
   for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
         E[M++] = Edge_(i, j, dis(i, j));
   sort(E, E + M);
   for(int it = 0; it < M and setSize != CC; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) )
         D = sqrt(E[it].w), setSize--,
         UF.unionSet(E[it].u, E[it].v);
   return D;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &CC, &N);
      for(int it = 0; it < N; it++)
         scanf("%d %d", &P[it].x, &P[it].y);
      printf("%.2lf\n", Kruskal());
   }
   return(0);
}
