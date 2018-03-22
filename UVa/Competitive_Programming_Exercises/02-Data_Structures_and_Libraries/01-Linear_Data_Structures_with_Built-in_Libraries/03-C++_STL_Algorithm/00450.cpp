#include <bits/stdc++.h>

#define SIZE 200

using namespace std;

struct Data{
   char t[SIZE], f[SIZE], l[SIZE], ha[SIZE], d[SIZE], hp[SIZE], wp[SIZE], cb[SIZE];
} aux;

int n;
char line[SIZE], Department[SIZE], *p;
vector <Data> v;

void printData(Data x){
   puts("----------------------------------------");
   printf("%s %s %s\n", x.t, x.f, x.l);
   printf("%s\n", x.ha);
   printf("Department: %s\n", x.d);
   printf("Home Phone: %s\n", x.hp);
   printf("Work Phone: %s\n", x.wp);
   printf("Campus Box: %s\n", x.cb);
}

void cp(char* x, char * y){
   int it = 0;
   for(it = 0; y[it]; it++) x[it] = y[it];
   x[it] = '\0';
}

bool cmp(Data x,Data y){
   return (strcmp(x.l, y.l)<0);
}

int main(){
   scanf("%d\n", &n);
   while(n--){
      cin.getline(Department, SIZE);
      strcpy(aux.d, Department);
      while(cin.getline(line, SIZE)){
         if(strlen(line) == 0) break;
         p = strtok(line, ",");
         cp(aux.t, p), p = strtok(NULL, ",");
         cp(aux.f, p), p = strtok(NULL, ",");
         cp(aux.l, p), p = strtok(NULL, ",");
         cp(aux.ha, p), p = strtok(NULL, ",");
         cp(aux.hp, p), p = strtok(NULL, ",");
         cp(aux.wp, p), p = strtok(NULL, ",");
         cp(aux.cb, p), p = strtok(NULL, ",");
         v.push_back(aux);
      }
   }
   sort(v.begin(), v.end(), cmp);
   for(int i = 0; i < v.size(); i++) printData(v[i]);
   return(0);
}
