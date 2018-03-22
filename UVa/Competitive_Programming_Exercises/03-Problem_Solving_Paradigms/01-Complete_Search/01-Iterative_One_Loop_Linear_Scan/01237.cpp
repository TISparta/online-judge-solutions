#include <bits/stdc++.h>

using namespace std;

int c, n, m, lab, ct, tmp;
string s[10000];
vector < pair<int, int> > a(10000);

int main(){
   scanf("%d",&c);
   while(c--){
      scanf("%d", &n);
      for(int i = 0; i < n; i++)
         cin >> s[i] >> a[i].first >> a[i].second;
      scanf("%d", &m);
      for(int i = 0; i < m; i++){
         scanf("%d", &tmp);
         ct = 0;
         for(int j = 0; j < n; j++)
            if(a[j].first <= tmp && tmp <= a[j].second)
               ct++, lab = j;
         if(ct == 1)
            cout << s[lab] << endl;
         else
            cout << "UNDETERMINED" << endl;
      }
      if(c)
         putchar('\n');
   }
   return(0);
}
