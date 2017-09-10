#include <bits/stdc++.h>

const long long  LIM = (int)1e6;

using namespace std;

bool prime[LIM+1];
vector<int>p;
vector<int>goldbach(LIM+1);
int n;

void goldbach_Conjeture(){
	for(int i=6;i<=LIM;i+=2)
		for(int j=0;j<90;j++)
			if(!prime[i-p[j]]){
				goldbach[i] = p[j];
				break;
			}
}

void sieve(){	
	prime[0] = prime[1] = 1;
	for(int i=4;i<=LIM;i+=2)
		prime[i] = 1;
	for(int i=3;i*i<=LIM;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<=LIM;j+=2*i)
				prime[j] = 1;
			p.push_back(i);
		}
	}
}

int main(){
	sieve();
	goldbach_Conjeture();
	while(scanf("%d",&n),n)
		printf("%d = %d + %d\n",n,goldbach[n],n-goldbach[n]);
	return(0);
}
