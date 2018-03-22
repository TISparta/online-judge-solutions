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

const int SIZE = 110;
int tc, n;
float x[SIZE], y[SIZE];
vector < pair <float, ii > > EdgeList;

float Kruskal(){
   EdgeList.clear();
   for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
         EdgeList.push_back( make_pair( hypot(x[i] - x[j], y[i] - y[j]), ii(i , j) ) ) ;
   sort(EdgeList.begin(), EdgeList.end());
   UnionFind UF(n);
   float min_cost = 0, setSize = 1;
   for(int it = 0; it < EdgeList.size(); it++){
      pair <float, ii > front = EdgeList[it];
      if( not UF.isSameSet(front.second.first, front.second.second) )
         min_cost += front.first, setSize++;
         UF.unionSet(front.second.first, front.second.second);
      if( setSize == n ) break;
   }
   return min_cost;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      for(int it = 0; it < n; it++) scanf("%f %f", x + it, y + it);
      printf("%.2f\n", Kruskal());
      if(tc) putchar('\n');
   }
   return(0);
}
