#include <bits/stdc++.h>

using namespace std;

#define N 1000

int n, m, f, l;
string a[N];
vector < pair<int, int> > b;

int first(){
   for(int i = 0; i < m; i++)
      if(a[n - 1][i] == '@')
         return i;
}

int last(){
   for(int i = 0; i < m; i++)
      if(a[0][i] == '#')
         return i;

}

int main(){
   int t;
   cin >> t;
   while(t--){
      cin >> n >> m;
      for(int i = 0; i < n; i++)
         cin >> a[i];
      f = first();
      b.push_back( make_pair(n - 1, f) );

   for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
         if(a[i][j] == 'I' && (abs(b[0].first - i) == 0 || abs(b[0].first - i) == 1) && (abs(b[0].second - j) == 0 || abs(b[0].second - j) == 1))
            b.push_back( make_pair(i, j) ),j = m, i = n;

        for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                        if(a[i][j] == 'E' && (abs(b[1].first - i) == 0 || abs(b[1].first - i) == 1) && (abs(b[1].second - j) == 0 || abs(b[1].second - j) == 1))
                                b.push_back( make_pair(i, j) ),j = m, i = n;

        for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                        if(a[i][j] == 'H' && (abs(b[2].first - i) == 0 || abs(b[2].first - i) == 1) && (abs(b[2].second - j) == 0 || abs(b[2].second - j) == 1))
                                b.push_back( make_pair(i, j) ), j = m, i = n;

        for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                        if(a[i][j] == 'O' && (abs(b[3].first - i) == 0 || abs(b[3].first - i) == 1) && (abs(b[3].second - j) == 0 || abs(b[3].second - j) == 1))
                                b.push_back( make_pair(i, j) ), j = m, i = n;

        for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                        if(a[i][j] == 'V' && (abs(b[4].first - i) == 0 || abs(b[4].first - i) == 1) && (abs(b[4].second - j) == 0 || abs(b[4].second - j) == 1))
                                b.push_back( make_pair(i, j) ), j = m, i = n;

        for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                        if(a[i][j] == 'A' && (abs(b[5].first - i) == 0 || abs(b[5].first - i) == 1) && (abs(b[5].second - j) == 0 || abs(b[5].second - j) == 1))
                                b.push_back( make_pair(i, j) ), j = m, i = n;
   l = last();
   b.push_back( make_pair(0, l) );

   for(int i = 1; i <= 7; i++){
      if(b[i - 1].first == b[i].first && b[i - 1].second > b[i].second)
         cout << "left";
      else if(b[i - 1].first == b[i].first && b[i - 1].second < b[i].second)
         cout << "right";
      else
         cout << "forth";
      if(i != 7)
         cout << ' ';
      else
         putchar('\n');
   }
   b.clear();
   }
   return(0);
}
