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

int N, M, a, b, w;
vector < pair < int, ii > > EdgeList;

void Kruskal(){
   UnionFind UF(N);
   sort(EdgeList.begin(), EdgeList.end());
   int ans = 0, CC = N;
   for(int it = 0; it < M; it++){
      pair <int, ii > front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         ans = front.first, CC--;
         UF.unionSet(front.second.first, front.second.second);
   }
   if( CC != 1 ) puts("IMPOSSIBLE");
   else printf("%d\n", ans);
}

int main(){
   while(scanf("%d %d", &N, &M), N | M){
      EdgeList.clear();
      for(int it = 0; it < M; it++){
         scanf("%d %d %d", &a, &b, &w);
         EdgeList.push_back( make_pair( w, ii(a, b) ) );
      }
      Kruskal();
   }
   return(0);
}
