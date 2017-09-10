#include <bits/stdc++.h>

using namespace std;

int main(){
   for(int d = 6; d <= 200; d++)
      for(int a = 2; a < d; a++)
         for(int b = a; b < d; b++)
            for(int c = b; c < d; c++)
               if(d * d * d == a * a * a + b * b * b + c * c * c)
                  printf("Cube = %d, Triple = (%d,%d,%d)\n", d, a, b, c);
   return(0);
}
