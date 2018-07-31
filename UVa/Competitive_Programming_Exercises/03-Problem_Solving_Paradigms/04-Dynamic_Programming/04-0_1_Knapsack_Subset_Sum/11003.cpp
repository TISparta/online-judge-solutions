#include <bits/stdc++.h>

#define MAX_N 1010
#define MAX_LOAD 6010

using namespace std;

int n,w[MAX_N],load[MAX_N],W,ans,memo[MAX_N][MAX_LOAD];

int dp(int id,int cload){
	if(id==n || cload<0) return 0;
	if(memo[id][cload]!=-1) return memo[id][cload];
	if(w[id]>cload) return memo[id][cload] = dp(id+1,cload);
	return memo[id][cload] = max(dp(id+1,cload),1+dp(id+1,min(cload-w[id],load[id])));
}

int main(){
	while(scanf("%d",&n),n){
		W = 0;
		memset(memo,-1,sizeof memo);
		for(int i=0;i<n;i++){
			scanf("%d %d",&w[i],&load[i]);
			W = max(W,w[i]+load[i]);
		}
		ans = dp(0,W);
		printf("%d\n",ans);
	}
	return(0);
}
