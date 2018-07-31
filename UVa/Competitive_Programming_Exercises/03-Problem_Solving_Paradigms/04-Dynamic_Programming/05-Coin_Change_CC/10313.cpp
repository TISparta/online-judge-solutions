#include <bits/stdc++.h>

#define MAX_W 310
#define MAX_COINS 310
#define SIZE 100

using namespace std;

int k,N,L1,L2;
long long dp[MAX_COINS][MAX_W],ans;
char s[SIZE];

int main(){
	dp[0][0] = 1;
	for(int id=1;id<=305;id++)
		for(int w=0;w<=305;w++){
			dp[id][w] = dp[id-1][w];	
			if(w>=id) dp[id][w] = max(dp[id][w],dp[id-1][w]+dp[id][w-id]);
		}
	while(true){
		cin.getline(s,SIZE);
		k = sscanf(s,"%d %d %d",&N,&L1,&L2);
		if(k==-1) break;
		if(k==1) ans = dp[N][N];
		else if(k==2) ans = dp[min(L1,N)][N];
		else if(k==3 && N==0 && L1==0) ans = 1;
		else ans = dp[min(L2,N)][N]-dp[min(N+1,max(L1-1,0))][N];
		printf("%lld\n",ans);
	}
	return(0);
}
