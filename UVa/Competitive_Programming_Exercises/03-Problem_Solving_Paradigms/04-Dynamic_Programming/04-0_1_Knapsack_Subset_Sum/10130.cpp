#include <bits/stdc++.h>

#define MAX_N 1010
#define MAX_W 40

using namespace std;

int tc,n,G,mv,ans,memo[MAX_N][MAX_W],V[MAX_N],W[MAX_N];

int knapsack(int id,int w){
	if(id==n || w==0) return 0;
	if(memo[id][w]!=-1) return memo[id][w];
	if(W[id]>w) return memo[id][w] = knapsack(id+1,w);
	return memo[id][w] = max(knapsack(id+1,w),V[id]+knapsack(id+1,w-W[id]));
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(memo,-1,sizeof memo);
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d %d",&V[i],&W[i]);
		ans = 0;
		scanf("%d",&G);
		while(G--){
			scanf("%d",&mv);
			ans += knapsack(0,mv);
		}
		printf("%d\n",ans);
	}
	return(0);
}
