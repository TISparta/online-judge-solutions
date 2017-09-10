#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   int numSets;
   vector <int> path, rank, setSize;

   UnionFind(int N_): numSets(N_){
      rank.assign(N_, 0);
      path.assign(N_, 0);
      setSize.assign(N_, 1);
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
      numSets--;
      int x = findSet(idx1), y = findSet(idx2);
      if( rank[x] > rank[y] ) path[y] = x, setSize[x] += setSize[y];
      else path[x] = y, setSize[y] += setSize[x];
      if( rank[x] == rank[y] ) rank[y]++;
   }

   int sizeOfSet(int idx){
      return setSize[ findSet(idx) ];
   }
};

const int SIZE = 110, LIM = 10;
int tc, P, T, a, b;
char line[LIM];
vector <int> G[SIZE];

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d\n", &P, &T);
      while(true){
         cin.getline(line, LIM);
         if( sscanf(line, "%d %d", &a, &b) == -1) break;
         G[a].push_back(b);
      }
      UnionFind UF(P);
      for(int it = 1; it <= P; it++){
         sort(G[it].begin(), G[it].end());
         G[it].erase( unique(G[it].begin(), G[it].end()), G[it].end());
      }
      for(int i = 1; i <= P; i++){
         for(int j = i + 1; j <= P; j++)
            if( G[i] == G[j] )
               UF.unionSet(i, j);
         G[i].clear();
      }
      printf("%d\n", UF.numSets);
      if(tc) putchar('\n');
   }
   return(0);
}
