#include <stdio.h>

void burbuja(int v[],int n){
   int i, j, temp;
   for(i = 0; i < n; i++)
      for(j = n - 1 ; j > i; j--)
         if(v[i] > v[j]){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
         }
}

int main(){
   int n, a[3], may, men,i = 1;
   scanf("%d",&n);
   while(n--){
      scanf("%d %d %d", &a[0], &a[1], &a[2]);
      burbuja(a, 3);
      printf("Case %d: %d\n", i, a[1]);
      i++;
   }
   return(0);
}
