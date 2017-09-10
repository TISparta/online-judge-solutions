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

typedef pair <int, int> ii;

int tc, N, M, A, a, b, w;
vector < pair < int, ii > > EdgeList;
ii ans;

ii Kruskal(){
   UnionFind UF(N);
   sort(EdgeList.begin(), EdgeList.end());
   int CC = N, min_cost = 0;
   for(int it = 0; it < EdgeList.size(); it++){
      pair <int, ii> front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         min_cost += front.first, CC--,
         UF.unionSet(front.second.first, front.second.second);
   }
   min_cost += CC * A;
   return ii(min_cost, CC);
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      EdgeList.clear();
      scanf("%d %d %d", &N, &M, &A);
      for(int it = 0; it < M; it++){
         scanf("%d %d %d", &a, &b, &w);
         if( w < A )
         EdgeList.push_back( make_pair( w, ii(a - 1, b - 1) ) );
      }
      ans = Kruskal();
      printf("Case #%d: %d %d\n", t, ans.first, ans.second);
   }
   return(0);
}
