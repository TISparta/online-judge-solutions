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

const int SIZE = 500010;

struct Edge_{
   int u, v;
   long long w;
   Edge_() {};
   Edge_(int u_, int v_, long long w_):
      u(u_), v(v_), w(w_) {};
   bool operator < (const Edge_& other){
      return ( w < other.w );
   }
}E[SIZE];

struct Point_{
   int x, y;
   Point_() {};
   Point_(int x_, int y_): x(x_), y(y_) {};
}P[SIZE];

int tc, N, M, CC, a, b;

inline long long pow2(long long P_){
   return P_ * P_;
}

inline long long dis(int i, int j){
   return pow2(P[i].x - P[j].x) + pow2(P[i].y - P[j].y);
}

int Kruskal(){
   UnionFind UF(N);
   double ans = 0;
   int setSize = N;
   for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
         E[M++] = Edge_(i, j, dis(i, j));
   sort(E, E + M);
   for(int it = 0; it < M and setSize != CC; it++)
      if( not UF.isSameSet(E[it].u, E[it].v) )
         ans = sqrt(E[it].w), setSize--,
         UF.unionSet(E[it].u, E[it].v);
   return ceil(ans);
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      N = M = 0;
      scanf("%d", &CC);
      while(scanf("%d", &a), ~a){
         scanf("%d", &b);
         P[N++] = Point_(a, b);
      }
      printf("%d\n", Kruskal());
   }
   return(0);
}
