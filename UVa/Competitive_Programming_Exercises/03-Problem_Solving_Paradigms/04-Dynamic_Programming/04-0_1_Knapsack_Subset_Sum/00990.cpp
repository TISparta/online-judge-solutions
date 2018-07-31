#include <bits/stdc++.h>

#define MAX_N 40
#define MAX_T 1010

using namespace std;

int tc,T,w,n,depth[MAX_N],gold[MAX_N],W[MAX_N],dp[MAX_N][MAX_T];
bool path[MAX_N][MAX_T];

void print_path(int i,int t,int ct){
	if(i==0){
		printf("%d\n",ct);		
		return;
	}
	if(path[i][t]){
		print_path(i-1,t-W[i],ct+1);
		printf("%d %d\n",depth[i],gold[i]);
	}
	else{
		print_path(i-1,t,ct);
	}
}

int main(){
	while(scanf("%d %d %d",&T,&w,&n)==3){
		if(tc++) putchar('\n');
		memset(path,false,sizeof path);
		for(int i=1;i<=n;i++)
			scanf("%d %d",&depth[i],&gold[i]), W[i] = depth[i]*3*w;
		for(int i=1;i<=n;i++) dp[i][0] = 0;
		for(int t=1;t<=T;t++) dp[0][t] = 0;
		for(int i=1;i<=n;i++)
			for(int t=1;t<=T;t++){
				dp[i][t] = dp[i-1][t];
				if(t>W[i] && gold[i]+dp[i-1][t-W[i]]>dp[i-1][t])
					dp[i][t] = gold[i]+dp[i-1][t-W[i]], path[i][t] = true;
			}
		printf("%d\n",dp[n][T]);	
		print_path(n,T,0);
	}
	return(0);
}
