#include <stdio.h>

void burbuja(int v[],int n){
   int i, j, temp;
   for(i = 0;i < n; i++)
      for(j = n - 1; j > i; j--)
         if(v[i] > v[j]){
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
         }
}

int main(){
   int N, n, a[100], i;
   scanf("%d", &N);
   while(N--){
   scanf("%d", &n);
   for(i = 0;i < n; i++) scanf("%d", &a[i]);
   burbuja(a, n);
   printf("%d\n",2*(a[n-1]-a[0]));
   }
   return(0);
}
