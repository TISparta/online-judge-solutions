#include <bits/stdc++.h>

int main(){
   int tc;
   scanf("%d", &tc);
   while(tc--){
      int A, B, C;
      scanf("%d %d %d",&A,&B,&C);
      int sqrtC = sqrt(C), sx, sy, sz;
      bool found = false;
      int x,y;
      for(x = -sqrtC; x <= sqrtC; x++){
         for(y = -sqrtC; y <= sqrtC; y++){
            int z = A - x - y;
            if(x == y || x == z || y == z) continue;
            if(x * y * z == B && x * x + y * y + z * z == C && found == false){
               sx = x; sy = y; sz =z;
               found = true;
               break;
            }
         }
         if(found) break;
      }
      if(found) printf("%d %d %d\n", sx, sy, sz);
      else printf("No solution.\n");
   }
   return(0);
}
