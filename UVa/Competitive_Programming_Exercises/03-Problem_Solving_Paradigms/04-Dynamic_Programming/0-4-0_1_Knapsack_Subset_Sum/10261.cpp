#include <bits/stdc++.h>

#define MAX_N 1010
#define MAX_W 10010

using namespace std;

int tc,n,ferry,v[MAX_N],dp[MAX_N][MAX_W],cumSum[MAX_N],path[MAX_N];
bool take[MAX_N][MAX_W],ok;

void fillPath(int id,int w){
	if(id==0) return;
	if(take[id][w])
		fillPath(id-1,w-v[id]), path[id] = true;
	else
		fillPath(id-1,w);
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		n = 1, ok = true;
		memset(dp,0,sizeof dp);
		memset(take,false,sizeof take);
		memset(path,false,sizeof path);
		scanf("%d",&ferry);
		ferry *= 100;
		while(scanf("%d",&v[n]),v[n]) cumSum[n] = v[n]+cumSum[n-1], n++;
		for(int i=1;i<n;i++)
			for(int w=v[i];w<=ferry;w++){
				dp[i][w] = dp[i-1][w];
				if(v[i]+dp[i-1][w-v[i]]>dp[i][w])
					dp[i][w] = v[i]+dp[i-1][w-v[i]], take[i][w] = true;
			}
		for(int i=n-1;i>0;i--){
			int sum = dp[i][ferry];
			if(sum<=ferry && cumSum[i]-sum<=ferry){
				ok = false;
				fillPath(i,ferry);
				printf("%d\n",i);
				for(int it=1;it<=i;it++)
					if(path[it]) puts("starboard");
					else puts("port");
				break;
			}
		}
		if(ok) puts("0");
		if(tc) putchar('\n');
	}
	return(0);
}
