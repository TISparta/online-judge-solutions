#include <bits/stdc++.h>

#define SIZE 12

using namespace std;

int tc,X,Y,n,x[SIZE],y[SIZE],d[SIZE][SIZE],memo[SIZE][1<<SIZE];

int tsp(int pos,int bitmask){
	if(bitmask==(1<<n)-1) return d[pos][0];
	if(~memo[pos][bitmask]) return memo[pos][bitmask];
	int ans = INT_MAX;
	for(int nxt=0;nxt<n;nxt++)
		if(nxt!=pos && (bitmask&(1<<nxt))==0)
			ans = min(ans,d[pos][nxt]+tsp(nxt,bitmask|(1<<nxt)));
	return memo[pos][bitmask] = ans;
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(memo,-1,sizeof memo);
		scanf("%d %d",&X,&Y);
		scanf("%d %d",x,y);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d %d",x+i,y+i);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				d[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
		n++;
		printf("The shortest path has length %d\n",tsp(0,1));
	}
	return(0);
}
