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

int tc, N, M, w;
vector < pair <int, ii > > EdgeList;

void Kruskal(){
   UnionFind UF(N);
   sort(EdgeList.begin(), EdgeList.end());
   int setSize = 1;
   for(int it = 0; it < EdgeList.size(); it++){
      pair <int, ii> front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         printf("%c-%c %d\n", front.second.first + 'A', front.second.second + 'A', front.first), setSize++;
         UF.unionSet(front.second.first, front.second.second);
      if( setSize == N ) return;
   }
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      EdgeList.clear();
      scanf("%d", &N);
      for(int row = 0; row < N; row++)
         for(int col = 0; col < N; col++){
            scanf("%d, ", &w);
            if( col > row and w )
               EdgeList.push_back( make_pair( w, ii(row, col) ) );
         }
      printf("Case %d:\n", t);
      Kruskal();
   }
   return(0);
}
