#include <bits/stdc++.h>

using namespace std;

struct callings{
   int n1, start, end, n2;
} v[500];

int tc, t, n, c1, c2;
vector <int> x;

int rings(int call, int time){
   x.push_back(call);
   for(int i = 0; i < x.size(); i++)
      for(int j = i + 1; j < x.size(); j++)
         if(x[i] == x[j])
            return 9999;
   int p = -1;
   for(int i = 0; i < n; i++)
      if(call == v[i].n1 && v[i].start <= time && time <= v[i].end)
         p = i;
   if(p == -1)
      return call;
   rings(v[p].n2, time);
}

int main(){
   scanf("%d", &tc);
   printf("CALL FORWARDING OUTPUT\n");
   while(tc--){
      printf("SYSTEM %d\n", ++t);
      n = -1;
      while(scanf("%d", &v[++n].n1), v[n].n1){
         scanf("%d %d %d", &v[n].start, &v[n].end, &v[n].n2);
         v[n].end += v[n].start;
      }
      while(scanf("%d", &c1), c1!=9000){
         x.clear();
         scanf("%d", &c2);
         printf("AT %.4d CALL TO %.4d RINGS %.4d\n", c1, c2, rings(c2, c1));
      }  
   }
   printf("END OF OUTPUT\n");
   return(0);
}
