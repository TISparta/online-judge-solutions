#include <bits/stdc++.h>

const long long  LIM = (int)1e7+2;

using namespace std;

bitset<LIM>prime;
vector<int>p;
int n,pib;

void sieve(){	
	int crossLimit = sqrt(LIM);
	prime[0] = prime[1] = 1;
	for(int i=4;i<=LIM;i+=2)
		prime[i] = 1;
	p.push_back(2);
	for(long long i=3;i<LIM;i+=2){
		if(!prime[i]){
			for(long long j=i*i;j<LIM;j+=2*i)
				prime[j] = 1;
			p.push_back((int)i);
		}
	}
}

int main(){
	sieve();
	while(scanf("%d",&n)==1){
		if(n<8){
			printf("Impossible.\n");
			continue;
		}
		pib = 4;
		n -= 4;
		for(int t=0;t<2;t++){
			pib += t;
			n -= t;
			for(int i=0;i<p.size();i++){
				if(n-p[i]<=0){
					break;
				}
				if(!prime[n-p[i]]){
					printf("2 %d %d %d\n",pib-2,p[i],n-p[i]);
					t = 2;
					break;
				}
			}
		}
	}
	return(0);
}
