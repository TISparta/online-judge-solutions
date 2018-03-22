#include <bits/stdc++.h>

using namespace std;

struct UnionFind{
   int numSets, largestChain;
   vector <int> path, rank, setSize;

   UnionFind(int N_): numSets(N_), largestChain(1){
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
      largestChain = max(largestChain, (int)max(setSize[x], setSize[y]));
   }

   int sizeOfSet(int idx){
      return setSize[ findSet(idx) ];
   }
};

const int LIM = 35;
int C, R;
char word[LIM], s1[LIM], s2[LIM];
map < string, int > mp;

int main(){
   while(scanf("%d %d\n", &C, &R), C | R){
      UnionFind UF(C);
      for(int it = 0; it < C; it++){
         scanf("%s", word);
         mp[(string)word] = it;
      }
      for(int it = 0; it < R; it++){
         scanf("%s %s", s1, s2);
         UF.unionSet(mp[(string)s1], mp[(string)s2]);
      }
      printf("%d\n", UF.largestChain);
   }
   return(0);
}
