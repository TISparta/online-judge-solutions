// Implementation
// 2
// 25-02-2016

#include <bits/stdc++.h>

#define LIM 1000001

using namespace std;

int a[LIM];

int main(){
	int n;
	cin>>n;
	int tmp, sum = 0;
	for(int i = 1;i<=n;i++)
		cin>>tmp,
		sum+=tmp,
		a[sum] = i;
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
		for(int j=b[i];j<LIM;j++)
			if(a[j])
				cout<<a[j]<<endl,
				j = LIM;
	}
	return(0);
}
