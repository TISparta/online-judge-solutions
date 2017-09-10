#include <bits/stdc++.h>

using namespace std;

int n, tmp1, tmp2;
bool bs, bq, bpq;

int main(){
   while(scanf("%d", &n) == 1){
      bs = bq = bpq = true;
      queue <int> q;
      stack <int> s;
      priority_queue <int> pq;
      for(int i = 0; i < n; i++){
         scanf("%d %d", &tmp1, &tmp2);
         if(tmp1 == 1){
            if(bs) s.push(tmp2);
            if(bq) q.push(tmp2);
            if(bpq) pq.push(tmp2);     
         }
         else{
            if(bs){
               if(s.empty() || s.top() != tmp2) bs = false;
               else s.pop();
            }
            if(bq){
               if(q.empty() || q.front() != tmp2) bq = false;
               else q.pop();
            }
            if(bpq){
               if(pq.empty() || pq.top() != tmp2) bpq = false;
               else pq.pop();
            }
         }
      }
      if(bs && !bq && !bpq) puts("stack");
      else if(!bs && bq && !bpq) puts("queue");
      else if(!bs && !bq && bpq) puts("priority queue");
      else if(bs + bq + bpq == 0) puts("impossible");
      else puts("not sure");
   }
   return(0);
}
