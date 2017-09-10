#include <stdio.h>

int main(){
   int n, min, max, temp, ind1, ind2, i;
   scanf("%d", &n);
   printf("Lumberjacks:\n");
   while(n--){
      scanf("%d",&temp);
      min = max = temp;
      ind1 = ind2 = 0;
      for(i = 0; i < 9; i++){
         scanf("%d", &temp);
         if(temp > min){
            min = temp;
            ind1++;
         }
         else if(temp < max){
            max = temp;
            ind2++;
         }
         else{
            ind1++;
            ind2++;
         }
      }
      if(ind1 == 9 || ind2 == 9) printf("Ordered\n");
      else printf("Unordered\n");
   }
   return(0);
}
