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

const int SIZE = 510;
int tc, N, V[SIZE];
vector < pair <int, ii> > EdgeList;

int rolls(int num1, int num2){
   int moves = 0;
   for(int it = 0; it < 4; it++){
      int x = num1 % 10, y = num2 % 10;
      num1 /= 10, num2 /= 10;
      moves += min( abs(x - y), 10 - abs(x - y) );
   }
   return moves;
}

int Kruskal(){
   UnionFind UF(N);
   sort(EdgeList.begin(), EdgeList.end());
   int min_cost = INT_MAX, setSize = 1;
   for(int it = 0; it < N; it++) min_cost = min(min_cost, rolls(0, V[it]));
   for(int it = 0; it < EdgeList.size(); it++){
      pair <int, ii> front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         min_cost += front.first, setSize++,
         UF.unionSet(front.second.first, front.second.second);
      if( setSize == N ) break;
   }
   return min_cost;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      EdgeList.clear();
      scanf("%d", &N);
      for(int it = 0; it < N; it++)
         scanf("%d", V + it);
      for(int i = 0; i < N; i++)
         for(int j = i + 1; j < N; j++)
            EdgeList.push_back( make_pair( rolls(V[i], V[j]), ii(i, j) ) );
      printf("%d\n", Kruskal());
   }
   return(0);
}
