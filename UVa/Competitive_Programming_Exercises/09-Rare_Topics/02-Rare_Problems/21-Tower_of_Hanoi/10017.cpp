#include <bits/stdc++.h>

using namespace std;

int tc, n, m;
deque <int> Tower[5];

void printTower(int id){
   printf("%c=>", id + 'A');
   if(Tower[id].empty()){
      putchar('\n');
      return;
   }
   printf("   ");
   for(int it = 0, sz = Tower[id].size() - 1; it <= sz; it++)
      printf( it != sz ? "%d " : "%d\n", Tower[id][it]);
}

void printDisks(){
   putchar('\n');
   printTower(0);
   printTower(1);
   printTower(2);
}

void backtrack(int disks, int source, int destination, int intermediate){
   if( m == 0 ) return;
   if( disks == 1 ){
      m--;
      Tower[destination].push_back(Tower[source].back());
      Tower[source].pop_back();
      printDisks();
      return;
   }
   backtrack(disks - 1, source, intermediate, destination);
   backtrack(1, source, destination, intermediate);
   backtrack(disks - 1, intermediate, destination, source);
}

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      for(int it = 0; it < 3; it++) Tower[it].clear();
      for(int disk = n; disk >= 1; disk--)
         Tower[0].push_back(disk);
      printf("Problem #%d\n", ++tc);
      printDisks();
      backtrack(n, 0, 2, 1);
      putchar('\n');
   }
   return(0);
}
